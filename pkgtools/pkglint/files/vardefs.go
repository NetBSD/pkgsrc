package pkglint

import (
	"netbsd.org/pkglint/regex"
	"path"
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
// TODO: There are separate permission rules for files from the pkgsrc
//  infrastructure since the infrastructure basically provides the API, and
//  the packages use the API.
//
// Variables that are defined by packages are usually used by the
// infrastructure, and vice versa. There are also user-defined variables,
// which from the view point of a package, are the same as variables
// defined by the infrastructure.

type VarTypeRegistry struct {
	types map[string]*Vartype // varcanon => type
}

func NewVarTypeRegistry() VarTypeRegistry {
	return VarTypeRegistry{make(map[string]*Vartype)}
}

func (reg *VarTypeRegistry) Canon(varname string) *Vartype {
	vartype := reg.types[varname]
	if vartype == nil {
		vartype = reg.types[varnameCanon(varname)]
	}
	return vartype
}

func (reg *VarTypeRegistry) DefinedExact(varname string) bool {
	return reg.types[varname] != nil
}

func (reg *VarTypeRegistry) DefinedCanon(varname string) bool {
	return reg.Canon(varname) != nil
}

func (reg *VarTypeRegistry) DefineType(varcanon string, vartype *Vartype) {
	reg.types[varcanon] = vartype
}

func (reg *VarTypeRegistry) Define(varname string, basicType *BasicType, options vartypeOptions, aclEntries ...ACLEntry) {
	m, varbase, varparam := match2(varname, `^([A-Z_.][A-Z0-9_]*|@)(|\*|\.\*)$`)
	G.Assertf(m, "invalid variable name")

	vartype := Vartype{basicType, options, aclEntries}

	if varparam == "" || varparam == "*" {
		reg.types[varbase] = &vartype
	}
	if varparam == "*" || varparam == ".*" {
		reg.types[varbase+".*"] = &vartype
	}
}

// DefineParse defines a variable with the given type and permissions.
//
// A permission entry looks like this:
//  "Makefile, Makefile.*, *.mk: default, set, append, use, use-loadtime"
// Only certain filenames are allowed in the part before the colon,
// to prevent typos. To use arbitrary filenames, prefix them with
// "special:".
//
// TODO: To be implemented: when prefixed with "infra:", the entry only
//  applies to files within the pkgsrc infrastructure. Without this prefix,
//  the pattern only applies to files outside the pkgsrc infrastructure.
func (reg *VarTypeRegistry) DefineParse(varname string, basicType *BasicType, options vartypeOptions, aclEntries ...string) {
	parsedEntries := reg.parseACLEntries(varname, aclEntries...)
	reg.Define(varname, basicType, options, parsedEntries...)
}

// Init initializes the long list of predefined pkgsrc variables.
// After this is done, PKGNAME, MAKE_ENV and all the other variables
// can be used in Makefiles without triggering warnings about typos.
func (reg *VarTypeRegistry) Init(src *Pkgsrc) {

	// acl defines the permissions of a variable by listing the permissions
	// individually.
	//
	// Each variable that uses this function directly must document:
	//  - which of the predefined permission sets is the closest
	//  - how this individual permission set differs
	//  - why the predefined permission set is not good enough
	//  - which packages need this custom permission set.
	acl := func(varname string, basicType *BasicType, options vartypeOptions, aclEntries ...string) {
		G.Assertf(!reg.DefinedExact(varname), "Variable %q must only be defined once.", varname)
		reg.DefineParse(varname, basicType, options, aclEntries...)
	}

	// acllist defines the permissions of a list variable by listing
	// the permissions individually.
	//
	// Each variable that uses this function directly must document:
	//  - which of the predefined permission sets is the closest
	//  - how this individual permission set differs
	//  - why the predefined permission set is not good enough
	//  - which packages need this custom permission set.
	acllist := func(varname string, basicType *BasicType, options vartypeOptions, aclEntries ...string) {
		acl(varname, basicType, options|List, aclEntries...)
	}

	// A package-settable variable may be set in all Makefiles except buildlink3.mk and builtin.mk.
	pkg := func(varname string, basicType *BasicType) {
		acl(varname, basicType,
			PackageSettable,
			"buildlink3.mk, builtin.mk: none",
			"Makefile, Makefile.*, *.mk: default, set, use")
	}

	// Like pkg, but always needs a rationale.
	pkgrat := func(varname string, basicType *BasicType) {
		acl(varname, basicType,
			PackageSettable|NeedsRationale,
			"buildlink3.mk, builtin.mk: none",
			"Makefile, Makefile.*, *.mk: default, set, use")
	}

	// pkgload is the same as pkg, except that the variable may be accessed at load time.
	pkgload := func(varname string, basicType *BasicType) {
		acl(varname, basicType,
			PackageSettable,
			"buildlink3.mk: none",
			"builtin.mk: use, use-loadtime",
			"Makefile, Makefile.*, *.mk: default, set, use, use-loadtime")
	}

	// A package-defined list may be defined and appended to in all Makefiles
	// except buildlink3.mk and builtin.mk. Simple assignment (instead of
	// appending) is also allowed. If this leads of an unconditional
	// assignment overriding a previous value, the redundancy check will
	// catch it.
	pkglist := func(varname string, basicType *BasicType) {
		acllist(varname, basicType,
			List|PackageSettable,
			"buildlink3.mk, builtin.mk: none",
			"Makefile, Makefile.*, *.mk: default, set, append, use")
	}

	// Like pkglist, but always needs a rationale.
	pkglistrat := func(varname string, basicType *BasicType) {
		acllist(varname, basicType,
			List|PackageSettable|NeedsRationale,
			"buildlink3.mk, builtin.mk: none",
			"Makefile, Makefile.*, *.mk: default, set, append, use")
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
	pkgappend := func(varname string, basicType *BasicType) {
		acl(varname, basicType,
			PackageSettable,
			"buildlink3.mk, builtin.mk: none",
			"Makefile, Makefile.*, *.mk: default, set, append, use")
	}
	pkgappendbl3 := func(varname string, basicType *BasicType) {
		acl(varname, basicType,
			PackageSettable,
			"Makefile, Makefile.*, *.mk: default, set, append, use")
	}

	// Like pkgappend, but always needs a rationale.
	pkgappendrat := func(varname string, basicType *BasicType) {
		acl(varname, basicType,
			PackageSettable|NeedsRationale,
			"buildlink3.mk, builtin.mk: none",
			"Makefile, Makefile.*, *.mk: default, set, append, use")
	}

	// Some package-defined variables may be modified in buildlink3.mk files.
	// These variables are typically related to compiling and linking files
	// from C and related languages.
	pkgbl3 := func(varname string, basicType *BasicType) {
		acl(varname, basicType,
			PackageSettable,
			"Makefile, Makefile.*, *.mk: default, set, use")
	}
	// Some package-defined lists may also be modified in buildlink3.mk files,
	// for example platform-specific CFLAGS and LDFLAGS.
	pkglistbl3 := func(varname string, basicType *BasicType) {
		acl(varname, basicType,
			List|PackageSettable,
			"Makefile, Makefile.*, *.mk: default, set, append, use")
	}

	// Like pkglistbl3, but always needs a rationale.
	pkglistbl3rat := func(varname string, basicType *BasicType) {
		acl(varname, basicType,
			List|PackageSettable|NeedsRationale,
			"Makefile, Makefile.*, *.mk: default, set, append, use")
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
	sys := func(varname string, basicType *BasicType) {
		acl(varname, basicType,
			SystemProvided,
			"buildlink3.mk: none",
			"*: use")
	}

	sysbl3 := func(varname string, basicType *BasicType) {
		acl(varname, basicType,
			SystemProvided,
			"*: use")
	}

	syslist := func(varname string, basicType *BasicType) {
		acllist(varname, basicType,
			List|SystemProvided,
			"buildlink3.mk: none",
			"*: use")
	}

	// usr declares a user-defined variable that must not be modified by packages.
	usr := func(varname string, basicType *BasicType) {
		acl(varname, basicType,
			// TODO: why is builtin.mk missing here?
			UserSettable,
			"buildlink3.mk: none",
			"*: use, use-loadtime")
	}

	// usr declares a user-defined list variable that must not be modified by packages.
	usrlist := func(varname string, basicType *BasicType) {
		acllist(varname, basicType,
			// TODO: why is builtin.mk missing here?
			List|UserSettable,
			"buildlink3.mk: none",
			"*: use, use-loadtime")
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
	usrpkg := func(varname string, basicType *BasicType) {
		acl(varname, basicType,
			PackageSettable|UserSettable,
			"Makefile: default, set, use, use-loadtime",
			"buildlink3.mk, builtin.mk: none",
			"Makefile.*, *.mk: default, set, use, use-loadtime",
			"*: use, use-loadtime")
	}

	// sysload declares a system-provided variable that may already be used at load time.
	sysload := func(varname string, basicType *BasicType) {
		acl(varname, basicType,
			SystemProvided,
			"*: use, use-loadtime")
	}

	sysloadlist := func(varname string, basicType *BasicType) {
		acl(varname, basicType,
			List|SystemProvided,
			"*: use, use-loadtime")
	}

	// bl3list declares a list variable that is defined by buildlink3.mk and
	// builtin.mk and can later be used by the package.
	bl3list := func(varname string, basicType *BasicType) {
		acl(varname, basicType,
			List, // not PackageSettable since the package uses it more than setting it.
			"buildlink3.mk, builtin.mk: append",
			"*: use")
	}

	// cmdline declares a variable that is defined on the command line. There
	// are only few variables of this type, such as PKG_DEBUG_LEVEL.
	cmdline := func(varname string, basicType *BasicType) {
		acl(varname, basicType,
			CommandLineProvided,
			"buildlink3.mk, builtin.mk: none",
			"*: use, use-loadtime")
	}

	// Only for infrastructure files; see mk/misc/show.mk
	infralist := func(varname string, basicType *BasicType) {
		acllist(varname, basicType,
			List,
			"*: append")
	}

	// compilerLanguages reads the available languages that are typically
	// bundled in a single compiler framework, such as GCC or Clang.
	compilerLanguages := enum(
		func() string {
			mklines := LoadMk(src.File("mk/compiler.mk"), NotEmpty)
			languages := make(map[string]bool)
			if mklines != nil {
				for _, mkline := range mklines.mklines {
					if mkline.IsDirective() && mkline.Directive() == "for" {
						words := mkline.ValueFields(mkline.Args())
						if len(words) > 2 && words[0] == "_version_" {
							for _, word := range words[2:] {
								languages[intern(word)] = true
							}
						}
					}
				}
			}
			alwaysAvailable := [...]string{
				"ada", "c", "c99", "c++", "c++11", "c++14",
				"fortran", "fortran77", "java", "objc", "obj-c++"}
			for _, language := range alwaysAvailable {
				languages[language] = true
			}

			joined := keysJoined(languages)
			if trace.Tracing {
				trace.Stepf("Languages from mk/compiler.mk: %s", joined)
			}
			return joined
		}())

	// enumFrom parses all variable definitions for the given file,
	// and for all variables matching one of the varcanons, all values
	// are added as allowed values.
	//
	// If the file cannot be found, the allowed values are taken from
	// defval. This is mostly useful when testing pkglint.
	enumFrom := func(filename string, defval string, varcanons ...string) *BasicType {
		mklines := LoadMk(src.File(filename), NotEmpty)
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

		if trace.Tracing {
			trace.Stepf("Enum from default value: %s", defval)
		}
		return enum(defval)
	}

	// enumFromDirs reads the package directories from category, takes all
	// that have a single number in them (such as php72) and ranks them
	// from earliest to latest.
	//
	// If the directories cannot be found, the allowed values are taken
	// from defval. This is mostly useful when testing pkglint.
	enumFromDirs := func(category string, re regex.Pattern, repl string, defval string) *BasicType {
		versions := src.ListVersions(category, re, repl, false)
		if len(versions) == 0 {
			return enum(defval)
		}
		return enum(strings.Join(versions, " "))
	}

	// enumFromFiles reads the files from the given base directory,
	// filtering it through the regular expression and the replacement.
	//
	// If no files are found, the allowed values are taken
	// from defval. This should only happen in the pkglint tests.
	enumFromFiles := func(basedir string, re regex.Pattern, repl string, defval string) *BasicType {
		var relevant []string
		for _, filename := range dirglob(G.Pkgsrc.File(basedir)) {
			basename := path.Base(filename)
			if matches(basename, re) {
				relevant = append(relevant, replaceAll(basename, re, repl))
			}
		}
		if len(relevant) == 0 {
			return enum(defval)
		}
		return enum(strings.Join(relevant, " "))
	}

	compilers := enumFrom(
		"mk/compiler.mk",
		"ccache ccc clang distcc f2c gcc hp icc ido mipspro mipspro-ucode pcc sunpro xlc",
		"_COMPILERS",
		"_PSEUDO_COMPILERS")

	emacsVersions := enumFrom(
		"editors/emacs/modules.mk",
		"emacs25 emacs21 emacs21nox emacs20 xemacs215 xemacs215nox xemacs214 xemacs214nox",
		"_EMACS_VERSIONS_ALL")

	mysqlVersions := enumFrom(
		"mk/mysql.buildlink3.mk",
		"57 56 55 51 MARIADB55",
		"MYSQL_VERSIONS_ACCEPTED")

	pgsqlVersions := enumFrom(
		"mk/pgsql.buildlink3.mk",
		"10 96 95 94 93",
		"PGSQL_VERSIONS_ACCEPTED")

	jvms := enumFrom(
		"mk/java-vm.mk",
		"openjdk8 oracle-jdk8 openjdk7 sun-jdk7 jdk16 jdk15 kaffe",
		"_PKG_JVMS.*")

	// Last synced with mk/defaults/mk.conf revision 1.300 (fe3d998769f).
	usr("USE_CWRAPPERS", enum("yes no auto"))
	usr("ALLOW_VULNERABLE_PACKAGES", BtYes)
	usrlist("AUDIT_PACKAGES_FLAGS", BtShellWord)
	usrlist("MANINSTALL", enum("maninstall catinstall"))
	usr("MANZ", BtYes)
	usrlist("GZIP", BtShellWord)
	usr("MAKE_JOBS", BtInteger)
	usr("OBJHOSTNAME", BtYes)
	usr("OBJMACHINE", BtYes)
	usr("SIGN_PACKAGES", enum("gpg x509"))
	usr("X509_KEY", BtPathname)
	usr("X509_CERTIFICATE", BtPathname)
	usr("PATCH_DEBUG", BtYes)
	usr("PKG_COMPRESSION", enum("gzip bzip2 xz none"))
	usr("PKGSRC_LOCKTYPE", enum("none sleep once"))
	usr("PKGSRC_SLEEPSECS", BtInteger)
	usr("ABI", enum("32 64"))
	usr("PKG_DEVELOPER", BtYesNo)
	usr("USE_ABI_DEPENDS", BtYesNo)
	usr("PKG_REGISTER_SHELLS", enum("YES NO"))
	usrlist("PKGSRC_COMPILER", compilers)
	usr("PKGSRC_KEEP_BIN_PKGS", BtYesNo)
	usrlist("PKGSRC_MESSAGE_RECIPIENTS", BtMailAddress)
	usr("PKGSRC_SHOW_BUILD_DEFS", BtYesNo)
	usr("PKGSRC_RUN_TEST", BtYesNo)
	usr("PKGSRC_MKPIE", BtYesNo)
	usr("PKGSRC_MKREPRO", BtYesNo)
	usr("PKGSRC_USE_CTF", BtYesNo)
	usr("PKGSRC_USE_FORTIFY", enum("no weak strong"))
	usr("PKGSRC_USE_RELRO", enum("no partial full"))
	usr("PKGSRC_USE_SSP", enum("no yes strong all"))
	usr("PKGSRC_USE_STACK_CHECK", enum("no yes"))
	usr("PREFER.*", enum("pkgsrc native"))
	usrlist("PREFER_PKGSRC", BtIdentifier)
	usrlist("PREFER_NATIVE", BtIdentifier)
	usr("PREFER_NATIVE_PTHREADS", BtYesNo)
	usr("WRKOBJDIR", BtPathname)
	usr("LOCALBASE", BtPathname)
	usr("CROSSBASE", BtPathname)
	usr("VARBASE", BtPathname)

	// X11_TYPE and X11BASE may be used in buildlink3.mk as well, which the
	// standard sysload doesn't allow.
	acl("X11_TYPE", enum("modular native"),
		UserSettable,
		"*: use, use-loadtime")
	acl("X11BASE", BtPathname,
		UserSettable,
		"*: use, use-loadtime")

	usr("MOTIFBASE", BtPathname)
	usr("PKGINFODIR", BtPathname)
	usr("PKGMANDIR", BtPathname)
	usr("PKGGNUDIR", BtPathname)
	usr("BSDSRCDIR", BtPathname)
	usr("BSDXSRCDIR", BtPathname)
	usr("DISTDIR", BtPathname)
	usr("DIST_PATH", BtPathlist)
	usr("DEFAULT_VIEW", BtUnknown) // XXX: deprecate? pkgviews has been removed
	usr("FETCH_CMD", BtShellCommand)
	usr("FIX_SYSTEM_HEADERS", BtYes)
	usr("LIBTOOLIZE_PLIST", BtYesNo)
	usr("PKG_RESUME_TRANSFERS", BtYesNo)
	usr("PKG_SYSCONFBASE", BtPathname)
	usr("INIT_SYSTEM", enum("rc.d smf"))
	usr("RCD_SCRIPTS_DIR", BtPathname)
	usr("PACKAGES", BtPathname)
	usr("PASSIVE_FETCH", BtYes)
	usr("PATCH_FUZZ_FACTOR", enum("none -F0 -F1 -F2 -F3"))
	usrlist("ACCEPTABLE_LICENSES", BtIdentifier)
	usr("SPECIFIC_PKGS", BtYes)
	usrlist("SITE_SPECIFIC_PKGS", BtPkgPath)
	usrlist("HOST_SPECIFIC_PKGS", BtPkgPath)
	usrlist("GROUP_SPECIFIC_PKGS", BtPkgPath)
	usrlist("USER_SPECIFIC_PKGS", BtPkgPath)
	usr("FAILOVER_FETCH", BtYes)
	usrlist("MASTER_SORT", BtUnknown)
	usrlist("MASTER_SORT_REGEX", BtUnknown)
	usr("MASTER_SORT_RANDOM", BtYes)
	usr("PKG_FC", BtShellCommand)
	usrlist("IMAKEOPTS", BtShellWord)
	usr("PRE_ROOT_CMD", BtShellCommand)
	usr("SU_CMD", BtShellCommand)
	usr("SU_CMD_PATH_APPEND", BtPathlist)
	usr("FATAL_OBJECT_FMT_SKEW", BtYesNo)
	usr("WARN_NO_OBJECT_FMT", BtYesNo)
	usr("SMART_MESSAGES", BtYes)
	usrlist("BINPKG_SITES", BtURL)
	usrlist("BIN_INSTALL_FLAGS", BtShellWord)
	usr("LOCALPATCHES", BtPathname)

	usr("ACROREAD_FONTPATH", BtPathlist)
	usr("AMANDA_USER", BtUserGroupName)
	usr("AMANDA_TMP", BtPathname)
	usr("AMANDA_VAR", BtPathname)
	usr("APACHE_USER", BtUserGroupName)
	usr("APACHE_GROUP", BtUserGroupName)
	usrlist("APACHE_SUEXEC_CONFIGURE_ARGS", BtShellWord)
	usrlist("APACHE_SUEXEC_DOCROOT", BtPathname)
	usr("ARLA_CACHE", BtPathname)
	usr("BIND_DIR", BtPathname)
	usr("BIND_GROUP", BtUserGroupName)
	usr("BIND_USER", BtUserGroupName)
	usr("CACTI_GROUP", BtUserGroupName)
	usr("CACTI_USER", BtUserGroupName)
	usr("CANNA_GROUP", BtUserGroupName)
	usr("CANNA_USER", BtUserGroupName)
	usr("CDRECORD_CONF", BtPathname)
	usr("CLAMAV_GROUP", BtUserGroupName)
	usr("CLAMAV_USER", BtUserGroupName)
	usr("CLAMAV_DBDIR", BtPathname)
	usr("CONSERVER_DEFAULTHOST", BtIdentifier)
	usr("CONSERVER_DEFAULTPORT", BtInteger)
	usr("CUPS_GROUP", BtUserGroupName)
	usr("CUPS_USER", BtUserGroupName)
	usrlist("CUPS_SYSTEM_GROUPS", BtUserGroupName)
	usr("CYRUS_IDLE", enum("poll idled no"))
	usr("CYRUS_GROUP", BtUserGroupName)
	usr("CYRUS_USER", BtUserGroupName)
	usr("DAEMONTOOLS_LOG_USER", BtUserGroupName)
	usr("DAEMONTOOLS_GROUP", BtUserGroupName)
	usr("DBUS_GROUP", BtUserGroupName)
	usr("DBUS_USER", BtUserGroupName)
	usr("DEFANG_GROUP", BtUserGroupName)
	usr("DEFANG_USER", BtUserGroupName)
	usr("DEFANG_SPOOLDIR", BtPathname)
	usr("DEFAULT_IRC_SERVER", BtIdentifier)
	usr("DEFAULT_SERIAL_DEVICE", BtPathname)
	usr("DIALER_GROUP", BtUserGroupName)
	usr("DJBDNS_AXFR_USER", BtUserGroupName)
	usr("DJBDNS_CACHE_USER", BtUserGroupName)
	usr("DJBDNS_LOG_USER", BtUserGroupName)
	usr("DJBDNS_RBL_USER", BtUserGroupName)
	usr("DJBDNS_TINY_USER", BtUserGroupName)
	usr("DJBDNS_DJBDNS_GROUP", BtUserGroupName)
	usr("DT_LAYOUT", enum("US FI FR GER DV"))
	usrlist("ELK_GUI", enum("none xaw motif"))
	usr("EMACS_TYPE", emacsVersions)
	usr("EXIM_GROUP", BtUserGroupName)
	usr("EXIM_USER", BtUserGroupName)
	usrpkg("EXTRACT_USING", enum("bsdtar gtar nbtar pax"))
	usrlist("FETCH_BEFORE_ARGS", BtShellWord)
	usrlist("FETCH_AFTER_ARGS", BtShellWord)
	usrlist("FETCH_RESUME_ARGS", BtShellWord)
	usrlist("FETCH_OUTPUT_ARGS", BtShellWord)
	usrpkg("FETCH_USING", enum("auto curl custom fetch ftp manual wget"))
	usr("FLUXBOX_USE_XINERAMA", enum("YES NO"))
	usr("FLUXBOX_USE_KDE", enum("YES NO"))
	usr("FLUXBOX_USE_GNOME", enum("YES NO"))
	usr("FLUXBOX_USE_XFT", enum("YES NO"))
	usr("FOX_USE_XUNICODE", enum("YES NO"))
	usr("FREEWNN_USER", BtUserGroupName)
	usr("FREEWNN_GROUP", BtUserGroupName)
	usr("GAMES_USER", BtUserGroupName)
	usr("GAMES_GROUP", BtUserGroupName)
	usr("GAMEMODE", BtFileMode)
	usr("GAMEDIRMODE", BtFileMode)
	usr("GAMEDATAMODE", BtFileMode)
	usr("GAMEGRP", BtUserGroupName)
	usr("GAMEOWN", BtUserGroupName)
	usr("GRUB_NETWORK_CARDS", BtIdentifier)
	usr("GRUB_PRESET_COMMAND", enum("bootp dhcp rarp"))
	usrlist("GRUB_SCAN_ARGS", BtShellWord)
	usr("HASKELL_COMPILER", enum("ghc"))
	usr("HOWL_GROUP", BtUserGroupName)
	usr("HOWL_USER", BtUserGroupName)
	usr("ICECAST_CHROOTDIR", BtPathname)
	usr("ICECAST_CHUNKLEN", BtInteger)
	usr("ICECAST_SOURCE_BUFFSIZE", BtInteger)
	usr("IMAP_UW_CCLIENT_MBOX_FMT",
		enum("mbox mbx mh mmdf mtx mx news phile tenex unix"))
	usr("IMAP_UW_MAILSPOOLHOME", BtFileName)
	usr("IMDICTDIR", BtPathname)
	usr("INN_DATA_DIR", BtPathname)
	usr("INN_USER", BtUserGroupName)
	usr("INN_GROUP", BtUserGroupName)
	usr("IRCD_HYBRID_NICLEN", BtInteger)
	usr("IRCD_HYBRID_TOPICLEN", BtInteger)
	usr("IRCD_HYBRID_SYSLOG_EVENTS", BtUnknown)
	usr("IRCD_HYBRID_SYSLOG_FACILITY", BtIdentifier)
	usr("IRCD_HYBRID_MAXCONN", BtInteger)
	usr("IRCD_HYBRID_IRC_USER", BtUserGroupName)
	usr("IRCD_HYBRID_IRC_GROUP", BtUserGroupName)
	usr("IRRD_USE_PGP", enum("5 2"))
	usr("JABBERD_USER", BtUserGroupName)
	usr("JABBERD_GROUP", BtUserGroupName)
	usr("JABBERD_LOGDIR", BtPathname)
	usr("JABBERD_SPOOLDIR", BtPathname)
	usr("JABBERD_PIDDIR", BtPathname)
	usr("JAKARTA_HOME", BtPathname)
	usr("KERBEROS", BtYes)
	usr("KERMIT_SUID_UUCP", BtYes)
	usr("KJS_USE_PCRE", BtYes)
	usr("KNEWS_DOMAIN_FILE", BtPathname)
	usr("KNEWS_DOMAIN_NAME", BtIdentifier)
	usr("LIBDVDCSS_HOMEPAGE", BtHomepage)
	usrlist("LIBDVDCSS_MASTER_SITES", BtFetchURL)
	usr("LIBUSB_TYPE", enum("compat native"))
	usr("LATEX2HTML_ICONPATH", BtURL)
	usr("LEAFNODE_DATA_DIR", BtPathname)
	usr("LEAFNODE_USER", BtUserGroupName)
	usr("LEAFNODE_GROUP", BtUserGroupName)
	usrlist("LINUX_LOCALES", BtIdentifier)
	usr("MAILAGENT_DOMAIN", BtIdentifier)
	usr("MAILAGENT_EMAIL", BtMailAddress)
	usr("MAILAGENT_FQDN", BtIdentifier)
	usr("MAILAGENT_ORGANIZATION", BtUnknown)
	usr("MAJORDOMO_HOMEDIR", BtPathname)
	usrlist("MAKEINFO_ARGS", BtShellWord)
	usr("MECAB_CHARSET", BtIdentifier)
	usr("MEDIATOMB_GROUP", BtUserGroupName)
	usr("MEDIATOMB_USER", BtUserGroupName)
	usr("MIREDO_USER", BtUserGroupName)
	usr("MIREDO_GROUP", BtUserGroupName)
	usr("MLDONKEY_GROUP", BtUserGroupName)
	usr("MLDONKEY_HOME", BtPathname)
	usr("MLDONKEY_USER", BtUserGroupName)
	usr("MONOTONE_GROUP", BtUserGroupName)
	usr("MONOTONE_USER", BtUserGroupName)
	usr("MOTIF_TYPE", enum("motif openmotif lesstif dt"))
	usr("MOTIF_TYPE_DEFAULT", enum("motif openmotif lesstif dt"))
	usr("MTOOLS_ENABLE_FLOPPYD", BtYesNo)
	usr("MYSQL_USER", BtUserGroupName)
	usr("MYSQL_GROUP", BtUserGroupName)
	usr("MYSQL_DATADIR", BtPathname)
	usr("MYSQL_CHARSET", BtIdentifier)
	usrlist("MYSQL_EXTRA_CHARSET", BtIdentifier)
	usr("NAGIOS_GROUP", BtUserGroupName)
	usr("NAGIOS_USER", BtUserGroupName)
	usr("NAGIOSCMD_GROUP", BtUserGroupName)
	usr("NAGIOSDIR", BtPathname)
	usr("NBPAX_PROGRAM_PREFIX", BtUnknown)
	usr("NMH_EDITOR", BtIdentifier)
	usr("NMH_MTA", enum("smtp sendmail"))
	usr("NMH_PAGER", BtIdentifier)
	usr("NS_PREFERRED", enum("communicator navigator mozilla"))
	usr("NULLMAILER_USER", BtUserGroupName)
	usr("NULLMAILER_GROUP", BtUserGroupName)
	usr("OPENSSH_CHROOT", BtPathname)
	usr("OPENSSH_USER", BtUserGroupName)
	usr("OPENSSH_GROUP", BtUserGroupName)
	usr("P4USER", BtUserGroupName)
	usr("P4GROUP", BtUserGroupName)
	usr("P4ROOT", BtPathname)
	usr("P4PORT", BtInteger)
	usr("PALMOS_DEFAULT_SDK", enum("1 2 3.1 3.5"))
	usr("PAPERSIZE", enum("A4 Letter"))
	usr("PGGROUP", BtUserGroupName)
	usr("PGUSER", BtUserGroupName)
	usr("PGHOME", BtPathname)
	usr("PILRC_USE_GTK", BtYesNo)
	usr("PKG_JVM_DEFAULT", jvms)
	usr("POPTOP_USE_MPPE", BtYes)
	usr("PROCMAIL_MAILSPOOLHOME", BtFileName)
	// Comma-separated list of string or integer literals.
	usr("PROCMAIL_TRUSTED_IDS", BtUnknown)
	usr("PVM_SSH", BtPathname)
	usr("QMAILDIR", BtPathname)
	usr("QMAIL_ALIAS_USER", BtUserGroupName)
	usr("QMAIL_DAEMON_USER", BtUserGroupName)
	usr("QMAIL_LOG_USER", BtUserGroupName)
	usr("QMAIL_ROOT_USER", BtUserGroupName)
	usr("QMAIL_PASSWD_USER", BtUserGroupName)
	usr("QMAIL_QUEUE_USER", BtUserGroupName)
	usr("QMAIL_REMOTE_USER", BtUserGroupName)
	usr("QMAIL_SEND_USER", BtUserGroupName)
	usr("QMAIL_QMAIL_GROUP", BtUserGroupName)
	usr("QMAIL_NOFILES_GROUP", BtUserGroupName)
	usr("QMAIL_QFILTER_TMPDIR", BtPathname)
	usr("QMAIL_QUEUE_DIR", BtPathname)
	usr("QMAIL_QUEUE_EXTRA", BtMailAddress)
	usr("QPOPPER_FAC", BtIdentifier)
	usr("QPOPPER_USER", BtUserGroupName)
	usr("QPOPPER_SPOOL_DIR", BtPathname)
	usr("RASMOL_DEPTH", enum("8 16 32"))
	usr("RELAY_CTRL_DIR", BtPathname)
	usr("RPM_DB_PREFIX", BtPathname)
	usr("RSSH_SCP_PATH", BtPathname)
	usr("RSSH_SFTP_SERVER_PATH", BtPathname)
	usr("RSSH_CVS_PATH", BtPathname)
	usr("RSSH_RDIST_PATH", BtPathname)
	usr("RSSH_RSYNC_PATH", BtPathname)
	usrlist("SAWFISH_THEMES", BtFileName)
	usr("SCREWS_GROUP", BtUserGroupName)
	usr("SCREWS_USER", BtUserGroupName)
	usr("SDIST_PAWD", enum("pawd pwd"))
	usrlist("SERIAL_DEVICES", BtPathname)
	usr("SILC_CLIENT_WITH_PERL", BtYesNo)
	usr("SNIPROXY_USER", BtUserGroupName)
	usr("SNIPROXY_GROUP", BtUserGroupName)
	usr("SSH_SUID", BtYesNo)
	usr("SSYNC_PAWD", enum("pawd pwd"))
	usr("SUSE_PREFER", enum("13.1 12.1 10.0")) // TODO: extract
	usr("TEXMFSITE", BtPathname)
	usr("THTTPD_LOG_FACILITY", BtIdentifier)
	usr("UCSPI_SSL_USER", BtUserGroupName)
	usr("UCSPI_SSL_GROUP", BtUserGroupName)
	usr("UNPRIVILEGED", BtYesNo)
	usr("USE_CROSS_COMPILE", BtYesNo)
	usr("USERPPP_GROUP", BtUserGroupName)
	usr("UUCP_GROUP", BtUserGroupName)
	usr("UUCP_USER", BtUserGroupName)
	usrlist("VIM_EXTRA_OPTS", BtShellWord)
	usr("WCALC_HTMLDIR", BtPathname)
	usr("WCALC_HTMLPATH", BtPathname) // URL path
	usr("WCALC_CGIDIR", BtPrefixPathname)
	usr("WCALC_CGIPATH", BtPathname) // URL path
	usrlist("WDM_MANAGERS", BtIdentifier)
	usr("X10_PORT", BtPathname)
	usrpkg("XAW_TYPE", enum("standard 3d xpm neXtaw"))
	usr("XLOCK_DEFAULT_MODE", BtIdentifier)
	usr("ZSH_STATIC", BtYes)

	// some other variables, sorted alphabetically

	// TODO: Instead of grouping them alphabetically, group them
	//  by topic, like clean, fetch, patch, configure, build, install,
	//  subst, buildlink3, checks. This will make them easier to
	//  analyze and align the permissions.

	sysload(".CURDIR", BtPathname)
	sysload(".IMPSRC", BtPathname)
	sys(".TARGET", BtPathname)
	sys("@", BtPathname)
	pkglistbl3("ALL_ENV", BtShellWord)
	pkg("ALTERNATIVES_FILE", BtFileName)
	pkglist("ALTERNATIVES_SRC", BtPathname)
	pkg("APACHE_MODULE", BtYes)
	sys("AR", BtShellCommand)
	sys("AS", BtShellCommand)
	pkglist("AUTOCONF_REQD", BtVersion)
	pkglist("AUTOMAKE_OVERRIDE", BtPathmask)
	pkglist("AUTOMAKE_REQD", BtVersion)
	pkg("AUTO_MKDIRS", BtYesNo)
	usr("BATCH", BtYes)
	usr("BDB185_DEFAULT", BtUnknown)
	sys("BDBBASE", BtPathname)
	pkglist("BDB_ACCEPTED", enum("db1 db2 db3 db4 db5 db6"))
	usr("BDB_DEFAULT", enum("db1 db2 db3 db4 db5 db6"))
	syslist("BDB_LIBS", BtLdFlag)
	sys("BDB_TYPE", enum("db1 db2 db3 db4 db5 db6"))
	syslist("BIGENDIANPLATFORMS", BtMachinePlatformPattern)
	sys("BINGRP", BtUserGroupName)
	sys("BINMODE", BtFileMode)
	sys("BINOWN", BtUserGroupName)
	pkglist("BOOTSTRAP_DEPENDS", BtDependencyWithPath)
	pkg("BOOTSTRAP_PKG", BtYesNo)
	// BROKEN should better be a list of messages instead of a simple string.
	pkgappendrat("BROKEN", BtMessage)
	pkg("BROKEN_GETTEXT_DETECTION", BtYesNo)
	pkglistrat("BROKEN_EXCEPT_ON_PLATFORM", BtMachinePlatformPattern)
	pkglistrat("BROKEN_ON_PLATFORM", BtMachinePlatformPattern)
	syslist("BSD_MAKE_ENV", BtShellWord)
	// TODO: Align the permissions of the various BUILDLINK_*.* variables with each other.
	acllist("BUILDLINK_ABI_DEPENDS.*", BtDependency,
		PackageSettable,
		"buildlink3.mk, builtin.mk: append, use-loadtime",
		"*: append")
	acllist("BUILDLINK_API_DEPENDS.*", BtDependency,
		PackageSettable,
		"buildlink3.mk, builtin.mk: append, use-loadtime",
		"*: append")
	acl("BUILDLINK_AUTO_DIRS.*", BtYesNo,
		PackageSettable,
		"buildlink3.mk: append",
		"Makefile: set")
	syslist("BUILDLINK_CFLAGS", BtCFlag)
	bl3list("BUILDLINK_CFLAGS.*", BtCFlag)
	acl("BUILDLINK_CONTENTS_FILTER.*", BtShellCommand,
		PackageSettable,
		"buildlink3.mk: set")
	syslist("BUILDLINK_CPPFLAGS", BtCFlag)
	bl3list("BUILDLINK_CPPFLAGS.*", BtCFlag)
	acllist("BUILDLINK_DEPENDS", BtIdentifier,
		PackageSettable,
		"buildlink3.mk: append")
	acllist("BUILDLINK_DEPMETHOD.*", BtBuildlinkDepmethod,
		PackageSettable,
		"buildlink3.mk: default, append, use",
		"Makefile, Makefile.*, *.mk: default, set, append")
	acl("BUILDLINK_DIR", BtPathname,
		PackageSettable,
		"*: use")
	bl3list("BUILDLINK_FILES.*", BtPathmask)
	pkgbl3("BUILDLINK_FILES_CMD.*", BtShellCommand)
	acllist("BUILDLINK_INCDIRS.*", BtPathname,
		PackageSettable,
		"buildlink3.mk: default, append",
		"Makefile, Makefile.*, *.mk: use")
	acl("BUILDLINK_JAVA_PREFIX.*", BtPathname,
		PackageSettable,
		"buildlink3.mk: set, use")
	acllist("BUILDLINK_LDADD.*", BtLdFlag,
		PackageSettable,
		"builtin.mk: default, set, append, use",
		"buildlink3.mk: append, use",
		"Makefile, Makefile.*, *.mk: use")
	acllist("BUILDLINK_LDFLAGS", BtLdFlag,
		PackageSettable,
		"*: use")
	bl3list("BUILDLINK_LDFLAGS.*", BtLdFlag)
	acllist("BUILDLINK_LIBDIRS.*", BtPathname,
		PackageSettable,
		"buildlink3.mk, builtin.mk: append",
		"Makefile, Makefile.*, *.mk: use")
	acllist("BUILDLINK_LIBS.*", BtLdFlag,
		PackageSettable,
		"buildlink3.mk: append",
		"Makefile, Makefile.*, *.mk: set, append, use")
	acllist("BUILDLINK_PASSTHRU_DIRS", BtPathname,
		PackageSettable,
		"Makefile, Makefile.*, *.mk: append")
	acllist("BUILDLINK_PASSTHRU_RPATHDIRS", BtPathname,
		PackageSettable,
		"Makefile, Makefile.*, *.mk: append")
	acl("BUILDLINK_PKGSRCDIR.*", BtRelativePkgDir,
		PackageSettable,
		"buildlink3.mk: default, use-loadtime")
	acl("BUILDLINK_PREFIX.*", BtPathname,
		PackageSettable,
		"builtin.mk: set, use",
		"Makefile, Makefile.*, *.mk: use")
	acllist("BUILDLINK_RPATHDIRS.*", BtPathname,
		PackageSettable,
		"buildlink3.mk: append")
	acllist("BUILDLINK_TARGETS", BtIdentifier,
		PackageSettable,
		"Makefile, Makefile.*, *.mk: append")
	acl("BUILDLINK_FNAME_TRANSFORM.*", BtSedCommands,
		PackageSettable,
		"Makefile, buildlink3.mk, builtin.mk, options.mk: append")
	acllist("BUILDLINK_TRANSFORM", BtWrapperTransform,
		PackageSettable,
		"*: append")
	acllist("BUILDLINK_TRANSFORM.*", BtWrapperTransform,
		PackageSettable,
		"*: append")
	acllist("BUILDLINK_TREE", BtIdentifier,
		PackageSettable,
		"buildlink3.mk: append")
	acl("BUILDLINK_X11_DIR", BtPathname,
		PackageSettable,
		"*: use")
	acllist("BUILD_DEFS", BtVariableName,
		PackageSettable,
		"Makefile, Makefile.*, *.mk: append")
	pkglist("BUILD_DEFS_EFFECTS", BtVariableName)
	pkglistbl3("BUILD_DEPENDS", BtDependencyWithPath)
	pkglist("BUILD_DIRS", BtWrksrcSubdirectory)
	pkglist("BUILD_ENV", BtShellWord)
	sys("BUILD_MAKE_CMD", BtShellCommand)
	pkglist("BUILD_MAKE_FLAGS", BtShellWord)
	pkglist("BUILD_TARGET", BtIdentifier)
	pkglist("BUILD_TARGET.*", BtIdentifier)
	pkg("BUILD_USES_MSGFMT", BtYes)
	acl("BUILTIN_PKG", BtIdentifier,
		PackageSettable,
		"builtin.mk: set, use, use-loadtime",
		"Makefile, Makefile.*, *.mk: use, use-loadtime")
	acl("BUILTIN_PKG.*", BtPkgName,
		PackageSettable,
		"builtin.mk: set, use, use-loadtime")
	pkglistbl3("BUILTIN_FIND_FILES_VAR", BtVariableName)
	pkglistbl3("BUILTIN_FIND_FILES.*", BtPathname)
	acl("BUILTIN_FIND_GREP.*", BtUnknown,
		PackageSettable,
		"builtin.mk: set")
	acllist("BUILTIN_FIND_HEADERS_VAR", BtVariableName,
		PackageSettable,
		"builtin.mk: set")
	acllist("BUILTIN_FIND_HEADERS.*", BtPathname,
		PackageSettable,
		"builtin.mk: set")
	acllist("BUILTIN_FIND_LIBS", BtPathname,
		PackageSettable,
		"builtin.mk: set")
	sys("BUILTIN_X11_TYPE", BtUnknown)
	sys("BUILTIN_X11_VERSION", BtUnknown)
	pkglist("CATEGORIES", BtCategory)
	sysload("CC_VERSION", BtMessage)
	sysload("CC", BtShellCommand)
	pkglistbl3("CFLAGS", BtCFlag)   // may also be changed by the user
	pkglistbl3("CFLAGS.*", BtCFlag) // may also be changed by the user
	acl("CHECK_BUILTIN", BtYesNo,
		PackageSettable,
		"builtin.mk: default",
		"Makefile: set")
	acl("CHECK_BUILTIN.*", BtYesNo,
		PackageSettable,
		"Makefile, options.mk, buildlink3.mk: set",
		"builtin.mk: default, use-loadtime",
		"*: use-loadtime")
	pkglist("CHECK_FILES_SKIP", BtBasicRegularExpression)
	pkg("CHECK_FILES_SUPPORTED", BtYesNo)
	usr("CHECK_HEADERS", BtYesNo)
	pkglist("CHECK_HEADERS_SKIP", BtPathmask)
	usr("CHECK_INTERPRETER", BtYesNo)
	pkglist("CHECK_INTERPRETER_SKIP", BtPathmask)
	usr("CHECK_PERMS", BtYesNo)
	pkglist("CHECK_PERMS_SKIP", BtPathmask)
	usr("CHECK_PORTABILITY", BtYesNo)
	pkglist("CHECK_PORTABILITY_SKIP", BtPathmask)
	usr("CHECK_RELRO", BtYesNo)
	pkglist("CHECK_RELRO_SKIP", BtPathmask)
	pkg("CHECK_RELRO_SUPPORTED", BtYesNo)
	pkg("CHECK_SHLIBS", BtYesNo)
	pkglist("CHECK_SHLIBS_SKIP", BtPathmask)
	pkg("CHECK_SHLIBS_SUPPORTED", BtYesNo)
	pkglist("CHECK_WRKREF_SKIP", BtPathmask)
	pkg("CMAKE_ARG_PATH", BtPathname)
	pkglist("CMAKE_ARGS", BtShellWord)
	pkglist("CMAKE_ARGS.*", BtShellWord)
	pkglist("CMAKE_DEPENDENCIES_REWRITE", BtPathmask) // Relative to WRKSRC
	pkglist("CMAKE_MODULE_PATH_OVERRIDE", BtPathmask) // Relative to WRKSRC
	pkg("CMAKE_PKGSRC_BUILD_FLAGS", BtYesNo)
	pkglist("CMAKE_PREFIX_PATH", BtPathmask)
	pkg("CMAKE_USE_GNU_INSTALL_DIRS", BtYesNo)
	pkg("CMAKE_INSTALL_PREFIX", BtPathname) // The default is ${PREFIX}.
	pkgappend("COMMENT", BtComment)
	sys("COMPILE.*", BtShellCommand)
	sys("COMPILER_RPATH_FLAG", enum("-Wl,-rpath"))
	pkglist("CONFIGURE_ARGS", BtShellWord)
	pkglist("CONFIGURE_ARGS.*", BtShellWord)
	pkglist("CONFIGURE_DIRS", BtWrksrcSubdirectory)
	pkglistbl3("CONFIGURE_ENV", BtShellWord)
	pkglistbl3("CONFIGURE_ENV.*", BtShellWord)
	pkg("CONFIGURE_HAS_INFODIR", BtYesNo)
	pkg("CONFIGURE_HAS_LIBDIR", BtYesNo)
	pkg("CONFIGURE_HAS_MANDIR", BtYesNo)
	pkg("CONFIGURE_SCRIPT", BtPathname)
	pkglist("CONFIG_GUESS_OVERRIDE", BtPathmask)
	pkglist("CONFIG_STATUS_OVERRIDE", BtPathmask)
	pkg("CONFIG_SHELL", BtPathname)
	pkglist("CONFIG_SUB_OVERRIDE", BtPathmask)
	pkglist("CONFLICTS", BtDependency)
	pkgappend("CONF_FILES", BtConfFiles)
	pkg("CONF_FILES_MODE", enum("0644 0640 0600 0400"))
	pkglist("CONF_FILES_PERMS", BtPerms)
	sys("COPY", enum("-c")) // The flag that tells ${INSTALL} to copy a file
	sys("CPP", BtShellCommand)
	pkglistbl3("CPPFLAGS", BtCFlag)
	pkglistbl3("CPPFLAGS.*", BtCFlag)
	sys("CXX", BtShellCommand)
	pkglistbl3("CXXFLAGS", BtCFlag)
	pkglistbl3("CXXFLAGS.*", BtCFlag)
	pkglistbl3("CWRAPPERS_APPEND.*", BtShellWord)
	syslist("DEFAULT_DISTFILES", BtFetchURL) // From mk/fetch/bsd.fetch-vars.mk.
	pkglist("DEINSTALL_SRC", BtPathname)
	pkglist("DEINSTALL_TEMPLATES", BtPathname)
	sys("DELAYED_ERROR_MSG", BtShellCommand)
	sys("DELAYED_WARNING_MSG", BtShellCommand)
	pkglistbl3("DEPENDS", BtDependencyWithPath)
	usrlist("DEPENDS_TARGET", BtIdentifier)
	pkglist("DESCR_SRC", BtPathname)
	sys("DESTDIR", BtPathname)
	pkg("DESTDIR_VARNAME", BtVariableName)
	sys("DEVOSSAUDIO", BtPathname)
	sys("DEVOSSSOUND", BtPathname)
	pkglist("DISTFILES", BtFileName)
	pkg("DISTINFO_FILE", BtRelativePkgPath)
	pkg("DISTNAME", BtFileName)
	pkg("DIST_SUBDIR", BtPathname)
	pkglist("DJB_BUILD_ARGS", BtShellWord)
	pkglist("DJB_BUILD_TARGETS", BtIdentifier)
	pkgappend("DJB_CONFIG_CMDS", BtShellCommands)
	pkglist("DJB_CONFIG_DIRS", BtWrksrcSubdirectory)
	pkg("DJB_CONFIG_HOME", BtFileName)
	pkg("DJB_CONFIG_PREFIX", BtPathname)
	pkglist("DJB_INSTALL_TARGETS", BtIdentifier)
	pkg("DJB_MAKE_TARGETS", BtYesNo)
	pkg("DJB_RESTRICTED", BtYesNo)
	pkg("DJB_SLASHPACKAGE", BtYesNo)
	pkg("DLOPEN_REQUIRE_PTHREADS", BtYesNo)
	pkg("DL_AUTO_VARS", BtYes)
	acllist("DL_LIBS", BtLdFlag,
		PackageSettable,
		"*: append, use")
	sys("DOCOWN", BtUserGroupName)
	sys("DOCGRP", BtUserGroupName)
	sys("DOCMODE", BtFileMode)
	sys("DOWNLOADED_DISTFILE", BtPathname)
	sys("DO_NADA", BtShellCommand)
	pkg("DYNAMIC_SITES_CMD", BtShellCommand)
	pkg("DYNAMIC_SITES_SCRIPT", BtPathname)
	sysbl3("ECHO", BtShellCommand)
	sysbl3("ECHO_MSG", BtShellCommand)
	sysbl3("ECHO_N", BtShellCommand)
	pkg("EGDIR", BtPathname) // Not defined anywhere but used in many places like this.
	sys("EMACS_BIN", BtPathname)
	sys("EMACS_ETCPREFIX", BtPathname)
	sys("EMACS_FLAVOR", enum("emacs xemacs"))
	sys("EMACS_INFOPREFIX", BtPathname)
	sys("EMACS_LISPPREFIX", BtPathname)
	pkglistbl3("EMACS_MODULES", BtIdentifier)
	sys("EMACS_PKGNAME_PREFIX", BtIdentifier) // Or the empty string.
	pkglist("EMACS_VERSIONS_ACCEPTED", emacsVersions)
	sys("EMACS_VERSION_MAJOR", BtInteger)
	sys("EMACS_VERSION_MINOR", BtInteger)
	pkglistrat("EMACS_VERSION_REQD", emacsVersions)
	sys("EMULDIR", BtPathname)
	sys("EMULSUBDIR", BtPathname)
	sys("OPSYS_EMULDIR", BtPathname)
	sys("EMULSUBDIRSLASH", BtPathname)
	sys("EMUL_ARCH", enum("arm i386 m68k none ns32k sparc vax x86_64"))
	sys("EMUL_DISTRO", BtIdentifier)
	sys("EMUL_IS_NATIVE", BtYes)
	pkglist("EMUL_MODULES.*", BtIdentifier)
	sys("EMUL_OPSYS", enum("darwin freebsd hpux irix linux osf1 solaris sunos none"))
	pkg("EMUL_PKG_FMT", enum("plain rpm"))
	usr("EMUL_PLATFORM", BtEmulPlatform)
	pkglist("EMUL_PLATFORMS", BtEmulPlatform)
	usrlist("EMUL_PREFER", BtEmulPlatform)
	pkglist("EMUL_REQD", BtDependency)
	usr("EMUL_TYPE.*", enum("native builtin suse suse-10.0 suse-12.1 suse-13.1"))
	sys("ERROR_CAT", BtShellCommand)
	sys("ERROR_MSG", BtShellCommand)
	syslist("EXPORT_SYMBOLS_LDFLAGS", BtLdFlag)
	sys("EXTRACT_CMD", BtShellCommand)
	pkg("EXTRACT_DIR", BtPathname)
	pkg("EXTRACT_DIR.*", BtPathname)
	pkglist("EXTRACT_ELEMENTS", BtPathmask)
	pkglist("EXTRACT_ENV", BtShellWord)
	pkglist("EXTRACT_ONLY", BtPathname)
	pkglist("EXTRACT_OPTS", BtShellWord)
	pkglist("EXTRACT_OPTS_BIN", BtShellWord)
	pkglist("EXTRACT_OPTS_LHA", BtShellWord)
	pkglist("EXTRACT_OPTS_PAX", BtShellWord)
	pkglist("EXTRACT_OPTS_RAR", BtShellWord)
	pkglist("EXTRACT_OPTS_TAR", BtShellWord)
	pkglist("EXTRACT_OPTS_ZIP", BtShellWord)
	pkglist("EXTRACT_OPTS_ZOO", BtShellWord)
	pkg("EXTRACT_SUFX", BtDistSuffix)
	sys("FAIL_MSG", BtShellCommand)
	sys("FAMBASE", BtPathname)
	pkglist("FAM_ACCEPTED", enum("fam gamin"))
	usr("FAM_DEFAULT", enum("fam gamin"))
	sys("FAM_TYPE", enum("fam gamin"))
	pkglist("FETCH_MESSAGE", BtShellWord)
	pkgload("FILESDIR", BtRelativePkgPath)
	pkglist("FILES_SUBST", BtShellWord)
	syslist("FILES_SUBST_SED", BtShellWord)
	pkglist("FIX_RPATH", BtVariableName)
	pkglistrat("FLEX_REQD", BtVersion)
	pkglist("FONTS_DIRS.*", BtPathname)
	syslist("GAMEDATA_PERMS", BtPerms)
	syslist("GAMEDIR_PERMS", BtPerms)
	pkglistbl3rat("GCC_REQD", BtGccReqd)
	pkgappend("GENERATE_PLIST", BtShellCommands)
	pkg("GITHUB_PROJECT", BtIdentifier)
	pkg("GITHUB_TAG", BtIdentifier)
	pkg("GITHUB_RELEASE", BtFileName)
	pkg("GITHUB_TYPE", enum("tag release"))
	pkgrat("GMAKE_REQD", BtVersion)
	// Some packages need to set GNU_ARCH.i386 to either i486 or i586.
	pkg("GNU_ARCH.*", BtIdentifier)
	// GNU_CONFIGURE needs to be tested in some buildlink3.mk files,
	// such as lang/vala.
	acl("GNU_CONFIGURE", BtYes,
		PackageSettable,
		"buildlink3.mk: none",
		"builtin.mk: use, use-loadtime",
		"Makefile, Makefile.*, *.mk: default, set, use, use-loadtime")
	pkg("GNU_CONFIGURE_INFODIR", BtPathname)
	pkg("GNU_CONFIGURE_LIBDIR", BtPathname)
	pkg("GNU_CONFIGURE_LIBSUBDIR", BtPathname)
	pkg("GNU_CONFIGURE_MANDIR", BtPathname)
	pkg("GNU_CONFIGURE_PREFIX", BtPathname)
	pkg("GOPATH", BtPathname)
	pkgload("HAS_CONFIGURE", BtYes)
	pkglist("HEADER_TEMPLATES", BtPathname)
	pkg("HOMEPAGE", BtHomepage)
	pkg("ICON_THEMES", BtYes)
	acl("IGNORE_PKG.*", BtYes,
		PackageSettable,
		"*: set, use-loadtime")
	sys("IMAKE", BtShellCommand)
	pkglistbl3rat("INCOMPAT_CURSES", BtMachinePlatformPattern)
	sys("INFO_DIR", BtPathname) // relative to PREFIX
	pkg("INFO_FILES", BtYes)
	sys("INSTALL", BtShellCommand)
	pkglist("INSTALLATION_DIRS", BtPrefixPathname)
	pkg("INSTALLATION_DIRS_FROM_PLIST", BtYes)
	sys("INSTALL_DATA", BtShellCommand)
	sys("INSTALL_DATA_DIR", BtShellCommand)
	pkglist("INSTALL_DIRS", BtWrksrcSubdirectory)
	pkglist("INSTALL_ENV", BtShellWord)
	pkg("INSTALL_FILE", BtPathname)
	sys("INSTALL_GAME", BtShellCommand)
	sys("INSTALL_GAME_DATA", BtShellCommand)
	sys("INSTALL_LIB", BtShellCommand)
	sys("INSTALL_LIB_DIR", BtShellCommand)
	pkglist("INSTALL_MAKE_FLAGS", BtShellWord)
	sys("INSTALL_MAN", BtShellCommand)
	sys("INSTALL_MAN_DIR", BtShellCommand)
	sys("INSTALL_PROGRAM", BtShellCommand)
	sys("INSTALL_PROGRAM_DIR", BtShellCommand)
	sys("INSTALL_SCRIPT", BtShellCommand)
	syslist("INSTALL_SCRIPTS_ENV", BtShellWord)
	sys("INSTALL_SCRIPT_DIR", BtShellCommand)
	pkglist("INSTALL_SRC", BtPathname)
	pkglist("INSTALL_TARGET", BtIdentifier)
	pkglist("INSTALL_TEMPLATES", BtPathname)
	pkgload("INSTALL_UNSTRIPPED", BtYesNo)
	pkglist("INTERACTIVE_STAGE", enum("fetch extract configure build test install"))
	acl("IS_BUILTIN.*", BtYesNoIndirectly,
		PackageSettable,
		// These two differ from the standard,
		// they are needed for devel/ncursesw.
		"buildlink3.mk: use, use-loadtime",
		// The "set" differs from the standard sys.
		"builtin.mk: set, use, use-loadtime",
		"Makefile, Makefile.*, *.mk: default, set, use, use-loadtime")
	sys("JAVA_BINPREFIX", BtPathname)
	pkg("JAVA_CLASSPATH", BtShellWord)
	pkg("JAVA_HOME", BtPathname)
	pkg("JAVA_NAME", BtFileName)
	pkglist("JAVA_UNLIMIT", enum("cmdsize datasize stacksize"))
	pkglist("JAVA_WRAPPERS", BtFileName)
	pkg("JAVA_WRAPPER_BIN.*", BtPathname)
	sys("KRB5BASE", BtPathname)
	pkglist("KRB5_ACCEPTED", enum("heimdal mit-krb5"))
	usr("KRB5_DEFAULT", enum("heimdal mit-krb5"))
	sys("KRB5_TYPE", BtIdentifier)
	sys("LD", BtShellCommand)
	pkglistbl3("LDFLAGS", BtLdFlag)       // May also be changed by the user.
	pkglistbl3("LDFLAGS.*", BtLdFlag)     // May also be changed by the user.
	sysload("LIBABISUFFIX", BtIdentifier) // Can also be empty.
	sys("LIBGRP", BtUserGroupName)
	sys("LIBMODE", BtFileMode)
	sys("LIBOWN", BtUserGroupName)
	sys("LIBOSSAUDIO", BtPathname)
	pkglist("LIBS", BtLdFlag)
	pkglist("LIBS.*", BtLdFlag)
	sys("LIBTOOL", BtShellCommand)
	pkglist("LIBTOOL_OVERRIDE", BtPathmask)
	pkglistrat("LIBTOOL_REQD", BtVersion)
	pkgappend("LICENCE", BtLicense)
	pkgappend("LICENSE", BtLicense)
	pkg("LICENSE_FILE", BtPathname)
	sys("LINK.*", BtShellCommand)
	sys("LINKER_RPATH_FLAG", BtShellWord)
	syslist("LITTLEENDIANPLATFORMS", BtMachinePlatformPattern)
	sys("LOWER_OPSYS", BtIdentifier)
	sys("LOWER_VENDOR", BtIdentifier)
	syslist("LP64PLATFORMS", BtMachinePlatformPattern)
	pkglist("LTCONFIG_OVERRIDE", BtPathmask)
	sysload("MACHINE_ARCH", enumMachineArch)
	sysload("MACHINE_GNU_ARCH", enumMachineGnuArch)
	sysload("MACHINE_GNU_PLATFORM", BtMachineGnuPlatform)
	sysload("MACHINE_PLATFORM", BtMachinePlatform)
	pkg("MAINTAINER", BtMailAddress)
	sysload("MAKE", BtShellCommand)
	pkglist("MAKEFLAGS", BtShellWord)
	pkglistbl3("MAKEVARS", BtVariableName)
	pkglist("MAKE_DIRS", BtPathname)
	pkglist("MAKE_DIRS_PERMS", BtPerms)
	pkglistbl3("MAKE_ENV", BtShellWord)
	pkglistbl3("MAKE_ENV.*", BtShellWord)
	pkg("MAKE_FILE", BtPathname)
	pkglist("MAKE_FLAGS", BtShellWord)
	pkglist("MAKE_FLAGS.*", BtShellWord)
	pkg("MAKE_JOBS_SAFE", BtYesNo)
	pkg("MAKE_PROGRAM", BtShellCommand)
	pkg("MANCOMPRESSED", BtYesNo)
	pkg("MANCOMPRESSED_IF_MANZ", BtYes)
	sys("MANGRP", BtUserGroupName)
	sys("MANMODE", BtFileMode)
	sys("MANOWN", BtUserGroupName)
	pkglist("MASTER_SITES", BtFetchURL)
	// TODO: Extract the MASTER_SITE_* definitions from mk/fetch/sites.mk
	//  instead of listing them here.
	syslist("MASTER_SITE_APACHE", BtFetchURL)
	syslist("MASTER_SITE_BACKUP", BtFetchURL)
	syslist("MASTER_SITE_CRATESIO", BtFetchURL)
	syslist("MASTER_SITE_CYGWIN", BtFetchURL)
	syslist("MASTER_SITE_DEBIAN", BtFetchURL)
	syslist("MASTER_SITE_FREEBSD", BtFetchURL)
	syslist("MASTER_SITE_FREEBSD_LOCAL", BtFetchURL)
	syslist("MASTER_SITE_GENTOO", BtFetchURL)
	syslist("MASTER_SITE_GITHUB", BtFetchURL)
	syslist("MASTER_SITE_GNOME", BtFetchURL)
	syslist("MASTER_SITE_GNU", BtFetchURL)
	syslist("MASTER_SITE_GNUSTEP", BtFetchURL)
	syslist("MASTER_SITE_IFARCHIVE", BtFetchURL)
	syslist("MASTER_SITE_HASKELL_HACKAGE", BtFetchURL)
	syslist("MASTER_SITE_KDE", BtFetchURL)
	syslist("MASTER_SITE_LOCAL", BtFetchURL)
	syslist("MASTER_SITE_MOZILLA", BtFetchURL)
	syslist("MASTER_SITE_MOZILLA_ALL", BtFetchURL)
	syslist("MASTER_SITE_MOZILLA_ESR", BtFetchURL)
	syslist("MASTER_SITE_MYSQL", BtFetchURL)
	syslist("MASTER_SITE_NETLIB", BtFetchURL)
	syslist("MASTER_SITE_OPENBSD", BtFetchURL)
	syslist("MASTER_SITE_OPENOFFICE", BtFetchURL)
	syslist("MASTER_SITE_OSDN", BtFetchURL)
	syslist("MASTER_SITE_PERL_CPAN", BtFetchURL)
	syslist("MASTER_SITE_PGSQL", BtFetchURL)
	syslist("MASTER_SITE_PYPI", BtFetchURL)
	syslist("MASTER_SITE_R_CRAN", BtFetchURL)
	syslist("MASTER_SITE_RUBYGEMS", BtFetchURL)
	syslist("MASTER_SITE_SOURCEFORGE", BtFetchURL)
	syslist("MASTER_SITE_SUNSITE", BtFetchURL)
	syslist("MASTER_SITE_SUSE", BtFetchURL)
	syslist("MASTER_SITE_TEX_CTAN", BtFetchURL)
	syslist("MASTER_SITE_XCONTRIB", BtFetchURL)
	syslist("MASTER_SITE_XEMACS", BtFetchURL)
	syslist("MASTER_SITE_XORG", BtFetchURL)
	pkglist("MESSAGE_SRC", BtPathname)
	pkglist("MESSAGE_SUBST", BtShellWord)
	pkg("META_PACKAGE", BtYes)
	syslist("MISSING_FEATURES", BtIdentifier)
	pkglist("MYSQL_VERSIONS_ACCEPTED", mysqlVersions)
	usr("MYSQL_VERSION_DEFAULT", BtVersion)
	sys("NATIVE_CC", BtShellCommand) // See mk/platform/tools.NetBSD.mk (and some others).
	sys("NM", BtShellCommand)
	sys("NONBINMODE", BtFileMode)
	pkglistrat("NOT_FOR_COMPILER", compilers)
	pkglistrat("NOT_FOR_BULK_PLATFORM", BtMachinePlatformPattern)
	pkglistrat("NOT_FOR_PLATFORM", BtMachinePlatformPattern)
	pkgrat("NOT_FOR_UNPRIVILEGED", BtYesNo)
	pkglistrat("NOT_PAX_ASLR_SAFE", BtPathmask)
	pkglistrat("NOT_PAX_MPROTECT_SAFE", BtPathmask)
	pkg("NO_BIN_ON_CDROM", BtRestricted)
	pkg("NO_BIN_ON_FTP", BtRestricted)
	pkgload("NO_BUILD", BtYes)
	pkg("NO_CHECKSUM", BtYes)
	pkg("NO_CONFIGURE", BtYes)
	pkg("NO_EXPORT_CPP", BtYes)
	pkg("NO_EXTRACT", BtYes)
	pkg("NO_INSTALL_MANPAGES", BtYes) // only has an effect for Imake packages.
	pkg("NO_PKGTOOLS_REQD_CHECK", BtYes)
	pkg("NO_SRC_ON_CDROM", BtRestricted)
	pkg("NO_SRC_ON_FTP", BtRestricted)
	sysload("OBJECT_FMT", enum("COFF ECOFF ELF SOM XCOFF Mach-O PE a.out"))
	pkglistrat("ONLY_FOR_COMPILER", compilers)
	pkglistrat("ONLY_FOR_PLATFORM", BtMachinePlatformPattern)
	pkgrat("ONLY_FOR_UNPRIVILEGED", BtYesNo)
	sysload("OPSYS", enumFromFiles("mk/platform", `(.*)\.mk$`, "$1",
		"Cygwin DragonFly FreeBSD Linux NetBSD SunOS"))
	pkglistbl3("OPSYSVARS", BtVariableName)
	pkg("OSVERSION_SPECIFIC", BtYes)
	sysload("OS_VERSION", BtVersion)
	sysload("OSX_VERSION", BtVersion) // See mk/platform/Darwin.mk.
	pkg("OVERRIDE_DIRDEPTH*", BtInteger)
	pkg("OVERRIDE_GNU_CONFIG_SCRIPTS", BtYes)
	pkg("OWNER", BtMailAddress)
	pkglist("OWN_DIRS", BtPathname)
	pkglist("OWN_DIRS_PERMS", BtPerms)
	sys("PAMBASE", BtPathname)
	usr("PAM_DEFAULT", enum("linux-pam openpam solaris-pam"))
	pkgload("PATCHDIR", BtRelativePkgPath)
	pkglist("PATCHFILES", BtFileName)
	pkglist("PATCH_ARGS", BtShellWord)
	pkglist("PATCH_DIST_ARGS", BtShellWord)
	pkg("PATCH_DIST_CAT", BtShellCommand)
	pkg("PATCH_DIST_STRIP*", BtShellWord)
	pkglist("PATCH_SITES", BtFetchURL)
	pkg("PATCH_STRIP", BtShellWord)
	sysload("PATH", BtPathlist)   // From the PATH environment variable.
	sys("PAXCTL", BtShellCommand) // See mk/pax.mk.
	pkglist("PERL5_PACKLIST", BtPerl5Packlist)
	pkg("PERL5_PACKLIST_DIR", BtPathname)
	pkglistrat("PERL5_REQD", BtVersion)
	sysbl3("PERL5_INSTALLARCHLIB", BtPathname) // See lang/perl5/vars.mk
	sysbl3("PERL5_INSTALLSCRIPT", BtPathname)
	sysbl3("PERL5_INSTALLVENDORBIN", BtPathname)
	sysbl3("PERL5_INSTALLVENDORSCRIPT", BtPathname)
	sysbl3("PERL5_INSTALLVENDORARCH", BtPathname)
	sysbl3("PERL5_INSTALLVENDORLIB", BtPathname)
	sysbl3("PERL5_INSTALLVENDORMAN1DIR", BtPathname)
	sysbl3("PERL5_INSTALLVENDORMAN3DIR", BtPathname)
	sysbl3("PERL5_SUB_INSTALLARCHLIB", BtPrefixPathname) // See lang/perl5/vars.mk
	sysbl3("PERL5_SUB_INSTALLSCRIPT", BtPrefixPathname)
	sysbl3("PERL5_SUB_INSTALLVENDORBIN", BtPrefixPathname)
	sysbl3("PERL5_SUB_INSTALLVENDORSCRIPT", BtPrefixPathname)
	sysbl3("PERL5_SUB_INSTALLVENDORARCH", BtPrefixPathname)
	sysbl3("PERL5_SUB_INSTALLVENDORLIB", BtPrefixPathname)
	sysbl3("PERL5_SUB_INSTALLVENDORMAN1DIR", BtPrefixPathname)
	sysbl3("PERL5_SUB_INSTALLVENDORMAN3DIR", BtPrefixPathname)
	pkg("PERL5_USE_PACKLIST", BtYesNo)
	sys("PGSQL_PREFIX", BtPathname)
	acllist("PGSQL_VERSIONS_ACCEPTED", pgsqlVersions,
		PackageSettable|NeedsRationale,
		// The "set" is necessary for databases/postgresql-postgis2.
		"Makefile, Makefile.*, *.mk: default, set, append, use")
	usr("PGSQL_VERSION_DEFAULT", BtVersion)
	sys("PG_LIB_EXT", enum("dylib so"))
	sys("PGSQL_TYPE",
		enumFrom("mk/pgsql.buildlink3.mk", "postgresql11-client", "PGSQL_TYPE"))
	sys("PGPKGSRCDIR", BtPathname)
	sys("PHASE_MSG", BtShellCommand)
	usr("PHP_VERSION_REQD", BtVersion)
	acl("PHP_PKG_PREFIX",
		enumFromDirs("lang", `^php(\d+)$`, "php$1", "php56 php71 php72 php73"),
		SystemProvided,
		"special:phpversion.mk: set",
		"*: use, use-loadtime")
	sys("PKGBASE", BtIdentifier)
	// Despite its name, this is actually a list of filenames.
	acllist("PKGCONFIG_FILE.*", BtPathname,
		PackageSettable,
		"builtin.mk: set, append",
		"special:pkgconfig-builtin.mk: use-loadtime")
	pkglist("PKGCONFIG_OVERRIDE", BtPathmask)
	pkg("PKGCONFIG_OVERRIDE_STAGE", BtStage)
	pkg("PKGDIR", BtRelativePkgDir)
	sys("PKGDIRMODE", BtFileMode)
	sys("PKGLOCALEDIR", BtPathname)
	pkg("PKGNAME", BtPkgName)
	sys("PKGNAME_NOREV", BtPkgName)
	sysload("PKGPATH", BtPathname)
	sys("PKGREPOSITORY", BtUnknown)
	// This variable is special in that it really only makes sense to
	// be set in a package Makefile.
	// See VartypeCheck.PkgRevision for details.
	acl("PKGREVISION", BtPkgRevision,
		PackageSettable,
		"Makefile: set")
	sys("PKGSRCDIR", BtPathname)
	// This definition is only valid in the top-level Makefile,
	// not in category or package Makefiles.
	acl("PKGSRCTOP", BtYes,
		PackageSettable,
		"Makefile: set")
	sys("PKGSRC_SETENV", BtShellCommand)
	syslist("PKGTOOLS_ENV", BtShellWord)
	sys("PKGVERSION", BtVersion)
	sys("PKGVERSION_NOREV", BtVersion) // Without the nb* part.
	sys("PKGWILDCARD", BtFileMask)
	sysload("PKG_ADMIN", BtShellCommand)
	sys("PKG_APACHE", enum("apache24"))
	pkglistrat("PKG_APACHE_ACCEPTED", enum("apache24"))
	usr("PKG_APACHE_DEFAULT", enum("apache24"))
	sysloadlist("PKG_BUILD_OPTIONS.*", BtOption)
	usr("PKG_CONFIG", BtYes)
	// ^^ No, this is not the popular command from GNOME, but the setting
	// whether the pkgsrc user wants configuration files automatically
	// installed or not.
	sys("PKG_CREATE", BtShellCommand)
	sys("PKG_DBDIR", BtPathname)
	cmdline("PKG_DEBUG_LEVEL", BtInteger)
	usrlist("PKG_DEFAULT_OPTIONS", BtOption)
	sys("PKG_DELETE", BtShellCommand)
	pkglist("PKG_DESTDIR_SUPPORT", enum("destdir user-destdir"))
	pkglist("PKG_FAIL_REASON", BtShellWord)
	sysload("PKG_FORMAT", BtIdentifier)
	pkg("PKG_GECOS.*", BtMessage)
	pkg("PKG_GID.*", BtInteger)
	pkglist("PKG_GROUPS", BtShellWord)
	pkglist("PKG_GROUPS_VARS", BtVariableName)
	pkg("PKG_HOME.*", BtPathname)
	// PKG_HACKS is used to record the applied hacks in the binary package.
	// Since only the hacks.mk can define hacks, appending to it only makes
	// sense there.
	//
	// TODO: Is it possible that a package includes the hacks.mk file from
	//  one of its dependencies?
	acllist("PKG_HACKS", BtIdentifier,
		PackageSettable,
		"*: none")
	sys("PKG_INFO", BtShellCommand)
	sys("PKG_JAVA_HOME", BtPathname)
	sys("PKG_JVM", jvms)
	pkglistrat("PKG_JVMS_ACCEPTED", jvms)
	pkg("PKG_LIBTOOL", BtPathname)

	// begin PKG_OPTIONS section
	//
	// TODO: force the pkgsrc packages to only define options in the
	//  options.mk file. Most packages already do this, but some still
	//  define them in the Makefile or Makefile.common.
	sysloadlist("PKG_OPTIONS", BtOption)
	usrlist("PKG_OPTIONS.*", BtOption)
	opt := pkg
	optlist := pkglist
	optlist("PKG_LEGACY_OPTIONS", BtOption)
	optlist("PKG_OPTIONS_DEPRECATED_WARNINGS", BtShellWord)
	optlist("PKG_OPTIONS_GROUP.*", BtOption)
	optlist("PKG_OPTIONS_LEGACY_OPTS", BtUnknown)
	optlist("PKG_OPTIONS_LEGACY_VARS", BtUnknown)
	optlist("PKG_OPTIONS_NONEMPTY_SETS", BtIdentifier)
	optlist("PKG_OPTIONS_OPTIONAL_GROUPS", BtIdentifier)
	optlist("PKG_OPTIONS_REQUIRED_GROUPS", BtIdentifier)
	optlist("PKG_OPTIONS_SET.*", BtOption)
	opt("PKG_OPTIONS_VAR", BtPkgOptionsVar)
	pkglist("PKG_SKIP_REASON", BtShellWord)
	optlist("PKG_SUGGESTED_OPTIONS", BtOption)
	optlist("PKG_SUGGESTED_OPTIONS.*", BtOption)
	optlist("PKG_SUPPORTED_OPTIONS", BtOption)
	// end PKG_OPTIONS section

	pkg("PKG_PRESERVE", BtYes)
	pkg("PKG_SHELL", BtPathname)
	pkg("PKG_SHELL.*", BtPathname)
	sys("PKG_SHLIBTOOL", BtPathname)
	// The special exception for buildlink3.mk is only here because
	// of textproc/xmlcatmgr.
	acl("PKG_SYSCONFDIR*", BtPathname,
		PackageSettable,
		"Makefile: set, use, use-loadtime",
		"buildlink3.mk, builtin.mk: use-loadtime",
		"Makefile.*, *.mk: default, set, use, use-loadtime")
	pkglist("PKG_SYSCONFDIR_PERMS", BtPerms)
	sys("PKG_SYSCONFBASEDIR", BtPathname)
	pkg("PKG_SYSCONFSUBDIR", BtPathname)
	pkg("PKG_SYSCONFVAR", BtIdentifier)
	pkg("PKG_UID", BtInteger)
	pkglist("PKG_USERS", BtShellWord)
	pkglist("PKG_USERS_VARS", BtVariableName)
	pkg("PKG_USE_KERBEROS", BtYes)
	pkgload("PLIST.*", BtYes)
	pkglist("PLIST_VARS", BtIdentifier)
	pkglist("PLIST_SRC", BtRelativePkgPath)
	pkglist("PLIST_SUBST", BtShellWord)
	pkg("PLIST_TYPE", enum("dynamic static"))
	pkglistbl3("PREPEND_PATH", BtPathname)

	acl("PREFIX", BtPathname,
		UserSettable,
		"*: use")
	// BtPathname instead of BtPkgPath since the original package doesn't exist anymore.
	// It would be more precise to check for a PkgPath that doesn't exist anymore.
	pkg("PREV_PKGPATH", BtPathname)
	acl("PRINT_PLIST_AWK", BtAwkCommand,
		PackageSettable,
		"*: append")
	pkglist("PRIVILEGED_STAGES", enum("build install package clean"))
	pkgbl3("PTHREAD_AUTO_VARS", BtYesNo)
	syslist("PTHREAD_CFLAGS", BtCFlag)
	syslist("PTHREAD_LDFLAGS", BtLdFlag)
	syslist("PTHREAD_LIBS", BtLdFlag)
	pkglistbl3("PTHREAD_OPTS", enum("native optional require"))
	sysload("PTHREAD_TYPE", BtIdentifier) // Or "native" or "none".
	pkg("PY_PATCHPLIST", BtYes)
	acl("PYPKGPREFIX",
		enumFromDirs("lang", `^python(\d+)$`, "py$1", "py27 py36"),
		SystemProvided,
		"special:pyversion.mk: set",
		"*: use, use-loadtime")
	// See lang/python/pyversion.mk
	pkg("PYTHON_FOR_BUILD_ONLY", enum("yes no test tool YES"))
	pkglistrat("PYTHON_VERSIONS_ACCEPTED", BtVersion)
	pkglistrat("PYTHON_VERSIONS_INCOMPATIBLE", BtVersion)
	usr("PYTHON_VERSION_DEFAULT", BtVersion)
	usr("PYTHON_VERSION_REQD", BtVersion)
	pkglist("PYTHON_VERSIONED_DEPENDENCIES", BtPythonDependency)
	sys("RANLIB", BtShellCommand)
	pkglist("RCD_SCRIPTS", BtFileName)
	// TODO: Is the definition in www/squid3/Makefile detected as being redundant?
	//  No, but it could if the RedundancyScope were able to resolve ${FILESDIR}
	//  to "files".
	pkg("RCD_SCRIPT_SRC.*", BtPathname)
	pkg("RCD_SCRIPT_WRK.*", BtPathname)
	usr("REAL_ROOT_USER", BtUserGroupName)
	usr("REAL_ROOT_GROUP", BtUserGroupName)

	// Example:
	//  REPLACE.sys-AWK.old=    .*awk
	//  REPLACE.sys-AWK.new=    ${AWK}
	// BtUnknown since one of them is a regular expression and the other
	// is a plain string.
	pkg("REPLACE.*", BtUnknown)

	pkglist("REPLACE_AWK", BtPathmask)
	pkglist("REPLACE_BASH", BtPathmask)
	pkglist("REPLACE_CSH", BtPathmask)
	pkglist("REPLACE_FILES.*", BtPathmask)
	pkglist("REPLACE_INTERPRETER", BtIdentifier)
	pkglist("REPLACE_KSH", BtPathmask)
	pkglist("REPLACE_LOCALEDIR_PATTERNS", BtFileMask)
	pkglist("REPLACE_LUA", BtPathmask)
	pkglist("REPLACE_PERL", BtPathmask)
	pkglist("REPLACE_PYTHON", BtPathmask)
	pkglist("REPLACE_SH", BtPathmask)
	pkglist("REQD_DIRS", BtPathname)
	pkglist("REQD_DIRS_PERMS", BtPerms)
	pkglist("REQD_FILES", BtPathname)
	pkg("REQD_FILES_MODE", enum("0644 0640 0600 0400"))
	pkglist("REQD_FILES_PERMS", BtPerms)
	pkg("RESTRICTED", BtMessage)
	usr("ROOT_USER", BtUserGroupName)
	usr("ROOT_GROUP", BtUserGroupName)
	pkglist("RPMIGNOREPATH", BtPathmask)
	acl("RUBY_BASE",
		enumFromDirs("lang", `^ruby(\d+)$`, "ruby$1", "ruby22 ruby23 ruby24 ruby25"),
		SystemProvided,
		"special:rubyversion.mk: set",
		"*: use, use-loadtime")
	usr("RUBY_VERSION_REQD", BtVersion)
	acl("RUBY_PKGPREFIX",
		enumFromDirs("lang", `^ruby(\d+)$`, "ruby$1", "ruby22 ruby23 ruby24 ruby25"),
		SystemProvided,
		"special:rubyversion.mk: default, set, use",
		"*: use, use-loadtime")
	sys("RUN", BtShellCommand)
	sys("RUN_LDCONFIG", BtYesNo)
	pkglist("SCRIPTS_ENV", BtShellWord)
	usrlist("SETGID_GAMES_PERMS", BtPerms)
	usrlist("SETUID_ROOT_PERMS", BtPerms)
	pkg("SET_LIBDIR", BtYes)
	sys("SHAREGRP", BtUserGroupName)
	sys("SHAREMODE", BtFileMode)
	sys("SHAREOWN", BtUserGroupName)
	sys("SHCOMMENT", BtShellCommand)
	sys("SHLIBTOOL", BtShellCommand)
	pkglist("SHLIBTOOL_OVERRIDE", BtPathmask)
	sysload("SHLIB_TYPE",
		enum("COFF ECOFF ELF SOM XCOFF Mach-O PE PEwin a.out aixlib dylib none"))
	pkglist("SITES.*", BtFetchURL)
	usr("SMF_PREFIS", BtPathname)
	pkg("SMF_SRCDIR", BtPathname)
	pkg("SMF_NAME", BtFileName)
	pkg("SMF_MANIFEST", BtPathname)
	pkglist("SMF_INSTANCES", BtIdentifier)
	pkglist("SMF_METHODS", BtFileName)
	pkg("SMF_METHOD_SRC.*", BtPathname)
	pkg("SMF_METHOD_SHELL", BtShellCommand)
	pkglist("SPECIAL_PERMS", BtPerms)
	sys("STEP_MSG", BtShellCommand)
	sys("STRIP", BtShellCommand) // see mk/tools/strip.mk

	// Only valid in the top-level and the category Makefiles.
	acllist("SUBDIR", BtFileName,
		PackageSettable,
		"Makefile: append")

	pkglistbl3("SUBST_CLASSES", BtIdentifier)
	pkglistbl3("SUBST_CLASSES.*", BtIdentifier) // OPSYS-specific
	pkglistbl3("SUBST_FILES.*", BtPathmask)
	pkgbl3("SUBST_FILTER_CMD.*", BtShellCommand)
	pkgbl3("SUBST_MESSAGE.*", BtMessage)
	pkgappendbl3("SUBST_SED.*", BtSedCommands)
	pkgbl3("SUBST_STAGE.*", BtStage)
	pkglistbl3("SUBST_VARS.*", BtVariableName)

	pkglist("SUPERSEDES", BtDependency)
	pkglist("TEST_DEPENDS", BtDependencyWithPath)
	pkglist("TEST_DIRS", BtWrksrcSubdirectory)
	pkglist("TEST_ENV", BtShellWord)
	pkglist("TEST_TARGET", BtIdentifier)
	pkglistrat("TEXINFO_REQD", BtVersion)
	pkglistbl3("TOOL_DEPENDS", BtDependencyWithPath)
	syslist("TOOLS_ALIASES", BtFileName)
	syslist("TOOLS_BROKEN", BtTool)
	sys("TOOLS_CMD.*", BtPathname)
	pkglist("TOOLS_CREATE", BtTool)
	pkglist("TOOLS_DEPENDS.*", BtDependencyWithPath)
	syslist("TOOLS_GNU_MISSING", BtTool)
	syslist("TOOLS_NOOP", BtTool)
	sys("TOOLS_PATH.*", BtPathname)
	sysload("TOOLS_PLATFORM.*", BtShellCommand)
	syslist("TOUCH_FLAGS", BtShellWord)
	pkglist("UAC_REQD_EXECS", BtPrefixPathname)
	pkglistbl3("UNLIMIT_RESOURCES",
		enum("cputime datasize memorysize stacksize"))
	usr("UNPRIVILEGED_USER", BtUserGroupName)
	usr("UNPRIVILEGED_GROUP", BtUserGroupName)
	pkglist("UNWRAP_FILES", BtPathmask)
	usrlist("UPDATE_TARGET", BtIdentifier)
	pkg("USERGROUP_PHASE", enum("configure build pre-install"))
	usrlist("USER_ADDITIONAL_PKGS", BtPkgPath)
	pkg("USE_BSD_MAKEFILE", BtYes)

	// USE_BUILTIN.* is usually set by the builtin.mk file, after checking
	// whether the package is available in the base system. To override
	// this check, a package may set this variable before including the
	// corresponding buildlink3.mk file.
	acl("USE_BUILTIN.*", BtYesNoIndirectly,
		PackageSettable,
		"Makefile, Makefile.*, *.mk: set, use, use-loadtime")

	pkg("USE_CMAKE", BtYes)
	usr("USE_DESTDIR", BtYes)
	pkglist("USE_FEATURES", BtIdentifier)
	pkg("USE_GAMESGROUP", BtYesNo)
	pkg("USE_GCC_RUNTIME", BtYesNo)
	pkg("USE_GNU_CONFIGURE_HOST", BtYesNo)
	pkgload("USE_GNU_ICONV", BtYes)
	pkg("USE_IMAKE", BtYes)
	pkg("USE_JAVA", enum("run yes build"))
	pkg("USE_JAVA2", enum("YES yes no 1.4 1.5 6 7 8"))
	pkglist("USE_LANGUAGES", compilerLanguages)
	pkg("USE_LIBTOOL", BtYes)
	pkg("USE_MAKEINFO", BtYes)
	pkg("USE_MSGFMT_PLURALS", BtYes)
	pkg("USE_NCURSES", BtYes)
	pkg("USE_OLD_DES_API", BtYesNo)
	pkg("USE_PKGINSTALL", BtYes)
	pkg("USE_PKGLOCALEDIR", BtYesNo)
	usr("USE_PKGSRC_GCC", BtYes)

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
	acllist("USE_TOOLS", BtTool,
		PackageSettable,
		"special:Makefile.common: set, append, use, use-loadtime",
		"buildlink3.mk: append",
		"builtin.mk: append, use-loadtime",
		"*: set, append, use")
	acllist("USE_TOOLS.*", BtTool, // OPSYS-specific
		PackageSettable,
		"buildlink3.mk, builtin.mk: append",
		"*: set, append, use")

	pkg("USE_X11", BtYes)
	syslist("WARNINGS", BtShellWord)
	sys("WARNING_MSG", BtShellCommand)
	sys("WARNING_CAT", BtShellCommand)
	sysload("WRAPPER_DIR", BtPathname)
	pkglistbl3("WRAPPER_REORDER_CMDS", BtWrapperReorder)
	pkg("WRAPPER_SHELL", BtShellCommand)
	pkglist("WRAPPER_TRANSFORM_CMDS", BtWrapperTransform)
	sys("WRKDIR", BtPathname)
	pkg("WRKSRC", BtWrkdirSubdirectory)
	pkglist("X11_LDFLAGS", BtLdFlag)
	sys("X11_PKGSRCDIR.*", BtPathname)
	pkglist("XMKMF_FLAGS", BtShellWord)
	pkglist("_WRAP_EXTRA_ARGS.*", BtShellWord)

	infralist("_VARGROUPS", BtIdentifier)
	infralist("_USER_VARS.*", BtIdentifier)
	infralist("_PKG_VARS.*", BtIdentifier)
	infralist("_SYS_VARS.*", BtIdentifier)
	infralist("_DEF_VARS.*", BtIdentifier)
	infralist("_USE_VARS.*", BtIdentifier)
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

	G.Assertf(len(aclEntries) > 0, "At least one ACL entry must be given.")

	// TODO: Use separate rules for infrastructure files.
	//  These rules would have the "infra:" prefix
	//  that works similar to the already existing prefix "special:".
	//  The "infra:" prefix applies to both mk/* and wip/mk/* files, and globs
	//  without that prefix only apply to all files outside the infrastructure.

	var result []ACLEntry
	prevperms := "(first)"
	for _, arg := range aclEntries {
		fields := strings.Split(arg, ": ")
		G.Assertf(len(fields) == 2, "ACL entry %q must have exactly 1 colon.", arg)
		globs, perms := fields[0], fields[1]

		G.Assertf(perms != prevperms, "Repeated permissions %q for %q.", perms, varname)
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
					G.Assertf(false, "Invalid ACL glob %q for %q.", glob, varname)
				} else {
					glob = withoutSpecial
				}
			}
			for _, prev := range result {
				matched, err := path.Match(prev.glob, glob)
				G.AssertNil(err, "Invalid ACL pattern %q for %q", glob, varname)
				G.Assertf(!matched, "Unreachable ACL pattern %q for %q.", glob, varname)
			}
			result = append(result, ACLEntry{glob, permissions})
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
		G.Assertf(
			false,
			"Invalid ACL permission %q for %q in %q. "+
				"Remaining parts are %q. "+
				"Valid permissions are default, set, append, "+
				"use, use-loadtime (in this order), or none.",
			perms, varname, globs, strings.Join(splitPerms, ", "))
	}
	return permissions
}
