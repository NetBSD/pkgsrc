package pkglint

import (
	"netbsd.org/pkglint/regex"
	"strings"
)

// This file defines the type and the access permissions of most pkgsrc
// variables.
//
// Some types are plain values, some are lists. Lists are split like in the
// shell, using "double" and 'single' quotes to enclose spaces.
//
// See vartypecheck.go for how these types are checked.
//
// The permissions depend on the name of the file where the variable is
// either assigned or used. There are several types of Makefile fragments
// in pkgsrc, and some of them have very specific tasks, like buildlink3.mk,
// builtin.mk and options.mk.
//
// TODO: There should be separate permission rules for files from the pkgsrc
//  infrastructure since the infrastructure basically provides the API, and
//  the packages use the API.
//
// Variables that are defined by packages are usually used by the
// infrastructure, and vice versa. There are also user-defined variables,
// which from the view point of a package, are the same as variables
// defined by the infrastructure.

type VarTypeRegistry struct {
	types map[string]*Vartype // varcanon => type
	cache map[string][]ACLEntry
}

func NewVarTypeRegistry() VarTypeRegistry {
	return VarTypeRegistry{make(map[string]*Vartype), make(map[string][]ACLEntry)}
}

func (reg *VarTypeRegistry) Canon(varname string) *Vartype {
	vartype := reg.types[varname]
	if vartype == nil {
		vartype = reg.types[varnameCanon(varname)]
	}
	return vartype
}

func (reg *VarTypeRegistry) IsDefinedExact(varname string) bool {
	return reg.types[varname] != nil
}

func (reg *VarTypeRegistry) IsDefinedCanon(varname string) bool {
	return reg.Canon(varname) != nil
}

func (reg *VarTypeRegistry) DefineType(varcanon string, vartype *Vartype) {
	reg.types[varcanon] = vartype
}

func (reg *VarTypeRegistry) Define(varname string, basicType *BasicType, options vartypeOptions, aclEntries []ACLEntry) {
	m, varbase, varparam := match2(varname, `^([A-Z_.][A-Z0-9_]*|@|\.newline)(|\*|\.\*)$`)
	assert(m) // invalid variable name

	// If this assertion fails, it usually means that
	// the test calls SetUpVartypes redundantly.
	// For example, it is called by SetUpPkgsrc or SetUpPackage as well.
	assertf(!reg.IsDefinedExact(varname), "Variable %q must only be defined once.", varname)

	vartype := NewVartype(basicType, options, aclEntries...)

	if varparam == "" || varparam == "*" {
		reg.types[varbase] = vartype
	}
	if varparam == "*" || varparam == ".*" {
		reg.types[varbase+".*"] = vartype
	}
}

// DefineName registers a variable type given an ACL name.
// The available ACL names are listed in Init.
func (reg *VarTypeRegistry) DefineName(varname string, basicType *BasicType, options vartypeOptions, aclName string) {
	aclEntries := reg.cache[aclName]
	assertNotNil(aclEntries)
	reg.Define(varname, basicType, options, aclEntries)
}

// acl defines the permissions of a variable by listing the permissions
// individually.
//
// A permission entry looks like this:
//  "Makefile, Makefile.*, *.mk: default, set, append, use, use-loadtime"
// Only certain filenames are allowed in the part before the colon,
// to prevent typos. To use arbitrary filenames, prefix them with
// "special:".
//
// Each variable that uses this function directly must document:
//  - which of the predefined permission sets is the closest
//  - how this individual permission set differs
//  - why the predefined permission set is not good enough
//  - which packages need this custom permission set.
//
// TODO: When prefixed with "infra:", the entry should only
//  apply to files within the pkgsrc infrastructure. Without this prefix,
//  the pattern should only apply to files outside the pkgsrc infrastructure.
func (reg *VarTypeRegistry) acl(varname string, basicType *BasicType, options vartypeOptions, aclEntries ...string) {
	parsedEntries := reg.parseACLEntries(varname, aclEntries...)
	reg.Define(varname, basicType, options, parsedEntries)
}

// acllist defines the permissions of a list variable by listing
// the permissions individually.
//
// Each variable that uses this function directly must document:
//  - which of the predefined permission sets is the closest
//  - how this individual permission set differs
//  - why the predefined permission set is not good enough
//  - which packages need this custom permission set.
func (reg *VarTypeRegistry) acllist(varname string, basicType *BasicType, options vartypeOptions, aclEntries ...string) {
	reg.acl(varname, basicType, options|List, aclEntries...)
}

// A package-settable variable may be set in all Makefiles except buildlink3.mk and builtin.mk.
func (reg *VarTypeRegistry) pkg(varname string, basicType *BasicType) {
	reg.DefineName(varname, basicType, PackageSettable, "pkg")
}

// Like pkg, but always needs a rationale.
func (reg *VarTypeRegistry) pkgrat(varname string, basicType *BasicType) {
	reg.DefineName(varname, basicType, PackageSettable|NeedsRationale, "pkg")
}

// pkgload is the same as pkg, except that the variable may be accessed at load time.
func (reg *VarTypeRegistry) pkgload(varname string, basicType *BasicType) {
	reg.DefineName(varname, basicType, PackageSettable, "pkgload")
}

// A package-defined list may be defined and appended to in all Makefiles
// except buildlink3.mk and builtin.mk. Simple assignment (instead of
// appending) is also allowed. If this leads of an unconditional
// assignment overriding a previous value, the redundancy check will
// catch it.
func (reg *VarTypeRegistry) pkglist(varname string, basicType *BasicType) {
	reg.DefineName(varname, basicType, List|PackageSettable, "pkglist")
}

// Like pkglist, but always needs a rationale.
func (reg *VarTypeRegistry) pkglistrat(varname string, basicType *BasicType) {
	reg.DefineName(varname, basicType, List|PackageSettable|NeedsRationale, "pkglist")
}

// Like pkglist, but only one value per line should be given.
// Typical example: PKG_FAIL_REASON.
func (reg *VarTypeRegistry) pkglistone(varname string, basicType *BasicType) {
	reg.DefineName(varname, basicType, List|PackageSettable|OnePerLine, "pkglist")
}

// A package-defined load-time list may be used or defined or appended to in
// all Makefiles except buildlink3.mk and builtin.mk. Simple assignment
// (instead of appending) is also allowed. If this leads to an unconditional
// assignment overriding a previous value, the redundancy check will catch it.
func (reg *VarTypeRegistry) pkgloadlist(varname string, basicType *BasicType) {
	reg.DefineName(varname, basicType, List|PackageSettable, "pkgloadlist")
}

// pkgappend declares a variable that may use the += operator,
// even though it is not a list where each item can be interpreted
// on its own.
//
// This applies to lists in which a single logical list item is
// composed of several syntactical words, such as CONF_FILES, which is
// a list of filename pairs.
//
// This also applies to COMMENT, which is not a list at all but a string
// that is sometimes composed of a common prefix and a package-specific
// suffix.
func (reg *VarTypeRegistry) pkgappend(varname string, basicType *BasicType) {
	reg.DefineName(varname, basicType, PackageSettable, "pkgappend")
}

func (reg *VarTypeRegistry) pkgappendbl3(varname string, basicType *BasicType) {
	reg.DefineName(varname, basicType, PackageSettable, "pkgappendbl3")
}

// Some package-defined variables may be modified in buildlink3.mk files.
// These variables are typically related to compiling and linking files
// from C and related languages.
func (reg *VarTypeRegistry) pkgbl3(varname string, basicType *BasicType) {
	reg.DefineName(varname, basicType, PackageSettable, "pkgbl3")
}

// Some package-defined lists may also be modified in buildlink3.mk files,
// for example platform-specific CFLAGS and LDFLAGS.
func (reg *VarTypeRegistry) pkglistbl3(varname string, basicType *BasicType) {
	reg.DefineName(varname, basicType, List|PackageSettable, "pkglistbl3")
}

// Like pkglistbl3, but always needs a rationale.
func (reg *VarTypeRegistry) pkglistbl3rat(varname string, basicType *BasicType) {
	reg.DefineName(varname, basicType, List|PackageSettable|NeedsRationale, "pkglistbl3")
}

// sys declares a user-defined or system-defined variable that must not
// be modified by packages.
//
// It also must not be used in buildlink3.mk and builtin.mk files or at
// load time since the system/user preferences may not have been loaded
// when these files are included.
//
// TODO: These timing issues should be handled separately from the permissions.
//  They can be made more precise.
func (reg *VarTypeRegistry) sys(varname string, basicType *BasicType, options ...vartypeOptions) {
	reg.DefineName(varname, basicType, reg.options(SystemProvided, options), "sys")
}

func (reg *VarTypeRegistry) sysbl3(varname string, basicType *BasicType) {
	reg.DefineName(varname, basicType, SystemProvided, "sysbl3")
}

func (reg *VarTypeRegistry) syslist(varname string, basicType *BasicType) {
	reg.DefineName(varname, basicType, List|SystemProvided, "syslist")
}

// usr declares a user-defined variable that must not be modified by packages.
func (reg *VarTypeRegistry) usr(varname string, basicType *BasicType) {
	reg.DefineName(varname, basicType, UserSettable, "usr")
}

// usr declares a user-defined list variable that must not be modified by packages.
func (reg *VarTypeRegistry) usrlist(varname string, basicType *BasicType) {
	reg.DefineName(varname, basicType, List|UserSettable, "usrlist")
}

// A few variables from mk/defaults/mk.conf may be overridden by packages.
// Therefore they need a separate definition of "user-settable".
//
// It is debatable whether packages should be allowed to override these
// variables at all since then there are two competing sources for the
// default values. Current practice is to have exactly this ambiguity,
// combined with some package Makefiles including bsd.prefs.mk and others
// omitting this necessary inclusion.
//
// TODO: parse all the below information directly from mk/defaults/mk.conf.
func (reg *VarTypeRegistry) usrpkg(varname string, basicType *BasicType) {
	reg.DefineName(varname, basicType, PackageSettable|UserSettable, "usrpkg")
}

// sysloadbl3 declares a system-provided variable that may already be used at load time.
//
// For most of these variables, bsd.prefs.mk has to be included before they can be used.
// For those that are defined earlier, see AlwaysInScope.
func (reg *VarTypeRegistry) sysloadbl3(varname string, basicType *BasicType, options ...vartypeOptions) {
	reg.DefineName(varname, basicType, reg.options(SystemProvided, options), "sysloadbl3")
}

func (reg *VarTypeRegistry) sysloadbl3list(varname string, basicType *BasicType, options ...vartypeOptions) {
	reg.DefineName(varname, basicType, reg.options(List|SystemProvided, options), "sysloadbl3")
}

// bl3list declares a list variable that is defined by buildlink3.mk and
// builtin.mk and can later be used by the package.
func (reg *VarTypeRegistry) bl3list(varname string, basicType *BasicType) {
	reg.DefineName(varname, basicType,
		List, // not PackageSettable since the package uses it more than setting it.
		"bl3list")
}

// cmdline declares a variable that is defined on the command line. There
// are only few variables of this type, such as PKG_DEBUG_LEVEL.
func (reg *VarTypeRegistry) cmdline(varname string, basicType *BasicType, options ...vartypeOptions) {
	reg.DefineName(varname, basicType, reg.options(CommandLineProvided, options), "cmdline")
}

// Only for infrastructure files; see mk/misc/show.mk
func (reg *VarTypeRegistry) infralist(varname string, basicType *BasicType) {
	reg.DefineName(varname, basicType, List, "infralist")
}

// compilerLanguages reads the available languages that are typically
// bundled in a single compiler framework, such as GCC or Clang.
func (reg *VarTypeRegistry) compilerLanguages(src *Pkgsrc) *BasicType {
	mklines := src.LoadMkExisting("mk/compiler.mk")

	languages := make(map[string]bool)
	if mklines != nil {
		for _, mkline := range mklines.mklines {

			if mkline.IsVarassign() && mkline.Varname() == "_CXX_STD_VERSIONS" {
				words := mkline.ValueFields(mkline.Value())
				for _, word := range words {
					languages[intern(word)] = true
				}
			}

			if mkline.IsDirective() && mkline.NeedsCond() && mkline.Cond() != nil {
				mkline.Cond().Walk(&MkCondCallback{
					VarUse: func(varuse *MkVarUse) {
						if varuse.varname == "USE_LANGUAGES" && len(varuse.modifiers) == 1 {
							ok, _, pattern, exact := varuse.modifiers[0].MatchMatch()
							if ok && exact {
								languages[intern(pattern)] = true
							}
						}
					}})
			}
		}
	}

	joined := keysJoined(languages)
	if trace.Tracing {
		trace.Stepf("Languages from mk/compiler.mk: %s", joined)
	}

	return enum(joined)
}

// enumFrom parses all variable definitions for the given file,
// and for all variables matching one of the varcanons, all values
// are added as allowed values.
//
// If the file is not found, the allowed values are taken from
// defval. This is only done in the pkglint tests.
func (reg *VarTypeRegistry) enumFrom(
	src *Pkgsrc, filename PkgsrcPath, defval string,
	varcanons ...string) *BasicType {

	mklines := src.LoadMkExisting(filename)
	if mklines == nil {
		return enum(defval)
	}

	values := make(map[string]bool)
	for _, mkline := range mklines.mklines {
		if !mkline.IsVarassign() {
			continue
		}

		varcanon := mkline.Varcanon()
		for _, vc := range varcanons {
			if vc != varcanon {
				continue
			}

			words := mkline.ValueFields(mkline.Value())
			for _, word := range words {
				if !contains(word, "$") {
					values[intern(word)] = true
				}
			}
		}
	}

	if len(values) > 0 {
		joined := keysJoined(values)
		if trace.Tracing {
			trace.Stepf("Enum from %s in %s with values: %s",
				strings.Join(varcanons, " "), filename, joined)
		}
		return enum(joined)
	}

	if !G.Testing {
		G.Logger.TechFatalf(
			mklines.lines.Filename,
			"Must contain at least 1 variable definition for %s.",
			joinCambridge("or", varcanons...))
	}

	if trace.Tracing {
		trace.Stepf("Enum from default value: %s", defval)
	}
	return enum(defval)
}

// enumFromDirs reads the package directories from category, takes all
// that have a single number in them (such as php72) and ranks them
// from earliest to latest.
//
// If no directories are found, the allowed values are taken
// from defval. This is only done in the pkglint tests.
func (reg *VarTypeRegistry) enumFromDirs(
	src *Pkgsrc, category PkgsrcPath, re regex.Pattern, repl string,
	defval string) *BasicType {

	versions := src.ListVersions(category, re, repl, false)
	if len(versions) == 0 {
		if !G.Testing {
			G.Logger.TechFatalf(
				src.File(category),
				"Must contain at least 1 subdirectory matching %q.", re)
		}
		return enum(defval)
	}

	return enum(strings.Join(versions, " "))
}

// enumFromFiles reads the files from the given base directory,
// filtering it through the regular expression and the replacement.
//
// If no files are found, the allowed values are taken
// from defval. This is only done in the pkglint tests.
func (reg *VarTypeRegistry) enumFromFiles(
	src *Pkgsrc, basedir PkgsrcPath, re regex.Pattern, repl string,
	defval string) *BasicType {

	var relevant []string
	for _, filename := range src.File(basedir).ReadPaths() {
		basename := filename.Base()
		if matches(basename.String(), re) {
			relevant = append(relevant, replaceAll(basename.String(), re, repl))
		}
	}
	if len(relevant) == 0 {
		if !G.Testing {
			G.Logger.TechFatalf(
				src.File(basedir),
				"Must contain at least 1 file matching %q.", re)
		}
		return enum(defval)
	}

	return enum(strings.Join(relevant, " "))
}

func (reg *VarTypeRegistry) options(base vartypeOptions, additional []vartypeOptions) vartypeOptions {
	assert(len(additional) <= 1)
	opts := base
	if len(additional) > 0 {
		opts |= additional[0]
	}
	return opts
}

func (reg *VarTypeRegistry) compile(name string, aclEntries ...string) {
	reg.cache[name] = reg.parseACLEntries(name, aclEntries...)
}

// Init initializes the long list of predefined pkgsrc variables.
// After this is done, PKGNAME, MAKE_ENV and all the other variables
// can be used in Makefiles without triggering warnings about typos.
func (reg *VarTypeRegistry) Init(src *Pkgsrc) {
	reg.compile("pkg",
		"buildlink3.mk, builtin.mk: none",
		"Makefile, Makefile.*, *.mk: default, set, use")
	reg.compile("pkgload",
		"buildlink3.mk: none",
		"builtin.mk: use, use-loadtime",
		"Makefile, Makefile.*, *.mk: default, set, use, use-loadtime")
	reg.compile("pkglist",
		"buildlink3.mk, builtin.mk: none",
		"Makefile, Makefile.*, *.mk: default, set, append, use")
	reg.compile("pkgloadlist",
		"buildlink3.mk, builtin.mk: none",
		"Makefile, Makefile.*, *.mk: default, set, append, use, use-loadtime")
	reg.compile("pkgappend",
		"buildlink3.mk, builtin.mk: none",
		"Makefile, Makefile.*, *.mk: default, set, append, use")
	reg.compile("pkgappendbl3",
		"Makefile, Makefile.*, *.mk: default, set, append, use")
	reg.compile("pkgbl3",
		"Makefile, Makefile.*, *.mk: default, set, use")
	reg.compile("pkglistbl3",
		"Makefile, Makefile.*, *.mk: default, set, append, use")

	reg.compile("sys",
		"buildlink3.mk: none",
		"*: use")
	reg.compile("sysbl3",
		"*: use")
	reg.compile("syslist",
		"buildlink3.mk: none",
		"*: use")
	reg.compile("sysloadbl3",
		"*: use, use-loadtime")

	reg.compile("usr",
		// TODO: why is builtin.mk missing here?
		"buildlink3.mk: none",
		"*: use, use-loadtime")
	reg.compile("usrlist",
		// TODO: why is builtin.mk missing here?
		"buildlink3.mk: none",
		"*: use, use-loadtime")
	reg.compile("usrpkg",
		"Makefile: default, set, use, use-loadtime",
		"buildlink3.mk, builtin.mk: none",
		"Makefile.*, *.mk: default, set, use, use-loadtime",
		"*: use, use-loadtime")

	reg.compile("bl3list",
		"buildlink3.mk, builtin.mk: append",
		"*: use")

	reg.compile("cmdline",
		"buildlink3.mk, builtin.mk: none",
		"*: use, use-loadtime")

	reg.compile("infralist",
		"*: set, append, use")

	compilers := reg.enumFrom(src,
		"mk/compiler.mk",
		"ccache ccc clang distcc f2c gcc hp icc ido mipspro mipspro-ucode pcc sunpro xlc",
		"_COMPILERS",
		"_PSEUDO_COMPILERS")

	emacsVersions := reg.enumFrom(src,
		"editors/emacs/modules.mk",
		"emacs25 emacs21 emacs21nox emacs20 xemacs215 xemacs215nox xemacs214 xemacs214nox",
		"_EMACS_VERSIONS_ALL")

	mysqlVersions := reg.enumFrom(src,
		"mk/mysql.buildlink3.mk",
		"57 56 55 51 MARIADB55",
		"MYSQL_VERSIONS_ACCEPTED")

	pgsqlVersions := reg.enumFrom(src,
		"mk/pgsql.buildlink3.mk",
		"10 96 95 94 93",
		"PGSQL_VERSIONS_ACCEPTED")

	jvms := reg.enumFrom(src,
		"mk/java-vm.mk",
		"openjdk8 oracle-jdk8 openjdk7 sun-jdk7 jdk16 jdk15 kaffe",
		"_PKG_JVMS.*")

	operatingSystems := reg.enumFromFiles(src,
		"mk/platform",
		`(.*)\.mk$`, "$1",
		"Cygwin DragonFly FreeBSD Linux NetBSD SunOS")

	// TODO: Only mark those variables as user-settable that actually influence
	//  the generated packages. For example, UPDATE_TARGET doesn't.

	// Last synced with mk/defaults/mk.conf revision 1.300 (abbf617a26f3).
	reg.usr("USE_CWRAPPERS", enum("yes no auto"))
	reg.usr("ALLOW_VULNERABLE_PACKAGES", BtYes)
	reg.usrlist("AUDIT_PACKAGES_FLAGS", BtShellWord)
	reg.usrlist("MANINSTALL", enum("maninstall catinstall"))
	reg.usr("MANZ", BtYes)
	reg.usrlist("GZIP", BtShellWord)
	reg.usr("MAKE_JOBS", BtInteger)
	reg.usr("OBJHOSTNAME", BtYes)
	reg.usr("OBJMACHINE", BtYes)
	reg.usr("SIGN_PACKAGES", enum("gpg x509"))
	reg.usr("X509_KEY", BtPathname)
	reg.usr("X509_CERTIFICATE", BtPathname)
	reg.usr("PATCH_DEBUG", BtYes)
	reg.usr("PKG_COMPRESSION", enum("gzip bzip2 xz none"))
	reg.usr("PKGSRC_LOCKTYPE", enum("none sleep once"))
	reg.usr("PKGSRC_SLEEPSECS", BtInteger)
	reg.usr("ABI", enum("32 64"))
	reg.usr("PKG_DEVELOPER", BtYesNo)
	reg.usr("USE_ABI_DEPENDS", BtYesNo)
	reg.usr("PKG_REGISTER_SHELLS", enum("YES NO"))
	reg.usrlist("PKGSRC_COMPILER", compilers)
	reg.usr("PKGSRC_KEEP_BIN_PKGS", BtYesNo)
	reg.usrlist("PKGSRC_MESSAGE_RECIPIENTS", BtMailAddress)
	reg.usr("PKGSRC_SHOW_BUILD_DEFS", BtYesNo)
	reg.usr("PKGSRC_RUN_TEST", BtYesNo)
	reg.usr("PKGSRC_MKPIE", BtYesNo)
	reg.usr("PKGSRC_MKREPRO", BtYesNo)
	reg.usr("PKGSRC_USE_CTF", BtYesNo)
	reg.usr("PKGSRC_USE_FORTIFY", enum("no weak strong"))
	reg.usr("PKGSRC_USE_RELRO", enum("no partial full"))
	reg.usr("PKGSRC_USE_SSP", enum("no yes strong all"))
	reg.usr("PKGSRC_USE_STACK_CHECK", enum("no yes"))
	reg.usr("PREFER.*", enum("pkgsrc native"))
	reg.usrlist("PREFER_PKGSRC", BtIdentifierDirect)
	reg.usrlist("PREFER_NATIVE", BtIdentifierDirect)
	reg.usr("PREFER_NATIVE_PTHREADS", BtYesNo)
	reg.usr("WRKOBJDIR", BtPathname)
	reg.usr("LOCALBASE", BtPathname)
	reg.usr("CROSSBASE", BtPathname)
	reg.usr("VARBASE", BtPathname)

	reg.sysloadbl3("X11_TYPE", enum("modular native"),
		UserSettable|DefinedIfInScope|NonemptyIfDefined)
	reg.sysloadbl3("X11BASE", BtPathname,
		UserSettable)

	reg.usr("MOTIFBASE", BtPathname)
	reg.usr("PKGINFODIR", BtPathname)
	reg.usr("PKGMANDIR", BtPrefixPathname)
	reg.usr("PKGGNUDIR", BtPathname)
	reg.usr("BSDSRCDIR", BtPathname)
	reg.usr("BSDXSRCDIR", BtPathname)
	reg.usr("DISTDIR", BtPathname)
	reg.usr("DIST_PATH", BtPathlist)
	reg.usr("DEFAULT_VIEW", BtUnknown) // XXX: deprecate? pkgviews has been removed
	reg.usr("FETCH_CMD", BtShellCommand)
	reg.usr("FIX_SYSTEM_HEADERS", BtYes)
	reg.usr("LIBTOOLIZE_PLIST", BtYesNo)
	reg.usr("PKG_RESUME_TRANSFERS", BtYesNo)
	reg.usr("PKG_SYSCONFBASE", BtPathname)
	reg.usr("INIT_SYSTEM", enum("rc.d smf"))
	reg.usr("RCD_SCRIPTS_DIR", BtPathname)
	reg.usr("PACKAGES", BtPathname)
	reg.usr("PASSIVE_FETCH", BtYes)
	reg.usr("PATCH_FUZZ_FACTOR", enum("none -F0 -F1 -F2 -F3"))
	reg.usrlist("ACCEPTABLE_LICENSES", BtIdentifierIndirect)
	reg.usr("SPECIFIC_PKGS", BtYes)
	reg.usrlist("SITE_SPECIFIC_PKGS", BtPkgpath)
	reg.usrlist("HOST_SPECIFIC_PKGS", BtPkgpath)
	reg.usrlist("GROUP_SPECIFIC_PKGS", BtPkgpath)
	reg.usrlist("USER_SPECIFIC_PKGS", BtPkgpath)
	reg.usr("FAILOVER_FETCH", BtYes)
	reg.usrlist("MASTER_SORT", BtUnknown)
	reg.usrlist("MASTER_SORT_REGEX", BtUnknown)
	reg.usr("MASTER_SORT_RANDOM", BtYes)
	reg.usr("PKG_FC", BtShellCommand)
	reg.usrlist("IMAKEOPTS", BtShellWord)
	reg.usr("PRE_ROOT_CMD", BtShellCommand)
	reg.usr("SU_CMD", BtShellCommand)
	reg.usr("SU_CMD_PATH_APPEND", BtPathlist)
	reg.usr("FATAL_OBJECT_FMT_SKEW", BtYesNo)
	reg.usr("WARN_NO_OBJECT_FMT", BtYesNo)
	reg.usr("SMART_MESSAGES", BtYes)
	reg.usrlist("BINPKG_SITES", BtURL)
	reg.usrlist("BIN_INSTALL_FLAGS", BtShellWord)
	reg.usr("LOCALPATCHES", BtPathname)

	reg.usr("ACROREAD_FONTPATH", BtPathlist)
	reg.usr("AMANDA_USER", BtUserGroupName)
	reg.usr("AMANDA_TMP", BtPathname)
	reg.usr("AMANDA_VAR", BtPathname)
	reg.usr("APACHE_USER", BtUserGroupName)
	reg.usr("APACHE_GROUP", BtUserGroupName)
	reg.usrlist("APACHE_SUEXEC_CONFIGURE_ARGS", BtShellWord)
	reg.usrlist("APACHE_SUEXEC_DOCROOT", BtPathname)
	reg.usr("ARLA_CACHE", BtPathname)
	reg.usr("BIND_DIR", BtPathname)
	reg.usr("BIND_GROUP", BtUserGroupName)
	reg.usr("BIND_USER", BtUserGroupName)
	reg.usr("CACTI_GROUP", BtUserGroupName)
	reg.usr("CACTI_USER", BtUserGroupName)
	reg.usr("CANNA_GROUP", BtUserGroupName)
	reg.usr("CANNA_USER", BtUserGroupName)
	reg.usr("CDRECORD_CONF", BtPathname)
	reg.usr("CLAMAV_GROUP", BtUserGroupName)
	reg.usr("CLAMAV_USER", BtUserGroupName)
	reg.usr("CLAMAV_DBDIR", BtPathname)
	reg.usr("CONSERVER_DEFAULTHOST", BtIdentifierIndirect)
	reg.usr("CONSERVER_DEFAULTPORT", BtInteger)
	reg.usr("CUPS_GROUP", BtUserGroupName)
	reg.usr("CUPS_USER", BtUserGroupName)
	reg.usrlist("CUPS_SYSTEM_GROUPS", BtUserGroupName)
	reg.usr("CYRUS_IDLE", enum("poll idled no"))
	reg.usr("CYRUS_GROUP", BtUserGroupName)
	reg.usr("CYRUS_USER", BtUserGroupName)
	reg.usr("DAEMONTOOLS_LOG_USER", BtUserGroupName)
	reg.usr("DAEMONTOOLS_GROUP", BtUserGroupName)
	reg.usr("DBUS_GROUP", BtUserGroupName)
	reg.usr("DBUS_USER", BtUserGroupName)
	reg.usr("DEFANG_GROUP", BtUserGroupName)
	reg.usr("DEFANG_USER", BtUserGroupName)
	reg.usr("DEFANG_SPOOLDIR", BtPathname)
	reg.usr("DEFAULT_IRC_SERVER", BtIdentifierIndirect)
	reg.usr("DEFAULT_SERIAL_DEVICE", BtPathname)
	reg.usr("DIALER_GROUP", BtUserGroupName)
	reg.usr("DJBDNS_AXFR_USER", BtUserGroupName)
	reg.usr("DJBDNS_CACHE_USER", BtUserGroupName)
	reg.usr("DJBDNS_LOG_USER", BtUserGroupName)
	reg.usr("DJBDNS_RBL_USER", BtUserGroupName)
	reg.usr("DJBDNS_TINY_USER", BtUserGroupName)
	reg.usr("DJBDNS_DJBDNS_GROUP", BtUserGroupName)
	reg.usr("DT_LAYOUT", enum("US FI FR GER DV"))
	reg.usrlist("ELK_GUI", enum("none xaw motif"))
	reg.usr("EMACS_TYPE", emacsVersions)
	reg.usr("EXIM_GROUP", BtUserGroupName)
	reg.usr("EXIM_USER", BtUserGroupName)
	reg.usrpkg("EXTRACT_USING", enum("bsdtar gtar nbtar pax"))
	reg.usrlist("FETCH_BEFORE_ARGS", BtShellWord)
	reg.usrlist("FETCH_AFTER_ARGS", BtShellWord)
	reg.usrlist("FETCH_RESUME_ARGS", BtShellWord)
	reg.usrlist("FETCH_OUTPUT_ARGS", BtShellWord)
	reg.usrpkg("FETCH_USING", enum("auto curl custom fetch ftp manual wget"))
	reg.usr("FLUXBOX_USE_XINERAMA", enum("YES NO"))
	reg.usr("FLUXBOX_USE_KDE", enum("YES NO"))
	reg.usr("FLUXBOX_USE_GNOME", enum("YES NO"))
	reg.usr("FLUXBOX_USE_XFT", enum("YES NO"))
	reg.usr("FOX_USE_XUNICODE", enum("YES NO"))
	reg.usr("FREEWNN_USER", BtUserGroupName)
	reg.usr("FREEWNN_GROUP", BtUserGroupName)
	reg.usr("GAMES_USER", BtUserGroupName)
	reg.usr("GAMES_GROUP", BtUserGroupName)
	reg.usr("GAMEMODE", BtFileMode)
	reg.usr("GAMEDIRMODE", BtFileMode)
	reg.usr("GAMEDATAMODE", BtFileMode)
	reg.usr("GAMEGRP", BtUserGroupName)
	reg.usr("GAMEOWN", BtUserGroupName)
	reg.usr("GRUB_NETWORK_CARDS", BtIdentifierIndirect)
	reg.usr("GRUB_PRESET_COMMAND", enum("bootp dhcp rarp"))
	reg.usrlist("GRUB_SCAN_ARGS", BtShellWord)
	reg.usr("HASKELL_COMPILER", enum("ghc"))
	reg.usr("HOWL_GROUP", BtUserGroupName)
	reg.usr("HOWL_USER", BtUserGroupName)
	reg.usr("ICECAST_CHROOTDIR", BtPathname)
	reg.usr("ICECAST_CHUNKLEN", BtInteger)
	reg.usr("ICECAST_SOURCE_BUFFSIZE", BtInteger)
	reg.usr("IMAP_UW_CCLIENT_MBOX_FMT",
		enum("mbox mbx mh mmdf mtx mx news phile tenex unix"))
	reg.usr("IMAP_UW_MAILSPOOLHOME", BtFilename)
	reg.usr("IMDICTDIR", BtPathname)
	reg.usr("INN_DATA_DIR", BtPathname)
	reg.usr("INN_USER", BtUserGroupName)
	reg.usr("INN_GROUP", BtUserGroupName)
	reg.usr("IRCD_HYBRID_NICLEN", BtInteger)
	reg.usr("IRCD_HYBRID_TOPICLEN", BtInteger)
	reg.usr("IRCD_HYBRID_SYSLOG_EVENTS", BtUnknown)
	reg.usr("IRCD_HYBRID_SYSLOG_FACILITY", BtIdentifierIndirect)
	reg.usr("IRCD_HYBRID_MAXCONN", BtInteger)
	reg.usr("IRCD_HYBRID_IRC_USER", BtUserGroupName)
	reg.usr("IRCD_HYBRID_IRC_GROUP", BtUserGroupName)
	reg.usr("IRRD_USE_PGP", enum("5 2"))
	reg.usr("JABBERD_USER", BtUserGroupName)
	reg.usr("JABBERD_GROUP", BtUserGroupName)
	reg.usr("JABBERD_LOGDIR", BtPathname)
	reg.usr("JABBERD_SPOOLDIR", BtPathname)
	reg.usr("JABBERD_PIDDIR", BtPathname)
	reg.usr("JAKARTA_HOME", BtPathname)
	reg.usr("KERBEROS", BtYes)
	reg.usr("KERMIT_SUID_UUCP", BtYes)
	reg.usr("KJS_USE_PCRE", BtYes)
	reg.usr("KNEWS_DOMAIN_FILE", BtPathname)
	reg.usr("KNEWS_DOMAIN_NAME", BtIdentifierIndirect)
	reg.usr("LIBDVDCSS_HOMEPAGE", BtHomepage)
	reg.usrlist("LIBDVDCSS_MASTER_SITES", BtFetchURL)
	reg.usr("LIBUSB_TYPE", enum("compat native"))
	reg.usr("LATEX2HTML_ICONPATH", BtURL)
	reg.usr("LEAFNODE_DATA_DIR", BtPathname)
	reg.usr("LEAFNODE_USER", BtUserGroupName)
	reg.usr("LEAFNODE_GROUP", BtUserGroupName)
	reg.usrlist("LINUX_LOCALES", BtIdentifierIndirect)
	reg.usr("MAILAGENT_DOMAIN", BtIdentifierIndirect)
	reg.usr("MAILAGENT_EMAIL", BtMailAddress)
	reg.usr("MAILAGENT_FQDN", BtIdentifierIndirect)
	reg.usr("MAILAGENT_ORGANIZATION", BtUnknown)
	reg.usr("MAJORDOMO_HOMEDIR", BtPathname)
	reg.usrlist("MAKEINFO_ARGS", BtShellWord)
	reg.usr("MECAB_CHARSET", BtIdentifierIndirect)
	reg.usr("MEDIATOMB_GROUP", BtUserGroupName)
	reg.usr("MEDIATOMB_USER", BtUserGroupName)
	reg.usr("MIREDO_USER", BtUserGroupName)
	reg.usr("MIREDO_GROUP", BtUserGroupName)
	reg.usr("MLDONKEY_GROUP", BtUserGroupName)
	reg.usr("MLDONKEY_HOME", BtPathname)
	reg.usr("MLDONKEY_USER", BtUserGroupName)
	reg.usr("MONOTONE_GROUP", BtUserGroupName)
	reg.usr("MONOTONE_USER", BtUserGroupName)
	reg.usr("MOTIF_TYPE", enum("motif openmotif lesstif dt"))
	reg.usr("MOTIF_TYPE_DEFAULT", enum("motif openmotif lesstif dt"))
	reg.usr("MTOOLS_ENABLE_FLOPPYD", BtYesNo)
	reg.usr("MYSQL_USER", BtUserGroupName)
	reg.usr("MYSQL_GROUP", BtUserGroupName)
	reg.usr("MYSQL_DATADIR", BtPathname)
	reg.usr("MYSQL_CHARSET", BtIdentifierIndirect)
	reg.usrlist("MYSQL_EXTRA_CHARSET", BtIdentifierIndirect)
	reg.usr("NAGIOS_GROUP", BtUserGroupName)
	reg.usr("NAGIOS_USER", BtUserGroupName)
	reg.usr("NAGIOSCMD_GROUP", BtUserGroupName)
	reg.usr("NAGIOSDIR", BtPathname)
	reg.usr("NBPAX_PROGRAM_PREFIX", BtUnknown)
	reg.usr("NMH_EDITOR", BtIdentifierIndirect)
	reg.usr("NMH_MTA", enum("smtp sendmail"))
	reg.usr("NMH_PAGER", BtIdentifierIndirect)
	reg.usr("NS_PREFERRED", enum("communicator navigator mozilla"))
	reg.usr("NULLMAILER_USER", BtUserGroupName)
	reg.usr("NULLMAILER_GROUP", BtUserGroupName)
	reg.usr("OPENSSH_CHROOT", BtPathname)
	reg.usr("OPENSSH_USER", BtUserGroupName)
	reg.usr("OPENSSH_GROUP", BtUserGroupName)
	reg.usr("P4USER", BtUserGroupName)
	reg.usr("P4GROUP", BtUserGroupName)
	reg.usr("P4ROOT", BtPathname)
	reg.usr("P4PORT", BtInteger)
	reg.usr("PALMOS_DEFAULT_SDK", enum("1 2 3.1 3.5"))
	reg.usr("PAPERSIZE", enum("A4 Letter"))
	reg.usr("PGGROUP", BtUserGroupName)
	reg.usr("PGUSER", BtUserGroupName)
	reg.usr("PGHOME", BtPathname)
	reg.usr("PILRC_USE_GTK", BtYesNo)
	reg.usr("PKG_JVM_DEFAULT", jvms)
	reg.usr("POPTOP_USE_MPPE", BtYes)
	reg.usr("PROCMAIL_MAILSPOOLHOME", BtFilename)
	// Comma-separated list of string or integer literals.
	reg.usr("PROCMAIL_TRUSTED_IDS", BtUnknown)
	reg.usr("PVM_SSH", BtPathname)
	reg.usr("QMAILDIR", BtPathname)
	reg.usr("QMAIL_ALIAS_USER", BtUserGroupName)
	reg.usr("QMAIL_DAEMON_USER", BtUserGroupName)
	reg.usr("QMAIL_LOG_USER", BtUserGroupName)
	reg.usr("QMAIL_ROOT_USER", BtUserGroupName)
	reg.usr("QMAIL_PASSWD_USER", BtUserGroupName)
	reg.usr("QMAIL_QUEUE_USER", BtUserGroupName)
	reg.usr("QMAIL_REMOTE_USER", BtUserGroupName)
	reg.usr("QMAIL_SEND_USER", BtUserGroupName)
	reg.usr("QMAIL_QMAIL_GROUP", BtUserGroupName)
	reg.usr("QMAIL_NOFILES_GROUP", BtUserGroupName)
	reg.usr("QMAIL_QFILTER_TMPDIR", BtPathname)
	reg.usr("QMAIL_QUEUE_DIR", BtPathname)
	reg.usr("QMAIL_QUEUE_EXTRA", BtMailAddress)
	reg.usr("QPOPPER_FAC", BtIdentifierIndirect)
	reg.usr("QPOPPER_USER", BtUserGroupName)
	reg.usr("QPOPPER_SPOOL_DIR", BtPathname)
	reg.usr("RASMOL_DEPTH", enum("8 16 32"))
	reg.usr("RELAY_CTRL_DIR", BtPathname)
	reg.usr("RPM_DB_PREFIX", BtPathname)
	reg.usr("RSSH_SCP_PATH", BtPathname)
	reg.usr("RSSH_SFTP_SERVER_PATH", BtPathname)
	reg.usr("RSSH_CVS_PATH", BtPathname)
	reg.usr("RSSH_RDIST_PATH", BtPathname)
	reg.usr("RSSH_RSYNC_PATH", BtPathname)
	reg.usrlist("SAWFISH_THEMES", BtFilename)
	reg.usr("SCREWS_GROUP", BtUserGroupName)
	reg.usr("SCREWS_USER", BtUserGroupName)
	reg.usr("SDIST_PAWD", enum("pawd pwd"))
	reg.usrlist("SERIAL_DEVICES", BtPathname)
	reg.usr("SILC_CLIENT_WITH_PERL", BtYesNo)
	reg.usr("SNIPROXY_USER", BtUserGroupName)
	reg.usr("SNIPROXY_GROUP", BtUserGroupName)
	reg.usr("SSH_SUID", BtYesNo)
	reg.usr("SSYNC_PAWD", enum("pawd pwd"))
	reg.usr("SUSE_PREFER", reg.enumFromDirs(src,
		"emulators", `^suse(\d\d)(\d)_base$`, "$1.$2", "13.1 12.1 10.0"))
	reg.usr("TEXMFSITE", BtPathname)
	reg.usr("THTTPD_LOG_FACILITY", BtIdentifierIndirect)
	reg.usr("UCSPI_SSL_USER", BtUserGroupName)
	reg.usr("UCSPI_SSL_GROUP", BtUserGroupName)
	reg.usr("UNPRIVILEGED", BtYesNo)
	reg.usr("USE_CROSS_COMPILE", BtYesNo)
	reg.usr("USERPPP_GROUP", BtUserGroupName)
	reg.usr("UUCP_GROUP", BtUserGroupName)
	reg.usr("UUCP_USER", BtUserGroupName)
	reg.usrlist("VIM_EXTRA_OPTS", BtShellWord)
	reg.usr("WCALC_HTMLDIR", BtPathname)
	reg.usr("WCALC_HTMLPATH", BtPathname) // URL path
	reg.usr("WCALC_CGIDIR", BtPrefixPathname)
	reg.usr("WCALC_CGIPATH", BtPathname) // URL path
	reg.usrlist("WDM_MANAGERS", BtIdentifierIndirect)
	reg.usr("X10_PORT", BtPathname)
	reg.usrpkg("XAW_TYPE", enum("standard 3d xpm neXtaw"))
	reg.usr("XLOCK_DEFAULT_MODE", BtIdentifierIndirect)
	reg.usr("ZSH_STATIC", BtYes)

	// some other variables, sorted alphabetically

	// TODO: Instead of grouping them alphabetically, group them
	//  by topic, like clean, fetch, patch, configure, build, install,
	//  subst, buildlink3, checks. This will make them easier to
	//  analyze and align the permissions.

	// TODO: Determine AlwaysInScope automatically based on sys.mk.
	// TODO: Determine DefinedIfInScope automatically.
	// TODO: Determine NonemptyIfDefined automatically.

	reg.sysloadbl3(".newline", BtMessage, AlwaysInScope|DefinedIfInScope|NonemptyIfDefined)
	reg.sysloadbl3list(".ALLSRC", BtPathname, AlwaysInScope)
	reg.sysloadbl3(".CURDIR", BtPathname, AlwaysInScope|DefinedIfInScope|NonemptyIfDefined)
	reg.sysloadbl3(".IMPSRC", BtPathname)
	reg.sys(".TARGET", BtPathname)
	reg.sys("@", BtPathname)
	reg.pkglistbl3("ALL_ENV", BtShellWord)
	reg.pkg("ALTERNATIVES_FILE", BtFilename)
	reg.pkglist("ALTERNATIVES_SRC", BtPathname)
	reg.pkg("APACHE_MODULE", BtYes)
	reg.sys("AR", BtShellCommand, AlwaysInScope|DefinedIfInScope|NonemptyIfDefined)
	reg.sys("AS", BtShellCommand, AlwaysInScope|DefinedIfInScope|NonemptyIfDefined)
	reg.pkglist("AUTOCONF_REQD", BtVersion)
	reg.pkglist("AUTOMAKE_OVERRIDE", BtYesNo)
	reg.pkglist("AUTOMAKE_REQD", BtVersion)
	reg.pkg("AUTO_MKDIRS", BtYesNo)
	reg.usr("BATCH", BtYes)
	reg.usr("BDB185_DEFAULT", BtUnknown)
	reg.sys("BDBBASE", BtPathname)
	reg.pkglist("BDB_ACCEPTED", enum("db1 db2 db3 db4 db5 db6"))
	reg.usr("BDB_DEFAULT", enum("db1 db2 db3 db4 db5 db6"))
	reg.syslist("BDB_LIBS", BtLdFlag)
	reg.sys("BDB_TYPE", enum("db1 db2 db3 db4 db5 db6"))
	reg.syslist("BIGENDIANPLATFORMS", BtMachinePlatformPattern)
	reg.sysloadbl3("BINGRP", BtUserGroupName, DefinedIfInScope|NonemptyIfDefined)
	reg.sysloadbl3("BINMODE", BtFileMode, DefinedIfInScope|NonemptyIfDefined)
	reg.sysloadbl3("BINOWN", BtUserGroupName, DefinedIfInScope|NonemptyIfDefined)
	reg.pkglist("BOOTSTRAP_DEPENDS", BtDependencyWithPath)
	reg.pkg("BOOTSTRAP_PKG", BtYesNo)
	reg.pkglistone("BROKEN", BtShellWord)
	reg.pkg("BROKEN_GETTEXT_DETECTION", BtYesNo)
	reg.pkglistrat("BROKEN_EXCEPT_ON_PLATFORM", BtMachinePlatformPattern)
	reg.pkglistrat("BROKEN_ON_PLATFORM", BtMachinePlatformPattern)
	reg.syslist("BSD_MAKE_ENV", BtShellWord)
	// TODO: Align the permissions of the various BUILDLINK_*.* variables with each other.
	reg.acllist("BUILDLINK_ABI_DEPENDS.*", BtDependencyPattern,
		PackageSettable,
		"buildlink3.mk, builtin.mk: append, use-loadtime",
		"*: append")
	reg.acllist("BUILDLINK_API_DEPENDS.*", BtDependencyPattern,
		PackageSettable,
		"buildlink3.mk, builtin.mk: append, use-loadtime",
		"*: append")
	reg.acl("BUILDLINK_AUTO_DIRS.*", BtYesNo,
		PackageSettable,
		"buildlink3.mk: append",
		"Makefile: set")
	reg.syslist("BUILDLINK_CFLAGS", BtCFlag)
	reg.bl3list("BUILDLINK_CFLAGS.*", BtCFlag)
	reg.acl("BUILDLINK_CONTENTS_FILTER.*", BtShellCommand,
		PackageSettable,
		"buildlink3.mk: set")
	reg.syslist("BUILDLINK_CPPFLAGS", BtCFlag)
	reg.bl3list("BUILDLINK_CPPFLAGS.*", BtCFlag)
	reg.acllist("BUILDLINK_DEPENDS", BtIdentifierDirect,
		PackageSettable,
		"buildlink3.mk: append")
	reg.acllist("BUILDLINK_DEPMETHOD.*", BtBuildlinkDepmethod,
		PackageSettable,
		"buildlink3.mk: default, append, use",
		"Makefile, Makefile.*, *.mk: default, set, append")
	reg.acl("BUILDLINK_DIR", BtPathname,
		PackageSettable,
		"*: use")
	reg.bl3list("BUILDLINK_FILES.*", BtPathPattern)
	reg.pkgbl3("BUILDLINK_FILES_CMD.*", BtShellCommand)
	reg.acllist("BUILDLINK_INCDIRS.*", BtPathname,
		PackageSettable,
		"buildlink3.mk: default, append",
		"Makefile, Makefile.*, *.mk: use")
	reg.acl("BUILDLINK_JAVA_PREFIX.*", BtPathname,
		PackageSettable,
		"buildlink3.mk: set, use")
	reg.acllist("BUILDLINK_LDADD.*", BtLdFlag,
		PackageSettable,
		"builtin.mk: default, set, append, use",
		"buildlink3.mk: append, use",
		"Makefile, Makefile.*, *.mk: use")
	reg.acllist("BUILDLINK_LDFLAGS", BtLdFlag,
		PackageSettable,
		"*: use")
	reg.bl3list("BUILDLINK_LDFLAGS.*", BtLdFlag)
	reg.acllist("BUILDLINK_LIBDIRS.*", BtPathname,
		PackageSettable,
		"buildlink3.mk, builtin.mk: append",
		"Makefile, Makefile.*, *.mk: use")
	reg.acllist("BUILDLINK_LIBS.*", BtLdFlag,
		PackageSettable,
		"buildlink3.mk: append",
		"Makefile, Makefile.*, *.mk: set, append, use")
	reg.acllist("BUILDLINK_PASSTHRU_DIRS", BtPathname,
		PackageSettable,
		"Makefile, Makefile.*, *.mk: append")
	reg.acllist("BUILDLINK_PASSTHRU_RPATHDIRS", BtPathname,
		PackageSettable,
		"Makefile, Makefile.*, *.mk: append")
	reg.acl("BUILDLINK_PKGSRCDIR.*", BtRelativePkgDir,
		PackageSettable,
		"buildlink3.mk: default, use-loadtime")
	reg.acl("BUILDLINK_PREFIX.*", BtPathname,
		PackageSettable,
		"builtin.mk: set, use",
		"Makefile, Makefile.*, *.mk: use")
	reg.acllist("BUILDLINK_RPATHDIRS.*", BtPathname,
		PackageSettable,
		"buildlink3.mk: append")
	reg.acllist("BUILDLINK_TARGETS", BtIdentifierDirect,
		PackageSettable,
		"Makefile, Makefile.*, *.mk: append")
	reg.acl("BUILDLINK_FNAME_TRANSFORM.*", BtSedCommands,
		PackageSettable,
		"Makefile, buildlink3.mk, builtin.mk, options.mk: append")
	reg.acllist("BUILDLINK_TRANSFORM", BtWrapperTransform,
		PackageSettable,
		"*: append")
	reg.acllist("BUILDLINK_TRANSFORM.*", BtWrapperTransform,
		PackageSettable,
		"*: append")
	reg.acllist("BUILDLINK_TREE", BtIdentifierDirect,
		PackageSettable,
		"buildlink3.mk: append")
	reg.acl("BUILDLINK_X11_DIR", BtPathname,
		PackageSettable,
		"*: use")
	reg.acllist("BUILD_DEFS", BtVariableName,
		PackageSettable,
		"Makefile, Makefile.*, *.mk: append")
	reg.pkglist("BUILD_DEFS_EFFECTS", BtVariableName)
	reg.pkglistbl3("BUILD_DEPENDS", BtDependencyWithPath)
	reg.pkglist("BUILD_DIRS", BtWrksrcSubdirectory)
	reg.pkglist("BUILD_ENV", BtShellWord)
	reg.sys("BUILD_MAKE_CMD", BtShellCommand)
	reg.pkglist("BUILD_MAKE_FLAGS", BtShellWord)
	reg.pkglist("BUILD_TARGET", BtIdentifierIndirect)
	reg.pkglist("BUILD_TARGET.*", BtIdentifierIndirect)
	reg.pkg("BUILD_USES_MSGFMT", BtYes)
	reg.acl("BUILTIN_PKG", BtIdentifierDirect,
		PackageSettable,
		"builtin.mk: set, use, use-loadtime",
		"Makefile, Makefile.*, *.mk: use, use-loadtime")
	reg.acl("BUILTIN_PKG.*", BtPkgname,
		PackageSettable,
		"builtin.mk: set, use, use-loadtime")
	reg.pkglistbl3("BUILTIN_FIND_FILES_VAR", BtVariableName)
	reg.pkglistbl3("BUILTIN_FIND_FILES.*", BtPathname)
	reg.acl("BUILTIN_FIND_GREP.*", BtUnknown,
		PackageSettable,
		"builtin.mk: set")
	reg.acllist("BUILTIN_FIND_HEADERS_VAR", BtVariableName,
		PackageSettable,
		"builtin.mk: set")
	reg.acllist("BUILTIN_FIND_HEADERS.*", BtPathname,
		PackageSettable,
		"builtin.mk: set")
	reg.acllist("BUILTIN_FIND_LIBS", BtPathname,
		PackageSettable,
		"builtin.mk: set")
	reg.sys("BUILTIN_X11_TYPE", BtUnknown)
	reg.sys("BUILTIN_X11_VERSION", BtUnknown)
	reg.DefineName("CATEGORIES", BtCategory, List|PackageSettable|Unique, "pkglist")
	reg.sysloadbl3("CC_VERSION", BtMessage, DefinedIfInScope|NonemptyIfDefined)
	reg.sysloadbl3("CC", BtShellCommand)
	reg.pkglistbl3("CFLAGS", BtCFlag)   // may also be changed by the user
	reg.pkglistbl3("CFLAGS.*", BtCFlag) // may also be changed by the user
	reg.acl("CHECK_BUILTIN", BtYesNo,
		PackageSettable,
		"builtin.mk: default",
		"Makefile: set")
	reg.acl("CHECK_BUILTIN.*", BtYesNo,
		PackageSettable,
		"Makefile, options.mk, buildlink3.mk: set",
		"builtin.mk: default, use-loadtime",
		"*: use-loadtime")
	reg.pkglist("CHECK_FILES_SKIP", BtBasicRegularExpression)
	reg.pkg("CHECK_FILES_SUPPORTED", BtYesNo)
	reg.usr("CHECK_HEADERS", BtYesNo)
	reg.pkglist("CHECK_HEADERS_SKIP", BtPathPattern)
	reg.usr("CHECK_INTERPRETER", BtYesNo)
	reg.pkglist("CHECK_INTERPRETER_SKIP", BtPathPattern)
	reg.usr("CHECK_PERMS", BtYesNo)
	reg.pkglist("CHECK_PERMS_SKIP", BtPathPattern)
	reg.usr("CHECK_PORTABILITY", BtYesNo)
	reg.pkglist("CHECK_PORTABILITY_SKIP", BtPathPattern)
	reg.usr("CHECK_RELRO", BtYesNo)
	reg.pkglist("CHECK_RELRO_SKIP", BtPathPattern)
	reg.pkg("CHECK_RELRO_SUPPORTED", BtYesNo)
	reg.pkg("CHECK_SHLIBS", BtYesNo)
	reg.pkglist("CHECK_SHLIBS_SKIP", BtPathPattern)
	reg.pkg("CHECK_SHLIBS_SUPPORTED", BtYesNo)
	reg.pkglist("CHECK_WRKREF_SKIP", BtPathPattern)
	reg.pkg("CMAKE_ARG_PATH", BtPathname)
	reg.pkglist("CMAKE_ARGS", BtShellWord)
	reg.pkglist("CMAKE_ARGS.*", BtShellWord)
	reg.pkglist("CMAKE_DEPENDENCIES_REWRITE", BtWrksrcPathPattern)
	reg.pkglist("CMAKE_MODULE_PATH_OVERRIDE", BtWrksrcPathPattern)
	reg.pkg("CMAKE_PKGSRC_BUILD_FLAGS", BtYesNo)
	reg.pkglist("CMAKE_PREFIX_PATH", BtPathPattern)
	reg.pkg("CMAKE_USE_GNU_INSTALL_DIRS", BtYesNo)
	reg.pkg("CMAKE_INSTALL_PREFIX", BtPathname) // The default is ${PREFIX}.
	reg.pkgappend("COMMENT", BtComment)
	reg.sys("COMPILE.*", BtShellCommand)
	reg.sys("COMPILER_RPATH_FLAG", enum("-Wl,-rpath"))
	reg.pkglist("CONFIGURE_ARGS", BtShellWord)
	reg.pkglist("CONFIGURE_ARGS.*", BtShellWord)
	reg.pkglist("CONFIGURE_DIRS", BtWrksrcSubdirectory)
	reg.pkglistbl3("CONFIGURE_ENV", BtShellWord)
	reg.pkglistbl3("CONFIGURE_ENV.*", BtShellWord)
	reg.pkg("CONFIGURE_HAS_INFODIR", BtYesNo)
	reg.pkg("CONFIGURE_HAS_LIBDIR", BtYesNo)
	reg.pkg("CONFIGURE_HAS_MANDIR", BtYesNo)
	reg.pkg("CONFIGURE_SCRIPT", BtPathname)
	reg.pkglist("CONFIG_GUESS_OVERRIDE", BtWrksrcPathPattern)
	reg.pkg("CONFIG_SHELL", BtShellCommand)
	reg.cmdline("CONFIG_SHELL_FLAGS", BtShellWord, List)
	reg.pkglist("CONFIG_SUB_OVERRIDE", BtWrksrcPathPattern)
	reg.pkglist("CONFLICTS", BtDependencyPattern)
	reg.pkgappend("CONF_FILES", BtConfFiles)
	reg.pkg("CONF_FILES_MODE", enum("0644 0640 0600 0400"))
	reg.pkglist("CONF_FILES_PERMS", BtPerms)
	reg.sys("COPY", enum("-c")) // The flag that tells ${INSTALL} to copy a file
	reg.sys("CPP", BtShellCommand)
	reg.pkglistbl3("CPPFLAGS", BtCFlag)
	reg.pkglistbl3("CPPFLAGS.*", BtCFlag)
	reg.sys("CXX", BtShellCommand)
	reg.pkglistbl3("CXXFLAGS", BtCFlag)
	reg.pkglistbl3("CXXFLAGS.*", BtCFlag)
	reg.pkglistbl3("CWRAPPERS_APPEND.*", BtShellWord)
	reg.syslist("DEFAULT_DISTFILES", BtFetchURL) // From mk/fetch/bsd.fetch-vars.mk.
	reg.pkglist("DEINSTALL_SRC", BtPathname)
	reg.pkglist("DEINSTALL_TEMPLATES", BtPathname)
	reg.sys("DELAYED_ERROR_MSG", BtShellCommand)
	reg.sys("DELAYED_WARNING_MSG", BtShellCommand)
	reg.pkglistbl3("DEPENDS", BtDependencyWithPath)
	reg.usrlist("DEPENDS_TARGET", BtIdentifierDirect)
	reg.pkglist("DESCR_SRC", BtPathname)
	reg.sys("DESTDIR", BtPathname)
	reg.pkg("DESTDIR_VARNAME", BtVariableName)
	reg.sys("DEVOSSAUDIO", BtPathname)
	reg.sys("DEVOSSSOUND", BtPathname)
	reg.pkglist("DISTFILES", BtFilename)
	reg.pkg("DISTINFO_FILE", BtRelativePkgPath)
	reg.pkg("DISTNAME", BtFilename)
	reg.pkg("DIST_SUBDIR", BtPathname)
	reg.pkglist("DJB_BUILD_ARGS", BtShellWord)
	reg.pkglist("DJB_BUILD_TARGETS", BtIdentifierIndirect)
	reg.pkgappend("DJB_CONFIG_CMDS", BtShellCommands)
	reg.pkglist("DJB_CONFIG_DIRS", BtWrksrcSubdirectory)
	reg.pkg("DJB_CONFIG_HOME", BtFilename)
	reg.pkg("DJB_CONFIG_PREFIX", BtPathname)
	reg.pkglist("DJB_INSTALL_TARGETS", BtIdentifierIndirect)
	reg.pkg("DJB_MAKE_TARGETS", BtYesNo)
	reg.pkg("DJB_RESTRICTED", BtYesNo)
	reg.pkg("DJB_SLASHPACKAGE", BtYesNo)
	reg.pkg("DLOPEN_REQUIRE_PTHREADS", BtYesNo)
	reg.pkg("DL_AUTO_VARS", BtYesNo)
	reg.acllist("DL_LIBS", BtLdFlag,
		PackageSettable,
		"*: append, use")
	reg.sysloadbl3("DOCOWN", BtUserGroupName, DefinedIfInScope|NonemptyIfDefined)
	reg.sysloadbl3("DOCGRP", BtUserGroupName, DefinedIfInScope|NonemptyIfDefined)
	reg.sysloadbl3("DOCMODE", BtFileMode, DefinedIfInScope|NonemptyIfDefined)
	reg.sys("DOWNLOADED_DISTFILE", BtPathname)
	reg.sys("DO_NADA", BtShellCommand)
	reg.pkg("DYNAMIC_SITES_CMD", BtShellCommand)
	reg.pkg("DYNAMIC_SITES_SCRIPT", BtPathname)
	reg.sysbl3("ECHO", BtShellCommand)
	reg.sysbl3("ECHO_BUILDLINK_MSG", BtShellCommand)
	reg.sysbl3("ECHO_MSG", BtShellCommand)
	reg.sysbl3("ECHO_N", BtShellCommand)
	reg.pkg("EGDIR", BtPathname) // Not defined anywhere but used in many places like this.
	reg.sys("EMACS_BIN", BtPathname)
	reg.sys("EMACS_ETCPREFIX", BtPathname)
	reg.sys("EMACS_FLAVOR", enum("emacs xemacs"))
	reg.sys("EMACS_INFOPREFIX", BtPathname)
	reg.sys("EMACS_LISPPREFIX", BtPathname)
	reg.pkglistbl3("EMACS_MODULES", BtIdentifierIndirect)
	reg.sys("EMACS_PKGNAME_PREFIX", BtIdentifierIndirect) // Or the empty string.
	reg.pkglist("EMACS_VERSIONS_ACCEPTED", emacsVersions)
	reg.sys("EMACS_VERSION_MAJOR", BtInteger)
	reg.sys("EMACS_VERSION_MINOR", BtInteger)
	reg.pkglistrat("EMACS_VERSION_REQD", emacsVersions)
	reg.sys("EMULDIR", BtPathname)
	reg.sys("EMULSUBDIR", BtPathname)
	reg.sys("OPSYS_EMULDIR", BtPathname)
	reg.sys("EMULSUBDIRSLASH", BtPathname)
	reg.sys("EMUL_ARCH", enum("arm i386 m68k none ns32k sparc vax x86_64"))
	reg.sys("EMUL_DISTRO", BtIdentifierIndirect)
	reg.sys("EMUL_IS_NATIVE", BtYes)
	reg.pkglist("EMUL_MODULES.*", BtIdentifierIndirect)
	reg.sys("EMUL_OPSYS", enum("darwin freebsd hpux irix linux osf1 solaris sunos none"))
	reg.pkg("EMUL_PKG_FMT", enum("plain rpm"))
	reg.usr("EMUL_PLATFORM", BtEmulPlatform)
	reg.pkglist("EMUL_PLATFORMS", BtEmulPlatform)
	reg.usrlist("EMUL_PREFER", BtEmulPlatform)
	reg.pkglist("EMUL_REQD", BtDependencyPattern)
	reg.usr("EMUL_TYPE.*", enum("native builtin suse suse-10.0 suse-12.1 suse-13.1"))
	reg.sys("ERROR_CAT", BtShellCommand)
	reg.sys("ERROR_MSG", BtShellCommand)
	reg.syslist("EXPORT_SYMBOLS_LDFLAGS", BtLdFlag)
	reg.sys("EXTRACT_CMD", BtShellCommand)
	reg.pkg("EXTRACT_DIR", BtPathname)
	reg.pkg("EXTRACT_DIR.*", BtPathname)
	reg.pkglist("EXTRACT_ELEMENTS", BtPathPattern) // TODO: No slashes allowed
	reg.pkglist("EXTRACT_ENV", BtShellWord)
	reg.pkglist("EXTRACT_ONLY", BtPathname)
	reg.pkglist("EXTRACT_OPTS", BtShellWord)
	reg.pkglist("EXTRACT_OPTS_BIN", BtShellWord)
	reg.pkglist("EXTRACT_OPTS_LHA", BtShellWord)
	reg.pkglist("EXTRACT_OPTS_PAX", BtShellWord)
	reg.pkglist("EXTRACT_OPTS_RAR", BtShellWord)
	reg.pkglist("EXTRACT_OPTS_TAR", BtShellWord)
	reg.pkglist("EXTRACT_OPTS_ZIP", BtShellWord)
	reg.pkglist("EXTRACT_OPTS_ZOO", BtShellWord)
	reg.pkg("EXTRACT_SUFX", BtDistSuffix)
	reg.sys("FAIL_MSG", BtShellCommand)
	reg.sys("FAMBASE", BtPathname)
	reg.pkglist("FAM_ACCEPTED", enum("fam gamin"))
	reg.usr("FAM_DEFAULT", enum("fam gamin"))
	reg.sys("FAM_TYPE", enum("fam gamin"))
	reg.pkglist("FETCH_MESSAGE", BtShellWord)
	reg.pkgload("FILESDIR", BtRelativePkgPath)
	reg.pkglist("FILES_SUBST", BtShellWord)
	reg.syslist("FILES_SUBST_SED", BtShellWord)
	reg.pkglist("FIX_RPATH", BtVariableName)
	reg.pkglistrat("FLEX_REQD", BtVersion)
	reg.pkglist("FONTS_DIRS.*", BtPathname)
	reg.syslist("GAMEDATA_PERMS", BtPerms)
	reg.syslist("GAMEDIR_PERMS", BtPerms)
	reg.pkglistbl3rat("GCC_REQD", BtGccReqd)
	reg.pkgappend("GENERATE_PLIST", BtShellCommands)
	reg.pkg("GITHUB_PROJECT", BtIdentifierIndirect)
	reg.pkg("GITHUB_TAG", BtIdentifierIndirect)
	reg.pkg("GITHUB_RELEASE", BtFilename)
	reg.pkg("GITHUB_TYPE", enum("tag release"))
	reg.pkgrat("GMAKE_REQD", BtVersion)
	// Some packages need to set GNU_ARCH.i386 to either i486 or i586.
	reg.pkg("GNU_ARCH.*", BtIdentifierDirect)
	// GNU_CONFIGURE needs to be tested in some buildlink3.mk files,
	// such as lang/vala.
	reg.acl("GNU_CONFIGURE", BtYes,
		PackageSettable,
		"buildlink3.mk: none",
		"builtin.mk: use, use-loadtime",
		"Makefile, Makefile.*, *.mk: default, set, use, use-loadtime")
	reg.pkg("GNU_CONFIGURE_INFODIR", BtPathname)
	reg.pkg("GNU_CONFIGURE_LIBDIR", BtPathname)
	reg.pkg("GNU_CONFIGURE_LIBSUBDIR", BtPathname)
	reg.pkg("GNU_CONFIGURE_MANDIR", BtPathname)
	reg.pkg("GNU_CONFIGURE_PREFIX", BtPathname)
	reg.pkg("GOPATH", BtPathname)
	reg.pkgload("HAS_CONFIGURE", BtYes)
	reg.pkglist("HEADER_TEMPLATES", BtPathname)
	reg.pkg("HOMEPAGE", BtHomepage)
	reg.pkgbl3("ICON_THEMES", BtYes)
	reg.acl("IGNORE_PKG.*", BtYes,
		PackageSettable,
		"*: set, use-loadtime")
	reg.sys("IMAKE", BtShellCommand)
	reg.pkglistbl3rat("INCOMPAT_CURSES", BtMachinePlatformPattern)
	reg.sys("INFO_DIR", BtPathname) // relative to PREFIX
	reg.pkg("INFO_FILES", BtYes)
	reg.sys("INFO_MSG", BtShellCommand)
	reg.sys("INSTALL", BtShellCommand)
	reg.pkglist("INSTALLATION_DIRS", BtPrefixPathname)
	reg.pkg("INSTALLATION_DIRS_FROM_PLIST", BtYes)
	reg.sys("INSTALL_DATA", BtShellCommand)
	reg.sys("INSTALL_DATA_DIR", BtShellCommand)
	reg.pkglist("INSTALL_DIRS", BtWrksrcSubdirectory)
	reg.pkglist("INSTALL_ENV", BtShellWord)
	reg.pkg("INSTALL_FILE", BtPathname)
	reg.sys("INSTALL_GAME", BtShellCommand)
	reg.sys("INSTALL_GAME_DATA", BtShellCommand)
	reg.sys("INSTALL_LIB", BtShellCommand)
	reg.sys("INSTALL_LIB_DIR", BtShellCommand)
	reg.pkglist("INSTALL_MAKE_FLAGS", BtShellWord)
	reg.sys("INSTALL_MAN", BtShellCommand)
	reg.sys("INSTALL_MAN_DIR", BtShellCommand)
	reg.sys("INSTALL_PROGRAM", BtShellCommand)
	reg.sys("INSTALL_PROGRAM_DIR", BtShellCommand)
	reg.sys("INSTALL_SCRIPT", BtShellCommand)
	reg.syslist("INSTALL_SCRIPTS_ENV", BtShellWord)
	reg.sys("INSTALL_SCRIPT_DIR", BtShellCommand)
	reg.pkglist("INSTALL_SRC", BtPathname)
	reg.pkglist("INSTALL_TARGET", BtIdentifierIndirect)
	reg.pkglist("INSTALL_TEMPLATES", BtPathname)
	reg.pkgload("INSTALL_UNSTRIPPED", BtYesNo)
	reg.pkglist("INTERACTIVE_STAGE", enum("fetch extract configure build test install"))
	reg.acl("IS_BUILTIN.*", BtYesNoIndirectly,
		PackageSettable,
		// These two differ from the standard,
		// they are needed for devel/ncursesw.
		"buildlink3.mk: use, use-loadtime",
		// The "set" differs from the standard sys.
		"builtin.mk: set, use, use-loadtime",
		"Makefile, Makefile.*, *.mk: default, set, use, use-loadtime")
	reg.sys("JAVA_BINPREFIX", BtPathname)
	reg.pkg("JAVA_CLASSPATH", BtShellWord)
	reg.pkg("JAVA_HOME", BtPathname)
	reg.pkg("JAVA_NAME", BtFilename)
	reg.pkglist("JAVA_UNLIMIT", enum("cmdsize datasize stacksize"))
	reg.pkglist("JAVA_WRAPPERS", BtFilename)
	reg.pkg("JAVA_WRAPPER_BIN.*", BtPathname)
	reg.sys("KRB5BASE", BtPathname)
	reg.pkglist("KRB5_ACCEPTED", enum("heimdal mit-krb5"))
	reg.usr("KRB5_DEFAULT", enum("heimdal mit-krb5"))
	reg.sys("KRB5_TYPE", BtIdentifierIndirect)
	reg.sys("LD", BtShellCommand)
	reg.pkglistbl3("LDFLAGS", BtLdFlag)                  // May also be changed by the user.
	reg.pkglistbl3("LDFLAGS.*", BtLdFlag)                // May also be changed by the user.
	reg.sysloadbl3("LIBABISUFFIX", BtIdentifierIndirect) // Can also be empty.
	reg.sys("LIBGRP", BtUserGroupName)
	reg.sys("LIBMODE", BtFileMode)
	reg.sys("LIBOWN", BtUserGroupName)
	reg.sys("LIBOSSAUDIO", BtPathname)
	reg.pkglist("LIBS", BtLdFlag)
	reg.pkglist("LIBS.*", BtLdFlag)
	reg.sys("LIBTOOL", BtShellCommand)
	reg.pkglist("LIBTOOL_OVERRIDE", BtWrksrcPathPattern)
	reg.pkglistrat("LIBTOOL_REQD", BtVersion)
	reg.pkgappend("LICENCE", BtLicense)
	reg.pkgappend("LICENSE", BtLicense)
	reg.pkg("LICENSE_FILE", BtPathname)
	reg.sys("LINK.*", BtShellCommand)
	reg.sys("LINKER_RPATH_FLAG", BtShellWord)
	reg.syslist("LITTLEENDIANPLATFORMS", BtMachinePlatformPattern)
	reg.sysloadbl3("LOWER_OPSYS", BtIdentifierDirect, NonemptyIfDefined)
	reg.sysloadbl3("LOWER_VENDOR", BtIdentifierDirect, NonemptyIfDefined)
	reg.sysloadbl3list("LP64PLATFORMS", BtMachinePlatformPattern, DefinedIfInScope|NonemptyIfDefined)

	// See devel/bmake/files/main.c:/Var_Set."MACHINE_ARCH"/.
	reg.sysloadbl3("MACHINE_ARCH", BtMachineArch, AlwaysInScope|DefinedIfInScope|NonemptyIfDefined)

	// From mk/endian.mk, determined by a shell program that compiles
	// a C program. That's just too much for pkglint to analyze.
	reg.sysloadbl3("MACHINE_ENDIAN", enum("big little unknown"), DefinedIfInScope|NonemptyIfDefined)

	reg.sysloadbl3("MACHINE_GNU_ARCH", BtMachineGnuArch, DefinedIfInScope|NonemptyIfDefined)
	reg.sysloadbl3("MACHINE_GNU_PLATFORM", BtMachineGnuPlatform, DefinedIfInScope|NonemptyIfDefined)
	reg.sysloadbl3("MACHINE_PLATFORM", BtMachinePlatform, DefinedIfInScope|NonemptyIfDefined)
	reg.pkg("MAINTAINER", BtMailAddress)

	// See devel/bmake/files/main.c:/Var_Set."MAKE"/.
	reg.sysloadbl3("MAKE", BtShellCommand, AlwaysInScope|DefinedIfInScope|NonemptyIfDefined)

	// System-provided, but packages may extend them.
	// TODO: This needs a special declaration since the very first
	//  assignment in a package must use += as well.
	// See devel/bmake/files/main.c:/Var_Set."MAKEFLAGS"/.
	reg.pkglist("MAKEFLAGS", BtShellWord)

	reg.pkglistbl3("MAKEVARS", BtVariableName)
	reg.pkglist("MAKE_DIRS", BtPathname)
	reg.pkglist("MAKE_DIRS_PERMS", BtPerms)
	reg.pkglistbl3("MAKE_ENV", BtShellWord)
	reg.pkglistbl3("MAKE_ENV.*", BtShellWord)
	reg.pkg("MAKE_FILE", BtPathname)
	reg.pkglist("MAKE_FLAGS", BtShellWord)
	reg.pkglist("MAKE_FLAGS.*", BtShellWord)
	reg.pkgrat("MAKE_JOBS_SAFE", BtYesNo)
	reg.pkg("MAKE_PROGRAM", BtShellCommand)
	reg.pkg("MANCOMPRESSED", BtYesNo)
	reg.pkg("MANCOMPRESSED_IF_MANZ", BtYes)
	reg.sysloadbl3("MANGRP", BtUserGroupName, DefinedIfInScope|NonemptyIfDefined)
	reg.sysloadbl3("MANMODE", BtFileMode, DefinedIfInScope|NonemptyIfDefined)
	reg.sysloadbl3("MANOWN", BtUserGroupName, DefinedIfInScope|NonemptyIfDefined)
	reg.pkglist("MASTER_SITES", BtFetchURL)

	for _, filename := range []PkgsrcPath{"mk/fetch/sites.mk", "mk/fetch/fetch.mk"} {
		sitesMk := src.LoadMkExisting(filename)
		if sitesMk != nil {
			sitesMk.ForEach(func(mkline *MkLine) {
				if mkline.IsVarassign() && hasPrefix(mkline.Varname(), "MASTER_SITE_") {
					reg.syslist(mkline.Varname(), BtFetchURL)
				}
			})
		}

		// During tests, use t.SetUpMasterSite instead to declare these variables.
	}

	reg.pkglist("MESSAGE_SRC", BtPathname)
	reg.pkglist("MESSAGE_SUBST", BtShellWord)
	reg.pkg("META_PACKAGE", BtYes)
	reg.syslist("MISSING_FEATURES", BtIdentifierDirect)
	reg.pkglist("MYSQL_VERSIONS_ACCEPTED", mysqlVersions)
	reg.usr("MYSQL_VERSION_DEFAULT", BtVersion)
	reg.sys("NATIVE_CC", BtShellCommand) // See mk/tools/tools.NetBSD.mk (and some others).
	reg.sys("NM", BtShellCommand)
	reg.sys("NONBINMODE", BtFileMode)
	reg.pkglistrat("NOT_FOR_COMPILER", compilers)
	reg.pkglistrat("NOT_FOR_BULK_PLATFORM", BtMachinePlatformPattern)
	reg.pkglistrat("NOT_FOR_PLATFORM", BtMachinePlatformPattern)
	reg.pkgrat("NOT_FOR_UNPRIVILEGED", BtYesNo)
	reg.pkglistrat("NOT_PAX_ASLR_SAFE", BtPathPattern)
	reg.pkglistrat("NOT_PAX_MPROTECT_SAFE", BtPathPattern)
	reg.pkg("NO_BIN_ON_CDROM", BtRestricted)
	reg.pkg("NO_BIN_ON_FTP", BtRestricted)
	reg.pkgload("NO_BUILD", BtYes)
	reg.pkg("NO_CHECKSUM", BtYes)
	reg.pkg("NO_CONFIGURE", BtYes)
	reg.pkg("NO_EXPORT_CPP", BtYes)
	reg.pkg("NO_EXTRACT", BtYes)
	reg.pkg("NO_INSTALL_MANPAGES", BtYes) // only has an effect for Imake packages.
	reg.pkg("NO_PKGTOOLS_REQD_CHECK", BtYes)
	reg.pkg("NO_SRC_ON_CDROM", BtRestricted)
	reg.pkg("NO_SRC_ON_FTP", BtRestricted)
	reg.sysloadbl3("OBJECT_FMT", enum("COFF ECOFF ELF SOM XCOFF Mach-O PE a.out"))
	reg.pkglistrat("ONLY_FOR_COMPILER", compilers)
	reg.pkglistrat("ONLY_FOR_PLATFORM", BtMachinePlatformPattern)
	reg.sysloadbl3("OPSYS", operatingSystems, DefinedIfInScope|NonemptyIfDefined)
	reg.pkglistbl3("OPSYSVARS", BtVariableName)
	reg.pkg("OSVERSION_SPECIFIC", BtYes)
	reg.sysloadbl3("OS_VARIANT", BtIdentifierDirect, DefinedIfInScope)
	reg.sysloadbl3("OS_VERSION", BtVersion)
	reg.sysloadbl3("OSX_VERSION", BtVersion) // See mk/platform/Darwin.mk.
	reg.pkg("OVERRIDE_DIRDEPTH*", BtInteger)
	reg.pkg("OVERRIDE_GNU_CONFIG_SCRIPTS", BtYes)
	reg.pkg("OWNER", BtMailAddress)
	reg.pkglist("OWN_DIRS", BtPathPattern)
	reg.pkglist("OWN_DIRS_PERMS", BtPerms)
	reg.sys("PAMBASE", BtPathname)
	reg.usr("PAM_DEFAULT", enum("linux-pam openpam solaris-pam"))
	reg.pkgload("PATCHDIR", BtRelativePkgPath)
	reg.pkglist("PATCHFILES", BtFilename)
	reg.pkglist("PATCH_ARGS", BtShellWord)
	reg.pkglist("PATCH_DIST_ARGS", BtShellWord)
	reg.pkg("PATCH_DIST_CAT", BtShellCommand)
	reg.pkg("PATCH_DIST_STRIP*", BtShellWord)
	reg.pkglist("PATCH_SITES", BtFetchURL)
	reg.pkg("PATCH_STRIP", BtShellWord)

	// From the PATH environment variable.
	reg.sysloadbl3("PATH", BtPathlist, AlwaysInScope|DefinedIfInScope|NonemptyIfDefined)

	reg.sys("PAXCTL", BtShellCommand) // See mk/pax.mk.
	reg.pkglist("PERL5_PACKLIST", BtPerl5Packlist)
	reg.pkg("PERL5_PACKLIST_DIR", BtPathname)
	reg.pkglistrat("PERL5_REQD", BtVersion)
	reg.sysbl3("PERL5_INSTALLARCHLIB", BtPathname) // See lang/perl5/vars.mk
	reg.sysbl3("PERL5_INSTALLSCRIPT", BtPathname)
	reg.sysbl3("PERL5_INSTALLVENDORBIN", BtPathname)
	reg.sysbl3("PERL5_INSTALLVENDORSCRIPT", BtPathname)
	reg.sysbl3("PERL5_INSTALLVENDORARCH", BtPathname)
	reg.sysbl3("PERL5_INSTALLVENDORLIB", BtPathname)
	reg.sysbl3("PERL5_INSTALLVENDORMAN1DIR", BtPathname)
	reg.sysbl3("PERL5_INSTALLVENDORMAN3DIR", BtPathname)
	reg.sysbl3("PERL5_SUB_INSTALLARCHLIB", BtPrefixPathname) // See lang/perl5/vars.mk
	reg.sysbl3("PERL5_SUB_INSTALLSCRIPT", BtPrefixPathname)
	reg.sysbl3("PERL5_SUB_INSTALLVENDORBIN", BtPrefixPathname)
	reg.sysbl3("PERL5_SUB_INSTALLVENDORSCRIPT", BtPrefixPathname)
	reg.sysbl3("PERL5_SUB_INSTALLVENDORARCH", BtPrefixPathname)
	reg.sysbl3("PERL5_SUB_INSTALLVENDORLIB", BtPrefixPathname)
	reg.sysbl3("PERL5_SUB_INSTALLVENDORMAN1DIR", BtPrefixPathname)
	reg.sysbl3("PERL5_SUB_INSTALLVENDORMAN3DIR", BtPrefixPathname)
	reg.pkg("PERL5_USE_PACKLIST", BtYesNo)
	reg.sys("PGSQL_PREFIX", BtPathname)
	reg.acllist("PGSQL_VERSIONS_ACCEPTED", pgsqlVersions,
		PackageSettable|NeedsRationale,
		// The "set" is necessary for databases/postgresql-postgis2.
		"Makefile, Makefile.*, *.mk: default, set, append, use")
	reg.usr("PGSQL_VERSION_DEFAULT", BtVersion)
	reg.sys("PG_LIB_EXT", enum("dylib so"))
	reg.sys("PGSQL_TYPE",
		reg.enumFrom(src, "mk/pgsql.buildlink3.mk", "postgresql11-client", "PGSQL_TYPE"))
	reg.sys("PGPKGSRCDIR", BtPathname)
	reg.sys("PHASE_MSG", BtShellCommand)
	reg.usr("PHP_VERSION_REQD", BtVersion)
	reg.acl("PHP_PKG_PREFIX",
		reg.enumFromDirs(src, "lang", `^php(\d+)$`, "php$1", "php56 php71 php72 php73"),
		SystemProvided,
		"special:phpversion.mk: set",
		"*: use, use-loadtime")
	reg.sys("PKGBASE", BtIdentifierDirect)
	// Despite its name, this is actually a list of filenames.
	reg.acllist("PKGCONFIG_FILE.*", BtPathname,
		PackageSettable,
		"builtin.mk: set, append",
		"special:pkgconfig-builtin.mk: use-loadtime")
	reg.pkglist("PKGCONFIG_OVERRIDE", BtWrksrcPathPattern)
	reg.pkg("PKGCONFIG_OVERRIDE_STAGE", BtStage)
	reg.pkg("PKGDIR", BtRelativePkgDir)
	reg.sys("PKGDIRMODE", BtFileMode)
	reg.sys("PKGLOCALEDIR", BtPathname)
	reg.pkg("PKGNAME", BtPkgname)
	reg.sys("PKGNAME_NOREV", BtPkgname)
	reg.sysloadbl3("PKGPATH", BtPkgpath, DefinedIfInScope|NonemptyIfDefined)
	reg.sys("PKGREPOSITORY", BtUnknown)
	// This variable is special in that it really only makes sense to
	// be set in a package Makefile.
	// See VartypeCheck.Pkgrevision for details.
	reg.acl("PKGREVISION", BtPkgrevision,
		PackageSettable|NonemptyIfDefined,
		"Makefile: set")
	reg.sysloadbl3("PKGSRCDIR", BtPathname, DefinedIfInScope|NonemptyIfDefined)
	// This definition is only valid in the top-level Makefile,
	// not in category or package Makefiles.
	reg.acl("PKGSRCTOP", BtYes,
		PackageSettable,
		"Makefile: set")
	reg.sys("PKGSRC_SETENV", BtShellCommand)
	reg.syslist("PKGTOOLS_ENV", BtShellWord)
	reg.sys("PKGVERSION", BtVersion)
	reg.sys("PKGVERSION_NOREV", BtVersion) // Without the nb* part.
	reg.sys("PKGWILDCARD", BtFilePattern)
	reg.sysloadbl3("PKG_ADMIN", BtShellCommand)
	reg.sys("PKG_APACHE", enum("apache24"), DefinedIfInScope|NonemptyIfDefined)
	reg.pkglistrat("PKG_APACHE_ACCEPTED", enum("apache24"))
	reg.usr("PKG_APACHE_DEFAULT", enum("apache24"))
	reg.sysloadbl3list("PKG_BUILD_OPTIONS.*", BtOption)
	reg.usr("PKG_CONFIG", BtYes)
	// ^^ No, this is not the popular command from GNOME, but the setting
	// whether the pkgsrc user wants configuration files automatically
	// installed or not.
	reg.sys("PKG_CREATE", BtShellCommand)
	reg.sys("PKG_DBDIR", BtPathname)
	reg.cmdline("PKG_DEBUG_LEVEL", BtInteger)
	reg.usrlist("PKG_DEFAULT_OPTIONS", BtOption)
	reg.sys("PKG_DELETE", BtShellCommand)
	reg.pkglist("PKG_DESTDIR_SUPPORT", enum("destdir user-destdir"))
	reg.pkglistone("PKG_FAIL_REASON", BtShellWord)
	reg.sysloadbl3("PKG_FORMAT", BtIdentifierDirect)
	reg.pkg("PKG_GECOS.*", BtMessage)
	reg.pkg("PKG_GID.*", BtInteger)
	reg.pkglist("PKG_GROUPS", BtShellWord)
	reg.pkglist("PKG_GROUPS_VARS", BtVariableName)
	reg.pkg("PKG_HOME.*", BtPathname)
	// PKG_HACKS is used to record the applied hacks in the binary package.
	// Since only the hacks.mk can define hacks, appending to it only makes
	// sense there.
	//
	// TODO: Is it possible that a package includes the hacks.mk file from
	//  one of its dependencies?
	reg.acllist("PKG_HACKS", BtIdentifierDirect,
		PackageSettable,
		"*: none")
	reg.sysloadbl3("PKG_INFO", BtShellCommand, DefinedIfInScope|NonemptyIfDefined)
	reg.sys("PKG_JAVA_HOME", BtPathname)
	reg.sysloadbl3("PKG_JVM", jvms)
	reg.pkglistrat("PKG_JVMS_ACCEPTED", jvms)
	reg.sys("PKG_LIBTOOL", BtPathname)

	// begin PKG_OPTIONS section
	//
	// Most identifiers for the groups are given as literal strings.
	// In rare cases (audio/speex), ${MACHINE_ARCH} is used for selecting a group,
	// but not for defining it.
	//
	// TODO: Consider forcing the pkgsrc packages to only define options in the
	//  options.mk file. Most packages already do this, but some still
	//  define them in the Makefile or Makefile.common.
	reg.sysloadbl3list("PKG_OPTIONS", BtOption, DefinedIfInScope|NonemptyIfDefined)
	reg.usrlist("PKG_OPTIONS.*", BtOption)
	reg.pkgloadlist("PKG_LEGACY_OPTIONS", BtOption)
	reg.pkgloadlist("PKG_OPTIONS_DEPRECATED_WARNINGS", BtShellWord)
	reg.pkgloadlist("PKG_OPTIONS_GROUP.*", BtOption)
	reg.pkgloadlist("PKG_OPTIONS_LEGACY_OPTS", BtUnknown)
	reg.pkgloadlist("PKG_OPTIONS_LEGACY_VARS", BtUnknown)
	reg.pkgloadlist("PKG_OPTIONS_NONEMPTY_SETS", BtIdentifierIndirect)
	reg.pkgloadlist("PKG_OPTIONS_OPTIONAL_GROUPS", BtIdentifierIndirect)
	reg.pkgloadlist("PKG_OPTIONS_REQUIRED_GROUPS", BtIdentifierIndirect)
	reg.pkgloadlist("PKG_OPTIONS_SET.*", BtOption)
	reg.pkgload("PKG_OPTIONS_VAR", BtPkgOptionsVar)
	reg.pkgloadlist("PKG_SUGGESTED_OPTIONS", BtOption)
	reg.pkgloadlist("PKG_SUGGESTED_OPTIONS.*", BtOption)
	reg.pkgloadlist("PKG_SUPPORTED_OPTIONS", BtOption)
	reg.pkgloadlist("PKG_SUPPORTED_OPTIONS.*", BtOption)
	// end PKG_OPTIONS section

	reg.pkg("PKG_PRESERVE", BtYes)
	reg.pkg("PKG_SHELL", BtPathname)
	reg.pkg("PKG_SHELL.*", BtPathname)
	reg.sys("PKG_SHLIBTOOL", BtPathname)
	reg.pkglistone("PKG_SKIP_REASON", BtShellWord)
	// The special exception for buildlink3.mk is only here because
	// of textproc/xmlcatmgr.
	reg.acl("PKG_SYSCONFDIR*", BtPathname,
		PackageSettable,
		"Makefile: set, use, use-loadtime",
		"buildlink3.mk, builtin.mk: use-loadtime",
		"Makefile.*, *.mk: default, set, use, use-loadtime")
	reg.pkglist("PKG_SYSCONFDIR_PERMS", BtPerms)
	reg.sys("PKG_SYSCONFBASEDIR", BtPathname)
	reg.pkg("PKG_SYSCONFSUBDIR", BtPathname)
	reg.pkg("PKG_SYSCONFVAR", BtIdentifierDirect)
	reg.pkg("PKG_UID", BtInteger)
	reg.pkglist("PKG_USERS", BtShellWord)
	reg.pkglist("PKG_USERS_VARS", BtVariableName)
	reg.pkg("PKG_USE_KERBEROS", BtYes)
	reg.pkgload("PLIST.*", BtYes)
	reg.pkgloadlist("PLIST_VARS", BtPlistIdentifier)
	reg.pkglist("PLIST_SRC", BtRelativePkgPath)
	reg.pkglist("PLIST_SUBST", BtShellWord)
	reg.pkg("PLIST_TYPE", enum("dynamic static"))
	reg.pkglistbl3("PREPEND_PATH", BtPathname)

	// PREFIX is indeed defined late, in bsd.pkg.use.mk, included by bsd.pkg.mk.
	// It may be used everywhere since it is a rather central variable.
	reg.acl("PREFIX", BtPathname, SystemProvided|DefinedIfInScope,
		"*: use")

	// BtPathname instead of BtPkgpath since the original package doesn't exist anymore.
	// It would be more precise to check for a Pkgpath that doesn't exist anymore.
	reg.pkg("PREV_PKGPATH", BtPathname)
	reg.acl("PRINT_PLIST_AWK", BtAwkCommand,
		PackageSettable,
		"*: append")
	reg.pkglist("PRIVILEGED_STAGES", enum("build install package clean"))
	reg.pkgbl3("PTHREAD_AUTO_VARS", BtYesNo)
	reg.syslist("PTHREAD_CFLAGS", BtCFlag)
	reg.syslist("PTHREAD_LDFLAGS", BtLdFlag)
	reg.syslist("PTHREAD_LIBS", BtLdFlag)
	reg.pkglistbl3("PTHREAD_OPTS", enum("native optional require"))
	reg.sysloadbl3("PTHREAD_TYPE", BtIdentifierDirect) // Or "native" or "none".
	reg.pkg("PY_PATCHPLIST", BtYes)
	reg.acl("PYPKGPREFIX",
		reg.enumFromDirs(src, "lang", `^python(\d+)$`, "py$1", "py27 py36"),
		SystemProvided,
		"special:pyversion.mk: set",
		"*: use, use-loadtime")
	// See lang/python/pyversion.mk
	py := reg.enumFromDirs(src, "lang", `^python(\d+)$`, "$1", "27 36 37 38")
	reg.pkg("PYTHON_FOR_BUILD_ONLY", enum("yes no test tool YES"))
	reg.pkglistrat("PYTHON_VERSIONS_ACCEPTED", py)
	reg.pkglistrat("PYTHON_VERSIONS_INCOMPATIBLE", py)
	reg.usr("PYTHON_VERSION_DEFAULT", py)
	reg.sys("PYTHON_VERSION_REQD", py)
	reg.pkglist("PYTHON_VERSIONED_DEPENDENCIES", BtPythonDependency)
	reg.sys("RANLIB", BtShellCommand)
	reg.pkglist("RCD_SCRIPTS", BtFilename)
	// TODO: Is the definition in www/squid3/Makefile detected as being redundant?
	//  No, but it could if the RedundancyScope were able to resolve ${FILESDIR}
	//  to "files".
	reg.pkg("RCD_SCRIPT_SRC.*", BtPathname)
	reg.pkg("RCD_SCRIPT_WRK.*", BtPathname)
	reg.sysloadbl3("READLINE_TYPE", enum("editline none readline"),
		DefinedIfInScope|NonemptyIfDefined)
	reg.usr("REAL_ROOT_USER", BtUserGroupName)
	reg.usr("REAL_ROOT_GROUP", BtUserGroupName)

	// Example:
	//  REPLACE.sys-AWK.old=    .*awk
	//  REPLACE.sys-AWK.new=    ${AWK}
	// BtUnknown since one of them is a regular expression and the other
	// is a plain string.
	reg.pkg("REPLACE.*", BtUnknown)

	reg.pkglist("REPLACE_AWK", BtWrksrcPathPattern)
	reg.pkglist("REPLACE_BASH", BtWrksrcPathPattern)
	reg.pkglist("REPLACE_CSH", BtWrksrcPathPattern)
	reg.pkglist("REPLACE_FILES.*", BtWrksrcPathPattern)
	reg.pkglist("REPLACE_INTERPRETER", BtIdentifierIndirect)
	reg.pkglist("REPLACE_KSH", BtWrksrcPathPattern)
	reg.pkglist("REPLACE_LOCALEDIR_PATTERNS", BtFilePattern)
	reg.pkglist("REPLACE_LUA", BtWrksrcPathPattern)
	reg.pkglist("REPLACE_PERL", BtWrksrcPathPattern)
	reg.pkglist("REPLACE_PYTHON", BtWrksrcPathPattern)
	reg.pkglist("REPLACE_SH", BtWrksrcPathPattern)
	reg.pkglist("REQD_DIRS", BtPathname)
	reg.pkglist("REQD_DIRS_PERMS", BtPerms)
	reg.pkglist("REQD_FILES", BtPathname)
	reg.pkg("REQD_FILES_MODE", enum("0644 0640 0600 0400"))
	reg.pkglist("REQD_FILES_PERMS", BtPerms)
	reg.pkg("RESTRICTED", BtMessage)
	reg.usr("ROOT_USER", BtUserGroupName)
	reg.usr("ROOT_GROUP", BtUserGroupName)
	reg.pkglist("RPMIGNOREPATH", BtPathPattern)
	reg.acl("RUBY_BASE",
		reg.enumFromDirs(src, "lang", `^ruby(\d+)$`, "ruby$1", "ruby22 ruby23 ruby24 ruby25"),
		SystemProvided,
		"special:rubyversion.mk: set",
		"*: use, use-loadtime")
	reg.usr("RUBY_VERSION_REQD", BtVersion)
	reg.acl("RUBY_PKGPREFIX",
		reg.enumFromDirs(src, "lang", `^ruby(\d+)$`, "ruby$1", "ruby22 ruby23 ruby24 ruby25"),
		SystemProvided,
		"special:rubyversion.mk: default, set, use",
		"*: use, use-loadtime")
	reg.sys("RUN", BtShellCommand, DefinedIfInScope|NonemptyIfDefined)
	reg.sys("RUN_LDCONFIG", BtYesNo)
	reg.pkg("R_PKGNAME", BtRPkgName)
	reg.pkg("R_PKGVER", BtRPkgVer)
	reg.pkglist("SCRIPTS_ENV", BtShellWord)
	reg.usrlist("SETGID_GAMES_PERMS", BtPerms)
	reg.usrlist("SETUID_ROOT_PERMS", BtPerms)
	reg.pkg("SET_LIBDIR", BtYes)
	reg.sysloadbl3("SHAREGRP", BtUserGroupName, DefinedIfInScope|NonemptyIfDefined)
	reg.sysloadbl3("SHAREMODE", BtFileMode, DefinedIfInScope|NonemptyIfDefined)
	reg.sysloadbl3("SHAREOWN", BtUserGroupName, DefinedIfInScope|NonemptyIfDefined)
	reg.sys("SHCOMMENT", BtShellCommand, DefinedIfInScope|NonemptyIfDefined)
	reg.sys("SHLIBTOOL", BtShellCommand)
	reg.pkglist("SHLIBTOOL_OVERRIDE", BtWrksrcPathPattern)
	reg.sysloadbl3("SHLIB_TYPE",
		enum("COFF ECOFF ELF SOM XCOFF Mach-O PE PEwin a.out aixlib dylib none"),
		DefinedIfInScope|NonemptyIfDefined)
	reg.pkglist("SITES.*", BtFetchURL)
	reg.usr("SMF_PREFIS", BtPathname)
	reg.pkg("SMF_SRCDIR", BtPathname)
	reg.pkg("SMF_NAME", BtFilename)
	reg.pkg("SMF_MANIFEST", BtPathname)
	reg.pkglist("SMF_INSTANCES", BtIdentifierIndirect)
	reg.pkglist("SMF_METHODS", BtFilename)
	reg.pkg("SMF_METHOD_SRC.*", BtPathname)
	reg.pkg("SMF_METHOD_SHELL", BtShellCommand)
	reg.pkglist("SPECIAL_PERMS", BtPerms)
	reg.sys("STEP_MSG", BtShellCommand, DefinedIfInScope|NonemptyIfDefined)
	reg.sys("STRIP", BtShellCommand) // see mk/tools/strip.mk

	// Only valid in the top-level and the category Makefiles.
	reg.acllist("SUBDIR", BtFilename,
		PackageSettable,
		"Makefile: append")

	reg.usr("SUBST_NOOP_OK", BtYesNo)
	reg.usr("SUBST_SHOW_DIFF", BtYesNo)
	reg.pkglistbl3("SUBST_CLASSES", BtIdentifierDirect)
	reg.pkglistbl3("SUBST_CLASSES.*", BtIdentifierDirect) // OPSYS-specific
	reg.pkgbl3("SUBST_STAGE.*", BtStage)
	reg.pkgbl3("SUBST_MESSAGE.*", BtMessage)
	reg.pkglistbl3("SUBST_FILES.*", BtWrksrcPathPattern)
	reg.pkgappendbl3("SUBST_SED.*", BtSedCommands)
	reg.pkglistbl3("SUBST_VARS.*", BtVariableName)
	reg.pkgbl3("SUBST_FILTER_CMD.*", BtShellCommand)
	reg.pkgbl3("SUBST_SKIP_TEXT_CHECK.*", BtYesNo)
	reg.pkgbl3("SUBST_SHOW_DIFF.*", BtYesNo)
	reg.pkgbl3("SUBST_NOOP_OK.*", BtYesNo)

	reg.pkglist("SUPERSEDES", BtDependencyPattern)
	reg.pkglist("TEST_DEPENDS", BtDependencyWithPath)
	reg.pkglist("TEST_DIRS", BtWrksrcSubdirectory)
	reg.pkglist("TEST_ENV", BtShellWord)
	reg.pkglist("TEST_TARGET", BtIdentifierIndirect)
	reg.pkglistrat("TEXINFO_REQD", BtVersion)
	reg.pkglistbl3("TOOL_DEPENDS", BtDependencyWithPath)
	reg.syslist("TOOLS_ALIASES", BtFilename)
	reg.pkglistbl3("TOOLS_BROKEN", BtToolName)
	reg.sys("TOOLS_CMD.*", BtPathname)
	reg.pkglist("TOOLS_CREATE", BtToolName)
	reg.pkglist("TOOLS_DEPENDS.*", BtDependencyWithPath)
	reg.pkglistbl3("TOOLS_FAIL", BtToolName)
	reg.syslist("TOOLS_GNU_MISSING", BtToolName)
	reg.pkglistbl3("TOOLS_NOOP", BtToolName)
	reg.sys("TOOLS_PATH.*", BtPathname)
	reg.sysloadbl3("TOOLS_PLATFORM.*", BtShellCommand)
	reg.sysloadbl3("TOOLS_SHELL", BtShellCommand)
	reg.syslist("TOUCH_FLAGS", BtShellWord)
	reg.pkglist("UAC_REQD_EXECS", BtPrefixPathname)
	reg.pkglistbl3("UNLIMIT_RESOURCES",
		enum("cputime datasize memorysize stacksize virtualsize"))
	reg.usr("UNPRIVILEGED_USER", BtUserGroupName)
	reg.usr("UNPRIVILEGED_GROUP", BtUserGroupName)
	reg.pkglist("UNWRAP_FILES", BtPathPattern)
	reg.cmdline("UPDATE_TARGET", BtIdentifierDirect, List)
	reg.pkg("USERGROUP_PHASE", enum("configure build pre-install"))
	reg.usrlist("USER_ADDITIONAL_PKGS", BtPkgpath)
	reg.pkg("USE_BSD_MAKEFILE", BtYes)

	// USE_BUILTIN.* is usually set by the builtin.mk file, after checking
	// whether the package is available in the base system. To override
	// this check, a package may set this variable before including the
	// corresponding buildlink3.mk file.
	reg.acl("USE_BUILTIN.*", BtYesNoIndirectly,
		PackageSettable|DefinedIfInScope|NonemptyIfDefined,
		"Makefile, Makefile.*, *.mk: set, use, use-loadtime")

	reg.pkg("USE_CMAKE", BtYes)
	reg.usr("USE_DESTDIR", BtYes)
	reg.pkglist("USE_FEATURES", BtIdentifierDirect)
	reg.pkg("USE_GAMESGROUP", BtYesNo)
	reg.pkg("USE_GCC_RUNTIME", BtYesNo)
	reg.pkg("USE_GNU_CONFIGURE_HOST", BtYesNo)
	reg.pkgload("USE_GNU_ICONV", BtYes)
	reg.pkg("USE_IMAKE", BtYes)
	reg.pkg("USE_JAVA", enum("run yes build"))
	reg.pkg("USE_JAVA2", enum("YES yes no 1.4 1.5 6 7 8"))
	reg.pkglist("USE_LANGUAGES", reg.compilerLanguages(src))
	reg.pkg("USE_LIBTOOL", BtYes)
	reg.pkg("USE_MAKEINFO", BtYes)
	reg.pkg("USE_MSGFMT_PLURALS", BtYes)
	reg.pkg("USE_NCURSES", BtYes)
	reg.pkg("USE_OLD_DES_API", BtYesNo)
	reg.pkg("USE_PKGINSTALL", BtYes)
	reg.pkg("USE_PKGLOCALEDIR", BtYesNo)
	reg.usr("USE_PKGSRC_GCC", BtYes)

	// USE_TOOLS is not similar to any predefined permissions set.
	//
	// It may be appended to in buildlink3 files to make tools available
	// at runtime. Making tools available at load time would only work
	// before bsd.prefs.mk has been included for the first time, and that
	// cannot be guaranteed.
	//
	// There are a few builtin.mk files that check whether some tool is
	// already contained in USE_TOOLS. For them, use-loadtime is allowed.
	//
	// All other files may also use = instead of +=. Cases where the tools
	// list is accidentally overwritten are detected by the redundancy check.
	//
	// The use-loadtime is only for devel/ncurses/Makefile.common, which
	// removes tbl from USE_TOOLS.
	reg.acllist("USE_TOOLS", BtToolDependency,
		PackageSettable,
		"special:Makefile.common: set, append, use, use-loadtime",
		"buildlink3.mk: append",
		"builtin.mk: append, use-loadtime",
		"*: set, append, use")
	reg.acllist("USE_TOOLS.*", BtToolDependency, // OPSYS-specific
		PackageSettable,
		"buildlink3.mk, builtin.mk: append",
		"*: set, append, use")

	reg.pkg("USE_X11", BtYes)
	reg.syslist("WARNINGS", BtShellWord)
	reg.sys("WARNING_MSG", BtShellCommand)
	reg.sys("WARNING_CAT", BtShellCommand)
	reg.sysloadbl3("WRAPPER_DIR", BtPathname)
	reg.pkglistbl3("WRAPPER_REORDER_CMDS", BtWrapperReorder)
	reg.pkg("WRAPPER_SHELL", BtShellCommand)
	reg.pkglist("WRAPPER_TRANSFORM_CMDS", BtWrapperTransform)
	reg.sys("WRKDIR", BtPathname)
	reg.pkg("WRKSRC", BtWrkdirSubdirectory)
	reg.pkglist("X11_LDFLAGS", BtLdFlag)
	reg.sys("X11_PKGSRCDIR.*", BtPathname)
	reg.pkglist("XMKMF_FLAGS", BtShellWord)
	reg.sys("_ULIMIT_CMD", BtShellCommands)
	reg.pkglist("_WRAP_EXTRA_ARGS.*", BtShellWord)

	reg.infralist("_VARGROUPS", BtIdentifierDirect)
	reg.infralist("_USER_VARS.*", BtVariableName)
	reg.infralist("_PKG_VARS.*", BtVariableName)
	reg.infralist("_SYS_VARS.*", BtVariableName)
	reg.infralist("_DEF_VARS.*", BtVariableName)
	reg.infralist("_USE_VARS.*", BtVariableName)
	reg.infralist("_IGN_VARS.*", BtVariableNamePattern)
	reg.infralist("_SORTED_VARS.*", BtVariableNamePattern)
	reg.infralist("_LISTED_VARS.*", BtVariableNamePattern)
}

func enum(values string) *BasicType {
	valueMap := make(map[string]bool)
	for _, value := range strings.Fields(values) {
		valueMap[value] = true
	}
	name := "enum: " + values + " " // See IsEnum
	basicType := BasicType{name, nil}
	basicType.checker = func(check *VartypeCheck) {
		check.Enum(valueMap, &basicType)
	}
	return &basicType
}

func (reg *VarTypeRegistry) parseACLEntries(varname string, aclEntries ...string) []ACLEntry {

	assert(len(aclEntries) > 0)

	// TODO: Use separate rules for infrastructure files.
	//  These rules would have the "infra:" prefix
	//  that works similar to the already existing prefix "special:".
	//  The "infra:" prefix applies to both mk/* and wip/mk/* files, and globs
	//  without that prefix only apply to all files outside the infrastructure.

	var result []ACLEntry
	prevperms := "(first)"
	for _, arg := range aclEntries {
		fields := strings.Split(arg, ": ")
		assertf(len(fields) == 2, "ACL entry %q must have exactly 1 colon.", arg)
		globs, perms := fields[0], fields[1]

		assertf(perms != prevperms, "Repeated permissions %q for %q.", perms, varname)
		prevperms = perms

		permissions := reg.parsePermissions(varname, globs, perms)

		for _, glob := range strings.Split(globs, ", ") {
			switch glob {
			case "*",
				"Makefile", "Makefile.*",
				"buildlink3.mk", "builtin.mk", "options.mk", "*.mk":
				break
			default:
				withoutSpecial := strings.TrimPrefix(glob, "special:")
				if withoutSpecial == glob {
					assertf(false, "Invalid ACL glob %q for %q.", glob, varname)
				} else {
					glob = withoutSpecial
				}
			}
			for _, prev := range result {
				matched := prev.matcher.matches(glob)
				assertf(!matched, "Unreachable ACL pattern %q for %q.", glob, varname)
			}
			result = append(result, NewACLEntry(glob, permissions))
		}
	}

	return result
}

func (reg *VarTypeRegistry) parsePermissions(varname, globs, perms string) ACLPermissions {
	if perms == "none" {
		return aclpNone
	}

	splitPerms := strings.Split(perms, ", ")
	var permissions ACLPermissions

	remove := func(name string, perm ACLPermissions) {
		if len(splitPerms) > 0 && splitPerms[0] == name {
			permissions |= perm
			splitPerms = splitPerms[1:]
		}
	}

	// The order of the assignment permissions is in perceived
	// chronological order. First the default assignment, which
	// can later be overridden by an unconditional assignment,
	// and that can be appended later to add more values.
	remove("default", aclpSetDefault)
	remove("set", aclpSet)
	remove("append", aclpAppend)

	// When using a variable, "use" comes first because it feels
	// more general. Most variables that can be used at load time
	// can also be used at run time.
	//
	// Using a variable at load time is a special access that
	// applies to fewer variables. Therefore it comes last.
	remove("use", aclpUse)
	remove("use-loadtime", aclpUseLoadtime)

	if len(splitPerms) > 0 {
		assertf(
			false,
			"Invalid ACL permission %q for %q in %q. "+
				"Remaining parts are %q. "+
				"Valid permissions are default, set, append, "+
				"use, use-loadtime (in this order), or none.",
			perms, varname, globs, strings.Join(splitPerms, ", "))
	}
	return permissions
}
