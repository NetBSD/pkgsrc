package main

import (
	"netbsd.org/pkglint/regex"
	"path"
	"strings"
)

// This file defines the specific type of some variables.
//
// There are two types of lists:
// * lkShell is a list whose elements are split by shell rules
// * lkSpace is a list whose elements are split by whitespace
//
// See vartypecheck.go for how these types are checked.

// InitVartypes initializes the long list of predefined pkgsrc variables.
// After this is done, ${PKGNAME}, ${MAKE_ENV} and all the other variables
// can be used in Makefiles without triggering warnings about typos.
func (src *Pkgsrc) InitVartypes() {

	acl := func(varname string, kindOfList KindOfList, checker *BasicType, aclEntries string) {
		m := mustMatch(varname, `^([A-Z_.][A-Z0-9_]*|@)(|\*|\.\*)$`)
		varbase, varparam := m[1], m[2]

		vartype := &Vartype{kindOfList, checker, parseACLEntries(varname, aclEntries), false}

		if varparam == "" || varparam == "*" {
			src.vartypes[varbase] = vartype
		}
		if varparam == "*" || varparam == ".*" {
			src.vartypes[varbase+".*"] = vartype
		}
	}

	// A package-defined variable may be set in all Makefiles except buildlink3.mk and builtin.mk.
	pkg := func(varname string, kindOfList KindOfList, checker *BasicType) {
		acl(varname, kindOfList, checker, ""+
			"Makefile: set, use; "+
			"buildlink3.mk, builtin.mk:; "+
			"Makefile.*, *.mk: default, set, use")
	}

	// pkgload is the same as pkg, except that the variable may be accessed at load time.
	pkgload := func(varname string, kindOfList KindOfList, checker *BasicType) {
		acl(varname, kindOfList, checker, ""+
			"Makefile: set, use, use-loadtime; "+
			"buildlink3.mk, builtin.mk:; "+
			"Makefile.*, *.mk: default, set, use, use-loadtime")
	}

	// A package-defined list may be appended to in all Makefiles except buildlink3.mk and builtin.mk.
	// Simple assignment (instead of appending) is only allowed in Makefile and Makefile.common.
	pkglist := func(varname string, kindOfList KindOfList, checker *BasicType) {
		acl(varname, kindOfList, checker, ""+
			"Makefile, Makefile.common, options.mk: append, default, set, use; "+
			"buildlink3.mk, builtin.mk:; "+
			"*.mk: append, default, use")
	}

	// A user-defined or system-defined variable must not be set by any
	// package file. It also must not be used in buildlink3.mk and
	// builtin.mk files or at load-time, since the system/user preferences
	// may not have been loaded when these files are included.
	sys := func(varname string, kindOfList KindOfList, checker *BasicType) {
		acl(varname, kindOfList, checker, "buildlink3.mk:; *: use")
	}

	usr := func(varname string, kindOfList KindOfList, checker *BasicType) {
		acl(varname, kindOfList, checker, "buildlink3.mk:; *: use-loadtime, use")
	}

	// sysload defines a system-provided variable that may already be used
	// at load time.
	sysload := func(varname string, kindOfList KindOfList, checker *BasicType) {
		acl(varname, kindOfList, checker, "*: use-loadtime, use")
	}

	bl3list := func(varname string, kindOfList KindOfList, checker *BasicType) {
		acl(varname, kindOfList, checker, "buildlink3.mk, builtin.mk: append")
	}
	cmdline := func(varname string, kindOfList KindOfList, checker *BasicType) {
		acl(varname, kindOfList, checker, "buildlink3.mk, builtin.mk:; *: use-loadtime, use")
	}

	languages := enum(
		func() string {
			mklines := LoadMk(src.File("mk/compiler.mk"), NotEmpty)
			languages := make(map[string]bool)
			if mklines != nil {
				for _, mkline := range mklines.mklines {
					if mkline.IsDirective() && mkline.Directive() == "for" {
						words := fields(mkline.Args())
						if len(words) > 2 && words[0] == "_version_" {
							for _, word := range words[2:] {
								languages[word] = true
							}
						}
					}
				}
			}
			for _, language := range [...]string{"ada", "c", "c99", "c++", "c++11", "fortran", "fortran77", "java", "objc", "obj-c++"} {
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
	enumFrom := func(fileName string, defval string, varcanons ...string) *BasicType {
		mklines := LoadMk(src.File(fileName), NotEmpty)
		values := make(map[string]bool)

		if mklines != nil {
			for _, mkline := range mklines.mklines {
				if mkline.IsVarassign() {
					varcanon := mkline.Varcanon()
					for _, vc := range varcanons {
						if vc == varcanon {
							words, _ := splitIntoMkWords(mkline.Line, mkline.Value())
							for _, word := range words {
								if !contains(word, "$") {
									values[word] = true
								}
							}
						}
					}
				}
			}
		}

		if len(values) > 0 {
			joined := keysJoined(values)
			if trace.Tracing {
				trace.Stepf("Enum from %s in: %s", strings.Join(varcanons, " "), fileName, joined)
			}
			return enum(joined)
		}

		if trace.Tracing {
			trace.Stepf("Enum from default value: %s", defval)
		}
		return enum(defval)
	}

	// enumFromDirs reads the directories from category, takes all
	// that have a single number in them and ranks them from earliest
	// to latest.
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
		"openjdk8 oracle-jdk8 openjdk7 sun-jdk7 sun-jdk6 jdk16 jdk15 kaffe",
		"_PKG_JVMS.*")

	// Last synced with mk/defaults/mk.conf revision 1.269
	usr("USE_CWRAPPERS", lkNone, enum("yes no auto"))
	usr("ALLOW_VULNERABLE_PACKAGES", lkNone, BtYes)
	usr("AUDIT_PACKAGES_FLAGS", lkShell, BtShellWord)
	usr("MANINSTALL", lkShell, enum("maninstall catinstall"))
	usr("MANZ", lkNone, BtYes)
	usr("GZIP", lkShell, BtShellWord)
	usr("MAKE_JOBS", lkNone, BtInteger)
	usr("OBJHOSTNAME", lkNone, BtYes)
	usr("OBJMACHINE", lkNone, BtYes)
	usr("SIGN_PACKAGES", lkNone, enum("gpg x509"))
	usr("X509_KEY", lkNone, BtPathname)
	usr("X509_CERTIFICATE", lkNone, BtPathname)
	usr("PATCH_DEBUG", lkNone, BtYes)
	usr("PKG_COMPRESSION", lkNone, enum("gzip bzip2 none"))
	usr("PKGSRC_LOCKTYPE", lkNone, enum("none sleep once"))
	usr("PKGSRC_SLEEPSECS", lkNone, BtInteger)
	usr("ABI", lkNone, enum("32 64"))
	usr("PKG_DEVELOPER", lkNone, BtYesNo)
	usr("USE_ABI_DEPENDS", lkNone, BtYesNo)
	usr("PKG_REGISTER_SHELLS", lkNone, enum("YES NO"))
	usr("PKGSRC_COMPILER", lkShell, compilers)
	usr("PKGSRC_KEEP_BIN_PKGS", lkNone, BtYesNo)
	usr("PKGSRC_MESSAGE_RECIPIENTS", lkShell, BtMailAddress)
	usr("PKGSRC_SHOW_BUILD_DEFS", lkNone, BtYesNo)
	usr("PKGSRC_RUN_TEST", lkNone, BtYesNo)
	usr("PKGSRC_MKPIE", lkNone, BtYesNo)
	usr("PKGSRC_USE_FORTIFY", lkNone, BtYesNo)
	usr("PKGSRC_USE_RELRO", lkNone, BtYesNo)
	usr("PKGSRC_USE_SSP", lkNone, enum("no yes strong all"))
	usr("PREFER.*", lkNone, enum("pkgsrc native"))
	usr("PREFER_PKGSRC", lkShell, BtIdentifier)
	usr("PREFER_NATIVE", lkShell, BtIdentifier)
	usr("PREFER_NATIVE_PTHREADS", lkNone, BtYesNo)
	usr("WRKOBJDIR", lkNone, BtPathname)
	usr("LOCALBASE", lkNone, BtPathname)
	usr("CROSSBASE", lkNone, BtPathname)
	usr("VARBASE", lkNone, BtPathname)
	acl("X11_TYPE", lkNone, enum("modular native"), "*: use-loadtime, use")
	usr("X11BASE", lkNone, BtPathname)
	usr("MOTIFBASE", lkNone, BtPathname)
	usr("PKGINFODIR", lkNone, BtPathname)
	usr("PKGMANDIR", lkNone, BtPathname)
	usr("PKGGNUDIR", lkNone, BtPathname)
	usr("BSDSRCDIR", lkNone, BtPathname)
	usr("BSDXSRCDIR", lkNone, BtPathname)
	usr("DISTDIR", lkNone, BtPathname)
	usr("DIST_PATH", lkNone, BtPathlist)
	usr("DEFAULT_VIEW", lkNone, BtUnknown) // XXX: deprecate? pkgviews has been removed
	usr("FETCH_CMD", lkNone, BtShellCommand)
	usr("FETCH_USING", lkNone, enum("auto curl custom fetch ftp manual wget"))
	usr("FETCH_BEFORE_ARGS", lkShell, BtShellWord)
	usr("FETCH_AFTER_ARGS", lkShell, BtShellWord)
	usr("FETCH_RESUME_ARGS", lkShell, BtShellWord)
	usr("FETCH_OUTPUT_ARGS", lkShell, BtShellWord)
	usr("FIX_SYSTEM_HEADERS", lkNone, BtYes)
	usr("LIBTOOLIZE_PLIST", lkNone, BtYesNo)
	usr("PKG_RESUME_TRANSFERS", lkNone, BtYesNo)
	usr("PKG_SYSCONFBASE", lkNone, BtPathname)
	usr("INIT_SYSTEM", lkNone, enum("rc.d smf"))
	usr("RCD_SCRIPTS_DIR", lkNone, BtPathname)
	usr("PACKAGES", lkNone, BtPathname)
	usr("PASSIVE_FETCH", lkNone, BtYes)
	usr("PATCH_FUZZ_FACTOR", lkNone, enum("-F0 -F1 -F2 -F3"))
	usr("ACCEPTABLE_LICENSES", lkShell, BtIdentifier)
	usr("SPECIFIC_PKGS", lkNone, BtYes)
	usr("SITE_SPECIFIC_PKGS", lkShell, BtPkgPath)
	usr("HOST_SPECIFIC_PKGS", lkShell, BtPkgPath)
	usr("GROUP_SPECIFIC_PKGS", lkShell, BtPkgPath)
	usr("USER_SPECIFIC_PKGS", lkShell, BtPkgPath)
	usr("EXTRACT_USING", lkNone, enum("bsdtar gtar nbtar pax"))
	usr("FAILOVER_FETCH", lkNone, BtYes)
	usr("MASTER_SORT", lkShell, BtUnknown)
	usr("MASTER_SORT_REGEX", lkShell, BtUnknown)
	usr("MASTER_SORT_RANDOM", lkNone, BtYes)
	usr("PATCH_DEBUG", lkNone, BtYes)
	usr("PKG_FC", lkNone, BtShellCommand)
	usr("IMAKEOPTS", lkShell, BtShellWord)
	usr("PRE_ROOT_CMD", lkNone, BtShellCommand)
	usr("SU_CMD", lkNone, BtShellCommand)
	usr("SU_CMD_PATH_APPEND", lkNone, BtPathlist)
	usr("FATAL_OBJECT_FMT_SKEW", lkNone, BtYesNo)
	usr("WARN_NO_OBJECT_FMT", lkNone, BtYesNo)
	usr("SMART_MESSAGES", lkNone, BtYes)
	usr("BINPKG_SITES", lkShell, BtURL)
	usr("BIN_INSTALL_FLAGS", lkShell, BtShellWord)
	usr("LOCALPATCHES", lkNone, BtPathname)

	// The remaining variables from mk/defaults/mk.conf may be overridden by packages.
	// Therefore they need a separate definition of "user-settable".
	//
	// It is debatable whether packages should be allowed to override these
	// variables at all since then there are two competing sources for the
	// default values. Current practice is to have exactly this ambiguity,
	// combined with some package Makefiles including bsd.prefs.mk and others
	// omitting this necessary inclusion.
	//
	// TODO: parse all the below information directly from mk/defaults/mk.conf.
	usrpkg := func(varname string, kindOfList KindOfList, checker *BasicType) {
		acl(varname, kindOfList, checker, ""+
			"Makefile: default, set, use, use-loadtime; "+
			"buildlink3.mk, builtin.mk:; "+
			"Makefile.*, *.mk: default, set, use, use-loadtime; "+
			"*: use-loadtime, use")
	}
	usrpkg("ACROREAD_FONTPATH", lkNone, BtPathlist)
	usrpkg("AMANDA_USER", lkNone, BtUserGroupName)
	usrpkg("AMANDA_TMP", lkNone, BtPathname)
	usrpkg("AMANDA_VAR", lkNone, BtPathname)
	usrpkg("APACHE_USER", lkNone, BtUserGroupName)
	usrpkg("APACHE_GROUP", lkNone, BtUserGroupName)
	usrpkg("APACHE_SUEXEC_CONFIGURE_ARGS", lkShell, BtShellWord)
	usrpkg("APACHE_SUEXEC_DOCROOT", lkShell, BtPathname)
	usrpkg("ARLA_CACHE", lkNone, BtPathname)
	usrpkg("BIND_DIR", lkNone, BtPathname)
	usrpkg("BIND_GROUP", lkNone, BtUserGroupName)
	usrpkg("BIND_USER", lkNone, BtUserGroupName)
	usrpkg("CACTI_GROUP", lkNone, BtUserGroupName)
	usrpkg("CACTI_USER", lkNone, BtUserGroupName)
	usrpkg("CANNA_GROUP", lkNone, BtUserGroupName)
	usrpkg("CANNA_USER", lkNone, BtUserGroupName)
	usrpkg("CDRECORD_CONF", lkNone, BtPathname)
	usrpkg("CLAMAV_GROUP", lkNone, BtUserGroupName)
	usrpkg("CLAMAV_USER", lkNone, BtUserGroupName)
	usrpkg("CLAMAV_DBDIR", lkNone, BtPathname)
	usrpkg("CONSERVER_DEFAULTHOST", lkNone, BtIdentifier)
	usrpkg("CONSERVER_DEFAULTPORT", lkNone, BtInteger)
	usrpkg("CUPS_GROUP", lkNone, BtUserGroupName)
	usrpkg("CUPS_USER", lkNone, BtUserGroupName)
	usrpkg("CUPS_SYSTEM_GROUPS", lkShell, BtUserGroupName)
	usrpkg("CYRUS_IDLE", lkNone, enum("poll idled no"))
	usrpkg("CYRUS_GROUP", lkNone, BtUserGroupName)
	usrpkg("CYRUS_USER", lkNone, BtUserGroupName)
	usrpkg("DBUS_GROUP", lkNone, BtUserGroupName)
	usrpkg("DBUS_USER", lkNone, BtUserGroupName)
	usrpkg("DEFANG_GROUP", lkNone, BtUserGroupName)
	usrpkg("DEFANG_USER", lkNone, BtUserGroupName)
	usrpkg("DEFANG_SPOOLDIR", lkNone, BtPathname)
	usrpkg("DEFAULT_IRC_SERVER", lkNone, BtIdentifier)
	usrpkg("DEFAULT_SERIAL_DEVICE", lkNone, BtPathname)
	usrpkg("DIALER_GROUP", lkNone, BtUserGroupName)
	usrpkg("DT_LAYOUT", lkNone, enum("US FI FR GER DV"))
	usrpkg("ELK_GUI", lkShell, enum("none xaw motif"))
	usrpkg("EMACS_TYPE", lkNone, emacsVersions)
	usrpkg("EXIM_GROUP", lkNone, BtUserGroupName)
	usrpkg("EXIM_USER", lkNone, BtUserGroupName)
	usrpkg("FLUXBOX_USE_XINERAMA", lkNone, enum("YES NO"))
	usrpkg("FLUXBOX_USE_KDE", lkNone, enum("YES NO"))
	usrpkg("FLUXBOX_USE_GNOME", lkNone, enum("YES NO"))
	usrpkg("FLUXBOX_USE_XFT", lkNone, enum("YES NO"))
	usrpkg("FOX_USE_XUNICODE", lkNone, enum("YES NO"))
	usrpkg("FREEWNN_USER", lkNone, BtUserGroupName)
	usrpkg("FREEWNN_GROUP", lkNone, BtUserGroupName)
	usrpkg("GAMES_USER", lkNone, BtUserGroupName)
	usrpkg("GAMES_GROUP", lkNone, BtUserGroupName)
	usrpkg("GAMEMODE", lkNone, BtFileMode)
	usrpkg("GAMEDIRMODE", lkNone, BtFileMode)
	usrpkg("GAMEDATAMODE", lkNone, BtFileMode)
	usrpkg("GAMEGRP", lkNone, BtUserGroupName)
	usrpkg("GAMEOWN", lkNone, BtUserGroupName)
	usrpkg("GRUB_NETWORK_CARDS", lkNone, BtIdentifier)
	usrpkg("GRUB_PRESET_COMMAND", lkNone, enum("bootp dhcp rarp"))
	usrpkg("GRUB_SCAN_ARGS", lkShell, BtShellWord)
	usrpkg("HASKELL_COMPILER", lkNone, enum("ghc"))
	usrpkg("HOWL_GROUP", lkNone, BtUserGroupName)
	usrpkg("HOWL_USER", lkNone, BtUserGroupName)
	usrpkg("ICECAST_CHROOTDIR", lkNone, BtPathname)
	usrpkg("ICECAST_CHUNKLEN", lkNone, BtInteger)
	usrpkg("ICECAST_SOURCE_BUFFSIZE", lkNone, BtInteger)
	usrpkg("IMAP_UW_CCLIENT_MBOX_FMT", lkNone, enum("mbox mbx mh mmdf mtx mx news phile tenex unix"))
	usrpkg("IMAP_UW_MAILSPOOLHOME", lkNone, BtFileName)
	usrpkg("IMDICTDIR", lkNone, BtPathname)
	usrpkg("INN_DATA_DIR", lkNone, BtPathname)
	usrpkg("INN_USER", lkNone, BtUserGroupName)
	usrpkg("INN_GROUP", lkNone, BtUserGroupName)
	usrpkg("IRCD_HYBRID_NICLEN", lkNone, BtInteger)
	usrpkg("IRCD_HYBRID_TOPICLEN", lkNone, BtInteger)
	usrpkg("IRCD_HYBRID_SYSLOG_EVENTS", lkNone, BtUnknown)
	usrpkg("IRCD_HYBRID_SYSLOG_FACILITY", lkNone, BtIdentifier)
	usrpkg("IRCD_HYBRID_MAXCONN", lkNone, BtInteger)
	usrpkg("IRCD_HYBRID_IRC_USER", lkNone, BtUserGroupName)
	usrpkg("IRCD_HYBRID_IRC_GROUP", lkNone, BtUserGroupName)
	usrpkg("IRRD_USE_PGP", lkNone, enum("5 2"))
	usrpkg("JABBERD_USER", lkNone, BtUserGroupName)
	usrpkg("JABBERD_GROUP", lkNone, BtUserGroupName)
	usrpkg("JABBERD_LOGDIR", lkNone, BtPathname)
	usrpkg("JABBERD_SPOOLDIR", lkNone, BtPathname)
	usrpkg("JABBERD_PIDDIR", lkNone, BtPathname)
	usrpkg("JAKARTA_HOME", lkNone, BtPathname)
	usrpkg("KERBEROS", lkNone, BtYes)
	usrpkg("KERMIT_SUID_UUCP", lkNone, BtYes)
	usrpkg("KJS_USE_PCRE", lkNone, BtYes)
	usrpkg("KNEWS_DOMAIN_FILE", lkNone, BtPathname)
	usrpkg("KNEWS_DOMAIN_NAME", lkNone, BtIdentifier)
	usrpkg("LIBDVDCSS_HOMEPAGE", lkNone, BtHomepage)
	usrpkg("LIBDVDCSS_MASTER_SITES", lkShell, BtFetchURL)
	usrpkg("LATEX2HTML_ICONPATH", lkNone, BtURL)
	usrpkg("LEAFNODE_DATA_DIR", lkNone, BtPathname)
	usrpkg("LEAFNODE_USER", lkNone, BtUserGroupName)
	usrpkg("LEAFNODE_GROUP", lkNone, BtUserGroupName)
	usrpkg("LINUX_LOCALES", lkShell, BtIdentifier)
	usrpkg("MAILAGENT_DOMAIN", lkNone, BtIdentifier)
	usrpkg("MAILAGENT_EMAIL", lkNone, BtMailAddress)
	usrpkg("MAILAGENT_FQDN", lkNone, BtIdentifier)
	usrpkg("MAILAGENT_ORGANIZATION", lkNone, BtUnknown)
	usrpkg("MAJORDOMO_HOMEDIR", lkNone, BtPathname)
	usrpkg("MAKEINFO_ARGS", lkShell, BtShellWord)
	usrpkg("MECAB_CHARSET", lkNone, BtIdentifier)
	usrpkg("MEDIATOMB_GROUP", lkNone, BtUserGroupName)
	usrpkg("MEDIATOMB_USER", lkNone, BtUserGroupName)
	usrpkg("MLDONKEY_GROUP", lkNone, BtUserGroupName)
	usrpkg("MLDONKEY_HOME", lkNone, BtPathname)
	usrpkg("MLDONKEY_USER", lkNone, BtUserGroupName)
	usrpkg("MONOTONE_GROUP", lkNone, BtUserGroupName)
	usrpkg("MONOTONE_USER", lkNone, BtUserGroupName)
	usrpkg("MOTIF_TYPE", lkNone, enum("motif openmotif lesstif dt"))
	usrpkg("MOTIF_TYPE_DEFAULT", lkNone, enum("motif openmotif lesstif dt"))
	usrpkg("MTOOLS_ENABLE_FLOPPYD", lkNone, BtYesNo)
	usrpkg("MYSQL_USER", lkNone, BtUserGroupName)
	usrpkg("MYSQL_GROUP", lkNone, BtUserGroupName)
	usrpkg("MYSQL_DATADIR", lkNone, BtPathname)
	usrpkg("MYSQL_CHARSET", lkNone, BtIdentifier)
	usrpkg("MYSQL_EXTRA_CHARSET", lkShell, BtIdentifier)
	usrpkg("NAGIOS_GROUP", lkNone, BtUserGroupName)
	usrpkg("NAGIOS_USER", lkNone, BtUserGroupName)
	usrpkg("NAGIOSCMD_GROUP", lkNone, BtUserGroupName)
	usrpkg("NAGIOSDIR", lkNone, BtPathname)
	usrpkg("NBPAX_PROGRAM_PREFIX", lkNone, BtUnknown)
	usrpkg("NMH_EDITOR", lkNone, BtIdentifier)
	usrpkg("NMH_MTA", lkNone, enum("smtp sendmail"))
	usrpkg("NMH_PAGER", lkNone, BtIdentifier)
	usrpkg("NS_PREFERRED", lkNone, enum("communicator navigator mozilla"))
	usrpkg("OPENSSH_CHROOT", lkNone, BtPathname)
	usrpkg("OPENSSH_USER", lkNone, BtUserGroupName)
	usrpkg("OPENSSH_GROUP", lkNone, BtUserGroupName)
	usrpkg("P4USER", lkNone, BtUserGroupName)
	usrpkg("P4GROUP", lkNone, BtUserGroupName)
	usrpkg("P4ROOT", lkNone, BtPathname)
	usrpkg("P4PORT", lkNone, BtInteger)
	usrpkg("PALMOS_DEFAULT_SDK", lkNone, enum("1 2 3.1 3.5"))
	usrpkg("PAPERSIZE", lkNone, enum("A4 Letter"))
	usrpkg("PGGROUP", lkNone, BtUserGroupName)
	usrpkg("PGUSER", lkNone, BtUserGroupName)
	usrpkg("PGHOME", lkNone, BtPathname)
	usrpkg("PILRC_USE_GTK", lkNone, BtYesNo)
	usrpkg("PKG_JVM_DEFAULT", lkNone, jvms)
	usrpkg("POPTOP_USE_MPPE", lkNone, BtYes)
	usrpkg("PROCMAIL_MAILSPOOLHOME", lkNone, BtFileName)
	usrpkg("PROCMAIL_TRUSTED_IDS", lkShell, BtUnknown) // Comma-separated list of string or integer literals.
	usrpkg("PVM_SSH", lkNone, BtPathname)
	usrpkg("QMAILDIR", lkNone, BtPathname)
	usrpkg("QMAIL_QFILTER_TMPDIR", lkNone, BtPathname)
	usrpkg("QMAIL_QUEUE_DIR", lkNone, BtPathname)
	usrpkg("QMAIL_QUEUE_EXTRA", lkNone, BtMailAddress)
	usrpkg("QPOPPER_FAC", lkNone, BtIdentifier)
	usrpkg("QPOPPER_USER", lkNone, BtUserGroupName)
	usrpkg("QPOPPER_SPOOL_DIR", lkNone, BtPathname)
	usrpkg("RASMOL_DEPTH", lkNone, enum("8 16 32"))
	usrpkg("RELAY_CTRL_DIR", lkNone, BtPathname)
	usrpkg("RPM_DB_PREFIX", lkNone, BtPathname)
	usrpkg("RSSH_SCP_PATH", lkNone, BtPathname)
	usrpkg("RSSH_SFTP_SERVER_PATH", lkNone, BtPathname)
	usrpkg("RSSH_CVS_PATH", lkNone, BtPathname)
	usrpkg("RSSH_RDIST_PATH", lkNone, BtPathname)
	usrpkg("RSSH_RSYNC_PATH", lkNone, BtPathname)
	usrpkg("SAWFISH_THEMES", lkShell, BtFileName)
	usrpkg("SCREWS_GROUP", lkNone, BtUserGroupName)
	usrpkg("SCREWS_USER", lkNone, BtUserGroupName)
	usrpkg("SDIST_PAWD", lkNone, enum("pawd pwd"))
	usrpkg("SERIAL_DEVICES", lkShell, BtPathname)
	usrpkg("SILC_CLIENT_WITH_PERL", lkNone, BtYesNo)
	usrpkg("SSH_SUID", lkNone, BtYesNo)
	usrpkg("SSYNC_PAWD", lkNone, enum("pawd pwd"))
	usrpkg("SUSE_PREFER", lkNone, enum("13.1 12.1 10.0"))
	usrpkg("TEXMFSITE", lkNone, BtPathname)
	usrpkg("THTTPD_LOG_FACILITY", lkNone, BtIdentifier)
	usrpkg("UNPRIVILEGED", lkNone, BtYesNo)
	usrpkg("USE_CROSS_COMPILE", lkNone, BtYesNo)
	usrpkg("USERPPP_GROUP", lkNone, BtUserGroupName)
	usrpkg("UUCP_GROUP", lkNone, BtUserGroupName)
	usrpkg("UUCP_USER", lkNone, BtUserGroupName)
	usrpkg("VIM_EXTRA_OPTS", lkShell, BtShellWord)
	usrpkg("WCALC_HTMLDIR", lkNone, BtPathname)
	usrpkg("WCALC_HTMLPATH", lkNone, BtPathname) // URL path
	usrpkg("WCALC_CGIDIR", lkNone, BtPrefixPathname)
	usrpkg("WCALC_CGIPATH", lkNone, BtPathname) // URL path
	usrpkg("WDM_MANAGERS", lkShell, BtIdentifier)
	usrpkg("X10_PORT", lkNone, BtPathname)
	usrpkg("XAW_TYPE", lkNone, enum("standard 3d xpm neXtaw"))
	usrpkg("XLOCK_DEFAULT_MODE", lkNone, BtIdentifier)
	usrpkg("ZSH_STATIC", lkNone, BtYes)

	// some other variables, sorted alphabetically

	acl(".CURDIR", lkNone, BtPathname, "buildlink3.mk:; *: use, use-loadtime")
	acl(".TARGET", lkNone, BtPathname, "buildlink3.mk:; *: use, use-loadtime")
	acl("@", lkNone, BtPathname, "buildlink3.mk:; *: use, use-loadtime")
	acl("ALL_ENV", lkShell, BtShellWord, "")
	acl("ALTERNATIVES_FILE", lkNone, BtFileName, "")
	acl("ALTERNATIVES_SRC", lkShell, BtPathname, "")
	pkg("APACHE_MODULE", lkNone, BtYes)
	sys("AR", lkNone, BtShellCommand)
	sys("AS", lkNone, BtShellCommand)
	pkglist("AUTOCONF_REQD", lkShell, BtVersion)
	acl("AUTOMAKE_OVERRIDE", lkShell, BtPathmask, "")
	pkglist("AUTOMAKE_REQD", lkShell, BtVersion)
	pkg("AUTO_MKDIRS", lkNone, BtYesNo)
	usr("BATCH", lkNone, BtYes)
	acl("BDB185_DEFAULT", lkNone, BtUnknown, "")
	sys("BDBBASE", lkNone, BtPathname)
	pkg("BDB_ACCEPTED", lkShell, enum("db1 db2 db3 db4 db5 db6"))
	acl("BDB_DEFAULT", lkNone, enum("db1 db2 db3 db4 db5 db6"), "")
	sys("BDB_LIBS", lkShell, BtLdFlag)
	sys("BDB_TYPE", lkNone, enum("db1 db2 db3 db4 db5 db6"))
	sys("BIGENDIANPLATFORMS", lkSpace, BtMachinePlatformPattern)
	sys("BINGRP", lkNone, BtUserGroupName)
	sys("BINMODE", lkNone, BtFileMode)
	sys("BINOWN", lkNone, BtUserGroupName)
	acl("BOOTSTRAP_DEPENDS", lkSpace, BtDependencyWithPath, "Makefile, Makefile.common, *.mk: append")
	pkg("BOOTSTRAP_PKG", lkNone, BtYesNo)
	acl("BROKEN", lkNone, BtMessage, "")
	pkg("BROKEN_GETTEXT_DETECTION", lkNone, BtYesNo)
	pkglist("BROKEN_EXCEPT_ON_PLATFORM", lkSpace, BtMachinePlatformPattern)
	pkglist("BROKEN_ON_PLATFORM", lkSpace, BtMachinePlatformPattern)
	sys("BSD_MAKE_ENV", lkShell, BtShellWord)
	acl("BUILDLINK_ABI_DEPENDS.*", lkSpace, BtDependency, "buildlink3.mk, builtin.mk: append, use-loadtime; *: append")
	acl("BUILDLINK_API_DEPENDS.*", lkSpace, BtDependency, "buildlink3.mk, builtin.mk: append, use-loadtime; *: append")
	acl("BUILDLINK_AUTO_DIRS.*", lkNone, BtYesNo, "buildlink3.mk: append")
	acl("BUILDLINK_CONTENTS_FILTER", lkNone, BtShellCommand, "")
	sys("BUILDLINK_CFLAGS", lkShell, BtCFlag)
	bl3list("BUILDLINK_CFLAGS.*", lkShell, BtCFlag)
	sys("BUILDLINK_CPPFLAGS", lkShell, BtCFlag)
	bl3list("BUILDLINK_CPPFLAGS.*", lkShell, BtCFlag)
	acl("BUILDLINK_CONTENTS_FILTER.*", lkNone, BtShellCommand, "buildlink3.mk: set")
	acl("BUILDLINK_DEPENDS", lkSpace, BtIdentifier, "buildlink3.mk: append")
	acl("BUILDLINK_DEPMETHOD.*", lkShell, BtBuildlinkDepmethod, "buildlink3.mk: default, append, use; Makefile: set, append; Makefile.common, *.mk: append")
	acl("BUILDLINK_DIR", lkNone, BtPathname, "*: use")
	bl3list("BUILDLINK_FILES.*", lkShell, BtPathmask)
	acl("BUILDLINK_FILES_CMD.*", lkNone, BtShellCommand, "")
	acl("BUILDLINK_INCDIRS.*", lkShell, BtPathname, "buildlink3.mk: default, append; Makefile, Makefile.common, *.mk: use")
	acl("BUILDLINK_JAVA_PREFIX.*", lkNone, BtPathname, "buildlink3.mk: set, use")
	acl("BUILDLINK_LDADD.*", lkShell, BtLdFlag, "builtin.mk: set, default, append, use; buildlink3.mk: append, use; Makefile, Makefile.common, *.mk: use")
	acl("BUILDLINK_LDFLAGS", lkShell, BtLdFlag, "*: use")
	bl3list("BUILDLINK_LDFLAGS.*", lkShell, BtLdFlag)
	acl("BUILDLINK_LIBDIRS.*", lkShell, BtPathname, "buildlink3.mk, builtin.mk: append; Makefile, Makefile.common, *.mk: use")
	acl("BUILDLINK_LIBS.*", lkShell, BtLdFlag, "buildlink3.mk: append")
	acl("BUILDLINK_PASSTHRU_DIRS", lkShell, BtPathname, "Makefile, Makefile.common, buildlink3.mk, hacks.mk: append")
	acl("BUILDLINK_PASSTHRU_RPATHDIRS", lkShell, BtPathname, "Makefile, Makefile.common, buildlink3.mk, hacks.mk: append")
	acl("BUILDLINK_PKGSRCDIR.*", lkNone, BtRelativePkgDir, "buildlink3.mk: default, use-loadtime")
	acl("BUILDLINK_PREFIX.*", lkNone, BtPathname, "builtin.mk: set, use; Makefile, Makefile.common, *.mk: use")
	acl("BUILDLINK_RPATHDIRS.*", lkShell, BtPathname, "buildlink3.mk: append")
	acl("BUILDLINK_TARGETS", lkShell, BtIdentifier, "")
	acl("BUILDLINK_FNAME_TRANSFORM.*", lkNone, BtSedCommands, "Makefile, buildlink3.mk, builtin.mk, hacks.mk: append")
	acl("BUILDLINK_TRANSFORM", lkShell, BtWrapperTransform, "*: append")
	acl("BUILDLINK_TRANSFORM.*", lkShell, BtWrapperTransform, "*: append")
	acl("BUILDLINK_TREE", lkShell, BtIdentifier, "buildlink3.mk: append")
	acl("BUILDLINK_X11_DIR", lkNone, BtPathname, "*: use")
	acl("BUILD_DEFS", lkShell, BtVariableName, "Makefile, Makefile.common, options.mk: append")
	pkglist("BUILD_DEFS_EFFECTS", lkShell, BtVariableName)
	acl("BUILD_DEPENDS", lkSpace, BtDependencyWithPath, "Makefile, Makefile.common, *.mk: append")
	pkglist("BUILD_DIRS", lkShell, BtWrksrcSubdirectory)
	pkglist("BUILD_ENV", lkShell, BtShellWord)
	sys("BUILD_MAKE_CMD", lkNone, BtShellCommand)
	pkglist("BUILD_MAKE_FLAGS", lkShell, BtShellWord)
	pkglist("BUILD_TARGET", lkShell, BtIdentifier)
	pkglist("BUILD_TARGET.*", lkShell, BtIdentifier)
	pkg("BUILD_USES_MSGFMT", lkNone, BtYes)
	acl("BUILTIN_PKG", lkNone, BtIdentifier, "builtin.mk: set, use-loadtime, use")
	acl("BUILTIN_PKG.*", lkNone, BtPkgName, "builtin.mk: set, use-loadtime, use")
	acl("BUILTIN_FIND_FILES_VAR", lkShell, BtVariableName, "builtin.mk: set")
	acl("BUILTIN_FIND_FILES.*", lkShell, BtPathname, "builtin.mk: set")
	acl("BUILTIN_FIND_GREP.*", lkNone, BtUnknown, "builtin.mk: set")
	acl("BUILTIN_FIND_HEADERS_VAR", lkShell, BtVariableName, "builtin.mk: set")
	acl("BUILTIN_FIND_HEADERS.*", lkShell, BtPathname, "builtin.mk: set")
	acl("BUILTIN_FIND_LIBS", lkShell, BtPathname, "builtin.mk: set")
	acl("BUILTIN_IMAKE_CHECK", lkShell, BtUnknown, "builtin.mk: set")
	acl("BUILTIN_IMAKE_CHECK.*", lkNone, BtYesNo, "")
	sys("BUILTIN_X11_TYPE", lkNone, BtUnknown)
	sys("BUILTIN_X11_VERSION", lkNone, BtUnknown)
	acl("CATEGORIES", lkShell, BtCategory, "Makefile: set, append; Makefile.common: set, default, append")
	sysload("CC_VERSION", lkNone, BtMessage)
	sysload("CC", lkNone, BtShellCommand)
	pkglist("CFLAGS", lkShell, BtCFlag)   // may also be changed by the user
	pkglist("CFLAGS.*", lkShell, BtCFlag) // may also be changed by the user
	acl("CHECK_BUILTIN", lkNone, BtYesNo, "builtin.mk: default; Makefile: set")
	acl("CHECK_BUILTIN.*", lkNone, BtYesNo, "Makefile, options.mk, buildlink3.mk: set; builtin.mk: default, use-loadtime; *: use-loadtime")
	acl("CHECK_FILES_SKIP", lkShell, BtBasicRegularExpression, "Makefile, Makefile.common: append")
	pkg("CHECK_FILES_SUPPORTED", lkNone, BtYesNo)
	usr("CHECK_HEADERS", lkNone, BtYesNo)
	pkglist("CHECK_HEADERS_SKIP", lkShell, BtPathmask)
	usr("CHECK_INTERPRETER", lkNone, BtYesNo)
	pkglist("CHECK_INTERPRETER_SKIP", lkShell, BtPathmask)
	usr("CHECK_PERMS", lkNone, BtYesNo)
	pkglist("CHECK_PERMS_SKIP", lkShell, BtPathmask)
	usr("CHECK_PORTABILITY", lkNone, BtYesNo)
	pkglist("CHECK_PORTABILITY_SKIP", lkShell, BtPathmask)
	usr("CHECK_RELRO", lkNone, BtYesNo)
	pkglist("CHECK_RELRO_SKIP", lkShell, BtPathmask)
	pkg("CHECK_RELRO_SUPPORTED", lkNone, BtYesNo)
	acl("CHECK_SHLIBS", lkNone, BtYesNo, "Makefile: set")
	pkglist("CHECK_SHLIBS_SKIP", lkShell, BtPathmask)
	acl("CHECK_SHLIBS_SUPPORTED", lkNone, BtYesNo, "Makefile: set")
	pkglist("CHECK_WRKREF_SKIP", lkShell, BtPathmask)
	pkg("CMAKE_ARG_PATH", lkNone, BtPathname)
	pkglist("CMAKE_ARGS", lkShell, BtShellWord)
	pkglist("CMAKE_ARGS.*", lkShell, BtShellWord)
	pkglist("CMAKE_DEPENDENCIES_REWRITE", lkShell, BtPathmask) // Relative to WRKSRC
	pkglist("CMAKE_MODULE_PATH_OVERRIDE", lkShell, BtPathmask) // Relative to WRKSRC
	pkg("CMAKE_PKGSRC_BUILD_FLAGS", lkNone, BtYesNo)
	pkglist("CMAKE_PREFIX_PATH", lkShell, BtPathmask)
	pkglist("CMAKE_USE_GNU_INSTALL_DIRS", lkNone, BtYesNo)
	pkg("CMAKE_INSTALL_PREFIX", lkNone, BtPathname) // The default is ${PREFIX}.
	acl("COMMENT", lkNone, BtComment, "Makefile, Makefile.common: set, append")
	sys("COMPILE.*", lkNone, BtShellCommand)
	acl("COMPILER_RPATH_FLAG", lkNone, enum("-Wl,-rpath"), "*: use")
	pkglist("CONFIGURE_ARGS", lkShell, BtShellWord)
	pkglist("CONFIGURE_ARGS.*", lkShell, BtShellWord)
	pkglist("CONFIGURE_DIRS", lkShell, BtWrksrcSubdirectory)
	acl("CONFIGURE_ENV", lkShell, BtShellWord, "Makefile, Makefile.common: append, set, use; buildlink3.mk, builtin.mk: append; *.mk: append, use")
	acl("CONFIGURE_ENV.*", lkShell, BtShellWord, "Makefile, Makefile.common: append, set, use; buildlink3.mk, builtin.mk: append; *.mk: append, use")
	pkg("CONFIGURE_HAS_INFODIR", lkNone, BtYesNo)
	pkg("CONFIGURE_HAS_LIBDIR", lkNone, BtYesNo)
	pkg("CONFIGURE_HAS_MANDIR", lkNone, BtYesNo)
	pkg("CONFIGURE_SCRIPT", lkNone, BtPathname)
	acl("CONFIG_GUESS_OVERRIDE", lkShell, BtPathmask, "Makefile, Makefile.common: set, append")
	acl("CONFIG_STATUS_OVERRIDE", lkShell, BtPathmask, "Makefile, Makefile.common: set, append")
	acl("CONFIG_SHELL", lkNone, BtPathname, "Makefile, Makefile.common: set")
	acl("CONFIG_SUB_OVERRIDE", lkShell, BtPathmask, "Makefile, Makefile.common: set, append")
	pkglist("CONFLICTS", lkSpace, BtDependency)
	pkglist("CONF_FILES", lkNone, BtConfFiles)
	pkg("CONF_FILES_MODE", lkNone, enum("0644 0640 0600 0400"))
	pkglist("CONF_FILES_PERMS", lkShell, BtPerms)
	sys("COPY", lkNone, enum("-c")) // The flag that tells ${INSTALL} to copy a file
	sys("CPP", lkNone, BtShellCommand)
	pkglist("CPPFLAGS", lkShell, BtCFlag)
	pkglist("CPPFLAGS.*", lkShell, BtCFlag)
	sys("CXX", lkNone, BtShellCommand)
	pkglist("CXXFLAGS", lkShell, BtCFlag)
	pkglist("CXXFLAGS.*", lkShell, BtCFlag)
	pkglist("CWRAPPERS_APPEND.*", lkShell, BtShellWord)
	sys("DEFAULT_DISTFILES", lkShell, BtFetchURL) // From mk/fetch/bsd.fetch-vars.mk.
	acl("DEINSTALL_FILE", lkNone, BtPathname, "Makefile: set")
	acl("DEINSTALL_SRC", lkShell, BtPathname, "Makefile: set; Makefile.common: default, set")
	acl("DEINSTALL_TEMPLATES", lkShell, BtPathname, "Makefile: set, append; Makefile.common: set, default, append")
	sys("DELAYED_ERROR_MSG", lkNone, BtShellCommand)
	sys("DELAYED_WARNING_MSG", lkNone, BtShellCommand)
	pkglist("DEPENDS", lkSpace, BtDependencyWithPath)
	usr("DEPENDS_TARGET", lkShell, BtIdentifier)
	acl("DESCR_SRC", lkShell, BtPathname, "Makefile: set, append; Makefile.common: default, set")
	sys("DESTDIR", lkNone, BtPathname)
	acl("DESTDIR_VARNAME", lkNone, BtVariableName, "Makefile, Makefile.common: set")
	sys("DEVOSSAUDIO", lkNone, BtPathname)
	sys("DEVOSSSOUND", lkNone, BtPathname)
	pkglist("DISTFILES", lkShell, BtFileName)
	pkg("DISTINFO_FILE", lkNone, BtRelativePkgPath)
	pkg("DISTNAME", lkNone, BtFileName)
	pkg("DIST_SUBDIR", lkNone, BtPathname)
	acl("DJB_BUILD_ARGS", lkShell, BtShellWord, "")
	acl("DJB_BUILD_TARGETS", lkShell, BtIdentifier, "")
	acl("DJB_CONFIG_CMDS", lkNone, BtShellCommands, "options.mk: set")
	acl("DJB_CONFIG_DIRS", lkShell, BtWrksrcSubdirectory, "")
	acl("DJB_CONFIG_HOME", lkNone, BtFileName, "")
	acl("DJB_CONFIG_PREFIX", lkNone, BtPathname, "")
	acl("DJB_INSTALL_TARGETS", lkShell, BtIdentifier, "")
	acl("DJB_MAKE_TARGETS", lkNone, BtYesNo, "")
	acl("DJB_RESTRICTED", lkNone, BtYesNo, "Makefile: set")
	acl("DJB_SLASHPACKAGE", lkNone, BtYesNo, "")
	acl("DLOPEN_REQUIRE_PTHREADS", lkNone, BtYesNo, "")
	acl("DL_AUTO_VARS", lkNone, BtYes, "Makefile, Makefile.common, options.mk: set")
	acl("DL_LIBS", lkShell, BtLdFlag, "")
	sys("DOCOWN", lkNone, BtUserGroupName)
	sys("DOCGRP", lkNone, BtUserGroupName)
	sys("DOCMODE", lkNone, BtFileMode)
	sys("DOWNLOADED_DISTFILE", lkNone, BtPathname)
	sys("DO_NADA", lkNone, BtShellCommand)
	pkg("DYNAMIC_SITES_CMD", lkNone, BtShellCommand)
	pkg("DYNAMIC_SITES_SCRIPT", lkNone, BtPathname)
	acl("ECHO", lkNone, BtShellCommand, "*: use")
	sys("ECHO_MSG", lkNone, BtShellCommand)
	sys("ECHO_N", lkNone, BtShellCommand)
	pkg("EGDIR", lkNone, BtPathname) // Not defined anywhere but used in many places like this.
	sys("EMACS_BIN", lkNone, BtPathname)
	sys("EMACS_ETCPREFIX", lkNone, BtPathname)
	sys("EMACS_FLAVOR", lkNone, enum("emacs xemacs"))
	sys("EMACS_INFOPREFIX", lkNone, BtPathname)
	sys("EMACS_LISPPREFIX", lkNone, BtPathname)
	acl("EMACS_MODULES", lkShell, BtIdentifier, "Makefile, Makefile.common: set, append")
	sys("EMACS_PKGNAME_PREFIX", lkNone, BtIdentifier) // Or the empty string.
	sys("EMACS_TYPE", lkNone, enum("emacs xemacs"))
	acl("EMACS_USE_LEIM", lkNone, BtYes, "")
	acl("EMACS_VERSIONS_ACCEPTED", lkShell, emacsVersions, "Makefile: set")
	sys("EMACS_VERSION_MAJOR", lkNone, BtInteger)
	sys("EMACS_VERSION_MINOR", lkNone, BtInteger)
	acl("EMACS_VERSION_REQD", lkShell, emacsVersions, "Makefile: set, append")
	sys("EMULDIR", lkNone, BtPathname)
	sys("EMULSUBDIR", lkNone, BtPathname)
	sys("OPSYS_EMULDIR", lkNone, BtPathname)
	sys("EMULSUBDIRSLASH", lkNone, BtPathname)
	sys("EMUL_ARCH", lkNone, enum("arm i386 m68k none ns32k sparc vax x86_64"))
	sys("EMUL_DISTRO", lkNone, BtIdentifier)
	sys("EMUL_IS_NATIVE", lkNone, BtYes)
	pkg("EMUL_MODULES.*", lkShell, BtIdentifier)
	sys("EMUL_OPSYS", lkNone, enum("darwin freebsd hpux irix linux osf1 solaris sunos none"))
	pkg("EMUL_PKG_FMT", lkNone, enum("plain rpm"))
	usr("EMUL_PLATFORM", lkNone, BtEmulPlatform)
	pkg("EMUL_PLATFORMS", lkSpace, BtEmulPlatform)
	usr("EMUL_PREFER", lkSpace, BtEmulPlatform)
	pkg("EMUL_REQD", lkSpace, BtDependency)
	usr("EMUL_TYPE.*", lkNone, enum("native builtin suse suse-9.1 suse-9.x suse-10.0 suse-10.x"))
	sys("ERROR_CAT", lkNone, BtShellCommand)
	sys("ERROR_MSG", lkNone, BtShellCommand)
	sys("EXPORT_SYMBOLS_LDFLAGS", lkShell, BtLdFlag)
	sys("EXTRACT_CMD", lkNone, BtShellCommand)
	pkg("EXTRACT_DIR", lkNone, BtPathname)
	pkg("EXTRACT_DIR.*", lkNone, BtPathname)
	pkglist("EXTRACT_ELEMENTS", lkShell, BtPathmask)
	pkglist("EXTRACT_ENV", lkShell, BtShellWord)
	pkglist("EXTRACT_ONLY", lkShell, BtPathname)
	acl("EXTRACT_OPTS", lkShell, BtShellWord, "Makefile, Makefile.common: set, append")
	acl("EXTRACT_OPTS_BIN", lkShell, BtShellWord, "Makefile, Makefile.common: set, append")
	acl("EXTRACT_OPTS_LHA", lkShell, BtShellWord, "Makefile, Makefile.common: set, append")
	acl("EXTRACT_OPTS_PAX", lkShell, BtShellWord, "Makefile, Makefile.common: set, append")
	acl("EXTRACT_OPTS_RAR", lkShell, BtShellWord, "Makefile, Makefile.common: set, append")
	acl("EXTRACT_OPTS_TAR", lkShell, BtShellWord, "Makefile, Makefile.common: set, append")
	acl("EXTRACT_OPTS_ZIP", lkShell, BtShellWord, "Makefile, Makefile.common: set, append")
	acl("EXTRACT_OPTS_ZOO", lkShell, BtShellWord, "Makefile, Makefile.common: set, append")
	pkg("EXTRACT_SUFX", lkNone, BtDistSuffix)
	pkg("EXTRACT_USING", lkNone, enum("bsdtar gtar nbtar pax"))
	sys("FAIL_MSG", lkNone, BtShellCommand)
	sys("FAMBASE", lkNone, BtPathname)
	pkg("FAM_ACCEPTED", lkShell, enum("fam gamin"))
	usr("FAM_DEFAULT", lkNone, enum("fam gamin"))
	sys("FAM_TYPE", lkNone, enum("fam gamin"))
	acl("FETCH_BEFORE_ARGS", lkShell, BtShellWord, "Makefile: set, append")
	pkglist("FETCH_MESSAGE", lkShell, BtShellWord)
	pkg("FILESDIR", lkNone, BtRelativePkgPath)
	pkglist("FILES_SUBST", lkShell, BtShellWord)
	acl("FILES_SUBST_SED", lkShell, BtShellWord, "")
	pkglist("FIX_RPATH", lkShell, BtVariableName)
	pkglist("FLEX_REQD", lkShell, BtVersion)
	acl("FONTS_DIRS.*", lkShell, BtPathname, "Makefile: set, append, use; Makefile.common: append, use")
	sys("GAMEDATAMODE", lkNone, BtFileMode)
	sys("GAMES_GROUP", lkNone, BtUserGroupName)
	sys("GAMEDATA_PERMS", lkShell, BtPerms)
	sys("GAMEDIR_PERMS", lkShell, BtPerms)
	sys("GAMEMODE", lkNone, BtFileMode)
	sys("GAMES_USER", lkNone, BtUserGroupName)
	pkglist("GCC_REQD", lkShell, BtGccReqd)
	pkglist("GENERATE_PLIST", lkNone, BtShellCommands)
	pkg("GITHUB_PROJECT", lkNone, BtIdentifier)
	pkg("GITHUB_TAG", lkNone, BtIdentifier)
	pkg("GITHUB_RELEASE", lkNone, BtFileName)
	pkg("GITHUB_TYPE", lkNone, enum("tag release"))
	pkg("GMAKE_REQD", lkNone, BtVersion)
	acl("GNU_ARCH", lkNone, enum("mips"), "")
	acl("GNU_ARCH.*", lkNone, BtIdentifier, "buildlink3.mk:; *: set, use")
	acl("GNU_CONFIGURE", lkNone, BtYes, "Makefile, Makefile.common: set")
	acl("GNU_CONFIGURE_INFODIR", lkNone, BtPathname, "Makefile, Makefile.common: set")
	acl("GNU_CONFIGURE_LIBDIR", lkNone, BtPathname, "Makefile, Makefile.common: set")
	pkg("GNU_CONFIGURE_LIBSUBDIR", lkNone, BtPathname)
	acl("GNU_CONFIGURE_MANDIR", lkNone, BtPathname, "Makefile, Makefile.common: set")
	acl("GNU_CONFIGURE_PREFIX", lkNone, BtPathname, "Makefile: set")
	pkg("GOPATH", lkNone, BtPathname)
	acl("HAS_CONFIGURE", lkNone, BtYes, "Makefile, Makefile.common: set")
	pkglist("HEADER_TEMPLATES", lkShell, BtPathname)
	pkg("HOMEPAGE", lkNone, BtHomepage)
	pkg("ICON_THEMES", lkNone, BtYes)
	acl("IGNORE_PKG.*", lkNone, BtYes, "*: set, use-loadtime")
	sys("IMAKE", lkNone, BtShellCommand)
	acl("INCOMPAT_CURSES", lkSpace, BtMachinePlatformPattern, "Makefile: set, append")
	acl("INCOMPAT_ICONV", lkSpace, BtMachinePlatformPattern, "")
	acl("INFO_DIR", lkNone, BtPathname, "") // relative to PREFIX
	pkg("INFO_FILES", lkNone, BtYes)
	sys("INSTALL", lkNone, BtShellCommand)
	pkglist("INSTALLATION_DIRS", lkShell, BtPrefixPathname)
	pkg("INSTALLATION_DIRS_FROM_PLIST", lkNone, BtYes)
	sys("INSTALL_DATA", lkNone, BtShellCommand)
	sys("INSTALL_DATA_DIR", lkNone, BtShellCommand)
	pkglist("INSTALL_DIRS", lkShell, BtWrksrcSubdirectory)
	pkglist("INSTALL_ENV", lkShell, BtShellWord)
	acl("INSTALL_FILE", lkNone, BtPathname, "Makefile: set")
	sys("INSTALL_GAME", lkNone, BtShellCommand)
	sys("INSTALL_GAME_DATA", lkNone, BtShellCommand)
	sys("INSTALL_LIB", lkNone, BtShellCommand)
	sys("INSTALL_LIB_DIR", lkNone, BtShellCommand)
	pkglist("INSTALL_MAKE_FLAGS", lkShell, BtShellWord)
	sys("INSTALL_MAN", lkNone, BtShellCommand)
	sys("INSTALL_MAN_DIR", lkNone, BtShellCommand)
	sys("INSTALL_PROGRAM", lkNone, BtShellCommand)
	sys("INSTALL_PROGRAM_DIR", lkNone, BtShellCommand)
	sys("INSTALL_SCRIPT", lkNone, BtShellCommand)
	acl("INSTALL_SCRIPTS_ENV", lkShell, BtShellWord, "")
	sys("INSTALL_SCRIPT_DIR", lkNone, BtShellCommand)
	acl("INSTALL_SRC", lkShell, BtPathname, "Makefile: set; Makefile.common: default, set")
	pkg("INSTALL_TARGET", lkShell, BtIdentifier)
	acl("INSTALL_TEMPLATES", lkShell, BtPathname, "Makefile: set, append; Makefile.common: set, default, append")
	acl("INSTALL_UNSTRIPPED", lkNone, BtYesNo, "Makefile, Makefile.common: set")
	pkg("INTERACTIVE_STAGE", lkShell, enum("fetch extract configure build test install"))
	acl("IS_BUILTIN.*", lkNone, BtYesNoIndirectly, "builtin.mk: set, use-loadtime, use")
	sys("JAVA_BINPREFIX", lkNone, BtPathname)
	pkg("JAVA_CLASSPATH", lkNone, BtShellWord)
	pkg("JAVA_HOME", lkNone, BtPathname)
	pkg("JAVA_NAME", lkNone, BtFileName)
	pkglist("JAVA_UNLIMIT", lkShell, enum("cmdsize datasize stacksize"))
	pkglist("JAVA_WRAPPERS", lkSpace, BtFileName)
	pkg("JAVA_WRAPPER_BIN.*", lkNone, BtPathname)
	sys("KRB5BASE", lkNone, BtPathname)
	acl("KRB5_ACCEPTED", lkShell, enum("heimdal mit-krb5"), "")
	usr("KRB5_DEFAULT", lkNone, enum("heimdal mit-krb5"))
	sys("KRB5_TYPE", lkNone, BtIdentifier)
	sys("LD", lkNone, BtShellCommand)
	pkglist("LDFLAGS", lkShell, BtLdFlag)
	pkglist("LDFLAGS.*", lkShell, BtLdFlag)
	sysload("LIBABISUFFIX", lkNone, BtIdentifier) // Can also be empty.
	sys("LIBGRP", lkNone, BtUserGroupName)
	sys("LIBMODE", lkNone, BtFileMode)
	sys("LIBOWN", lkNone, BtUserGroupName)
	sys("LIBOSSAUDIO", lkNone, BtPathname)
	pkglist("LIBS", lkShell, BtLdFlag)
	pkglist("LIBS.*", lkShell, BtLdFlag)
	sys("LIBTOOL", lkNone, BtShellCommand)
	acl("LIBTOOL_OVERRIDE", lkShell, BtPathmask, "Makefile: set, append")
	pkglist("LIBTOOL_REQD", lkShell, BtVersion)
	acl("LICENCE", lkNone, BtLicense, "Makefile, Makefile.common, options.mk: set, append")
	acl("LICENSE", lkNone, BtLicense, "Makefile, Makefile.common, options.mk: set, append")
	pkg("LICENSE_FILE", lkNone, BtPathname)
	sys("LINK.*", lkNone, BtShellCommand)
	sys("LINKER_RPATH_FLAG", lkNone, BtShellWord)
	sys("LITTLEENDIANPLATFORMS", lkSpace, BtMachinePlatformPattern)
	sys("LOWER_OPSYS", lkNone, BtIdentifier)
	sys("LOWER_VENDOR", lkNone, BtIdentifier)
	sys("LP64PLATFORMS", lkSpace, BtMachinePlatformPattern)
	acl("LTCONFIG_OVERRIDE", lkShell, BtPathmask, "Makefile: set, append; Makefile.common: append")
	sysload("MACHINE_ARCH", lkNone, enumMachineArch)
	sysload("MACHINE_GNU_ARCH", lkNone, enumMachineGnuArch)
	sysload("MACHINE_GNU_PLATFORM", lkNone, BtMachineGnuPlatform)
	sysload("MACHINE_PLATFORM", lkNone, BtMachinePlatform)
	acl("MAINTAINER", lkNone, BtMailAddress, "Makefile: set; Makefile.common: default")
	sysload("MAKE", lkNone, BtShellCommand)
	pkglist("MAKEFLAGS", lkShell, BtShellWord)
	acl("MAKEVARS", lkShell, BtVariableName, "buildlink3.mk, builtin.mk, hacks.mk: append")
	pkglist("MAKE_DIRS", lkShell, BtPathname)
	pkglist("MAKE_DIRS_PERMS", lkShell, BtPerms)
	acl("MAKE_ENV", lkShell, BtShellWord, "Makefile, Makefile.common: append, set, use; buildlink3.mk, builtin.mk: append; *.mk: append, use")
	acl("MAKE_ENV.*", lkShell, BtShellWord, "Makefile, Makefile.common: append, set, use; buildlink3.mk, builtin.mk: append; *.mk: append, use")
	pkg("MAKE_FILE", lkNone, BtPathname)
	pkglist("MAKE_FLAGS", lkShell, BtShellWord)
	pkglist("MAKE_FLAGS.*", lkShell, BtShellWord)
	usr("MAKE_JOBS", lkNone, BtInteger)
	pkg("MAKE_JOBS_SAFE", lkNone, BtYesNo)
	pkg("MAKE_PROGRAM", lkNone, BtShellCommand)
	acl("MANCOMPRESSED", lkNone, BtYesNo, "Makefile: set; Makefile.common: default, set")
	acl("MANCOMPRESSED_IF_MANZ", lkNone, BtYes, "Makefile: set; Makefile.common: default, set")
	sys("MANGRP", lkNone, BtUserGroupName)
	sys("MANMODE", lkNone, BtFileMode)
	sys("MANOWN", lkNone, BtUserGroupName)
	pkglist("MASTER_SITES", lkShell, BtFetchURL)
	sys("MASTER_SITE_APACHE", lkShell, BtFetchURL)
	sys("MASTER_SITE_BACKUP", lkShell, BtFetchURL)
	sys("MASTER_SITE_CRATESIO", lkShell, BtFetchURL)
	sys("MASTER_SITE_CYGWIN", lkShell, BtFetchURL)
	sys("MASTER_SITE_DEBIAN", lkShell, BtFetchURL)
	sys("MASTER_SITE_FREEBSD", lkShell, BtFetchURL)
	sys("MASTER_SITE_FREEBSD_LOCAL", lkShell, BtFetchURL)
	sys("MASTER_SITE_GENTOO", lkShell, BtFetchURL)
	sys("MASTER_SITE_GITHUB", lkShell, BtFetchURL)
	sys("MASTER_SITE_GNOME", lkShell, BtFetchURL)
	sys("MASTER_SITE_GNU", lkShell, BtFetchURL)
	sys("MASTER_SITE_GNUSTEP", lkShell, BtFetchURL)
	sys("MASTER_SITE_IFARCHIVE", lkShell, BtFetchURL)
	sys("MASTER_SITE_HASKELL_HACKAGE", lkShell, BtFetchURL)
	sys("MASTER_SITE_KDE", lkShell, BtFetchURL)
	sys("MASTER_SITE_LOCAL", lkShell, BtFetchURL)
	sys("MASTER_SITE_MOZILLA", lkShell, BtFetchURL)
	sys("MASTER_SITE_MOZILLA_ALL", lkShell, BtFetchURL)
	sys("MASTER_SITE_MOZILLA_ESR", lkShell, BtFetchURL)
	sys("MASTER_SITE_MYSQL", lkShell, BtFetchURL)
	sys("MASTER_SITE_NETLIB", lkShell, BtFetchURL)
	sys("MASTER_SITE_OPENBSD", lkShell, BtFetchURL)
	sys("MASTER_SITE_OPENOFFICE", lkShell, BtFetchURL)
	sys("MASTER_SITE_OSDN", lkShell, BtFetchURL)
	sys("MASTER_SITE_PERL_CPAN", lkShell, BtFetchURL)
	sys("MASTER_SITE_PGSQL", lkShell, BtFetchURL)
	sys("MASTER_SITE_PYPI", lkShell, BtFetchURL)
	sys("MASTER_SITE_R_CRAN", lkShell, BtFetchURL)
	sys("MASTER_SITE_RUBYGEMS", lkShell, BtFetchURL)
	sys("MASTER_SITE_SOURCEFORGE", lkShell, BtFetchURL)
	sys("MASTER_SITE_SUNSITE", lkShell, BtFetchURL)
	sys("MASTER_SITE_SUSE", lkShell, BtFetchURL)
	sys("MASTER_SITE_TEX_CTAN", lkShell, BtFetchURL)
	sys("MASTER_SITE_XCONTRIB", lkShell, BtFetchURL)
	sys("MASTER_SITE_XEMACS", lkShell, BtFetchURL)
	sys("MASTER_SITE_XORG", lkShell, BtFetchURL)
	pkglist("MESSAGE_SRC", lkShell, BtPathname)
	acl("MESSAGE_SUBST", lkShell, BtShellWord, "Makefile, Makefile.common, options.mk: append")
	pkg("META_PACKAGE", lkNone, BtYes)
	sys("MISSING_FEATURES", lkShell, BtIdentifier)
	acl("MYSQL_VERSIONS_ACCEPTED", lkShell, mysqlVersions, "Makefile: set")
	usr("MYSQL_VERSION_DEFAULT", lkNone, BtVersion)
	sys("NATIVE_CC", lkNone, BtShellCommand) // See mk/platform/tools.NetBSD.mk (and some others).
	sys("NM", lkNone, BtShellCommand)
	sys("NONBINMODE", lkNone, BtFileMode)
	pkg("NOT_FOR_COMPILER", lkShell, compilers)
	pkglist("NOT_FOR_BULK_PLATFORM", lkSpace, BtMachinePlatformPattern)
	pkglist("NOT_FOR_PLATFORM", lkSpace, BtMachinePlatformPattern)
	pkg("NOT_FOR_UNPRIVILEGED", lkNone, BtYesNo)
	pkglist("NOT_PAX_ASLR_SAFE", lkShell, BtPathmask)
	pkglist("NOT_PAX_MPROTECT_SAFE", lkShell, BtPathmask)
	acl("NO_BIN_ON_CDROM", lkNone, BtRestricted, "Makefile, Makefile.common: set")
	acl("NO_BIN_ON_FTP", lkNone, BtRestricted, "Makefile, Makefile.common: set")
	acl("NO_BUILD", lkNone, BtYes, "Makefile, Makefile.common: set; Makefile.*: default, set")
	pkg("NO_CHECKSUM", lkNone, BtYes)
	pkg("NO_CONFIGURE", lkNone, BtYes)
	acl("NO_EXPORT_CPP", lkNone, BtYes, "Makefile: set")
	pkg("NO_EXTRACT", lkNone, BtYes)
	pkg("NO_INSTALL_MANPAGES", lkNone, BtYes) // only has an effect for Imake packages.
	acl("NO_PKGTOOLS_REQD_CHECK", lkNone, BtYes, "Makefile: set")
	acl("NO_SRC_ON_CDROM", lkNone, BtRestricted, "Makefile, Makefile.common: set")
	acl("NO_SRC_ON_FTP", lkNone, BtRestricted, "Makefile, Makefile.common: set")
	sysload("OBJECT_FMT", lkNone, enum("COFF ECOFF ELF SOM XCOFF Mach-O PE a.out"))
	pkglist("ONLY_FOR_COMPILER", lkShell, compilers)
	pkglist("ONLY_FOR_PLATFORM", lkSpace, BtMachinePlatformPattern)
	pkg("ONLY_FOR_UNPRIVILEGED", lkNone, BtYesNo)
	sysload("OPSYS", lkNone, BtIdentifier)
	acl("OPSYSVARS", lkShell, BtVariableName, "Makefile, Makefile.common: append")
	acl("OSVERSION_SPECIFIC", lkNone, BtYes, "Makefile, Makefile.common: set")
	sysload("OS_VERSION", lkNone, BtVersion)
	sysload("OSX_VERSION", lkNone, BtVersion) // See mk/platform/Darwin.mk.
	pkg("OVERRIDE_DIRDEPTH*", lkNone, BtInteger)
	pkg("OVERRIDE_GNU_CONFIG_SCRIPTS", lkNone, BtYes)
	acl("OWNER", lkNone, BtMailAddress, "Makefile: set; Makefile.common: default")
	pkglist("OWN_DIRS", lkShell, BtPathname)
	pkglist("OWN_DIRS_PERMS", lkShell, BtPerms)
	sys("PAMBASE", lkNone, BtPathname)
	usr("PAM_DEFAULT", lkNone, enum("linux-pam openpam solaris-pam"))
	acl("PATCHDIR", lkNone, BtRelativePkgPath, "Makefile: set; Makefile.common: default, set")
	pkglist("PATCHFILES", lkShell, BtFileName)
	acl("PATCH_ARGS", lkShell, BtShellWord, "")
	acl("PATCH_DIST_ARGS", lkShell, BtShellWord, "Makefile: set, append")
	acl("PATCH_DIST_CAT", lkNone, BtShellCommand, "")
	acl("PATCH_DIST_STRIP*", lkNone, BtShellWord, "buildlink3.mk, builtin.mk:; Makefile, Makefile.common, *.mk: set")
	acl("PATCH_SITES", lkShell, BtFetchURL, "Makefile, Makefile.common, options.mk: set")
	acl("PATCH_STRIP", lkNone, BtShellWord, "")
	sys("PATH", lkNone, BtPathlist)       // From the PATH environment variable.
	sys("PAXCTL", lkNone, BtShellCommand) // See mk/pax.mk.
	acl("PERL5_PACKLIST", lkShell, BtPerl5Packlist, "Makefile: set; options.mk: set, append")
	acl("PERL5_PACKLIST_DIR", lkNone, BtPathname, "")
	pkg("PERL5_REQD", lkShell, BtVersion)
	sys("PERL5_INSTALLARCHLIB", lkNone, BtPathname) // See lang/perl5/vars.mk
	sys("PERL5_INSTALLSCRIPT", lkNone, BtPathname)
	sys("PERL5_INSTALLVENDORBIN", lkNone, BtPathname)
	sys("PERL5_INSTALLVENDORSCRIPT", lkNone, BtPathname)
	sys("PERL5_INSTALLVENDORARCH", lkNone, BtPathname)
	sys("PERL5_INSTALLVENDORLIB", lkNone, BtPathname)
	sys("PERL5_INSTALLVENDORMAN1DIR", lkNone, BtPathname)
	sys("PERL5_INSTALLVENDORMAN3DIR", lkNone, BtPathname)
	sys("PERL5_SUB_INSTALLARCHLIB", lkNone, BtPrefixPathname) // See lang/perl5/vars.mk
	sys("PERL5_SUB_INSTALLSCRIPT", lkNone, BtPrefixPathname)
	sys("PERL5_SUB_INSTALLVENDORBIN", lkNone, BtPrefixPathname)
	sys("PERL5_SUB_INSTALLVENDORSCRIPT", lkNone, BtPrefixPathname)
	sys("PERL5_SUB_INSTALLVENDORARCH", lkNone, BtPrefixPathname)
	sys("PERL5_SUB_INSTALLVENDORLIB", lkNone, BtPrefixPathname)
	sys("PERL5_SUB_INSTALLVENDORMAN1DIR", lkNone, BtPrefixPathname)
	sys("PERL5_SUB_INSTALLVENDORMAN3DIR", lkNone, BtPrefixPathname)
	pkg("PERL5_USE_PACKLIST", lkNone, BtYesNo)
	sys("PGSQL_PREFIX", lkNone, BtPathname)
	acl("PGSQL_VERSIONS_ACCEPTED", lkShell, pgsqlVersions, "")
	usr("PGSQL_VERSION_DEFAULT", lkNone, BtVersion)
	sys("PG_LIB_EXT", lkNone, enum("dylib so"))
	sys("PGSQL_TYPE", lkNone, enum("postgresql81-client postgresql80-client"))
	sys("PGPKGSRCDIR", lkNone, BtPathname)
	sys("PHASE_MSG", lkNone, BtShellCommand)
	usr("PHP_VERSION_REQD", lkNone, BtVersion)
	sys("PKGBASE", lkNone, BtIdentifier)
	acl("PKGCONFIG_FILE.*", lkShell, BtPathname, "builtin.mk: set, append; pkgconfig-builtin.mk: use-loadtime")
	acl("PKGCONFIG_OVERRIDE", lkShell, BtPathmask, "Makefile: set, append; Makefile.common: append")
	pkg("PKGCONFIG_OVERRIDE_STAGE", lkNone, BtStage)
	pkg("PKGDIR", lkNone, BtRelativePkgDir)
	sys("PKGDIRMODE", lkNone, BtFileMode)
	sys("PKGLOCALEDIR", lkNone, BtPathname)
	pkg("PKGNAME", lkNone, BtPkgName)
	sys("PKGNAME_NOREV", lkNone, BtPkgName)
	sysload("PKGPATH", lkNone, BtPathname)
	acl("PKGREPOSITORY", lkNone, BtUnknown, "")
	acl("PKGREVISION", lkNone, BtPkgRevision, "Makefile: set")
	sys("PKGSRCDIR", lkNone, BtPathname)
	acl("PKGSRCTOP", lkNone, BtYes, "Makefile: set")
	sys("PKGSRC_SETENV", lkNone, BtShellCommand)
	acl("PKGTOOLS_ENV", lkShell, BtShellWord, "")
	sys("PKGVERSION", lkNone, BtVersion)
	sys("PKGVERSION_NOREV", lkNone, BtVersion) // Without the nb* part.
	sys("PKGWILDCARD", lkNone, BtFileMask)
	sys("PKG_ADMIN", lkNone, BtShellCommand)
	sys("PKG_APACHE", lkNone, enum("apache24"))
	pkg("PKG_APACHE_ACCEPTED", lkShell, enum("apache24"))
	usr("PKG_APACHE_DEFAULT", lkNone, enum("apache24"))
	sysload("PKG_BUILD_OPTIONS.*", lkShell, BtOption)
	usr("PKG_CONFIG", lkNone, BtYes)
	// ^^ No, this is not the popular command from GNOME, but the setting
	// whether the pkgsrc user wants configuration files automatically
	// installed or not.
	sys("PKG_CREATE", lkNone, BtShellCommand)
	sys("PKG_DBDIR", lkNone, BtPathname)
	cmdline("PKG_DEBUG_LEVEL", lkNone, BtInteger)
	usr("PKG_DEFAULT_OPTIONS", lkShell, BtOption)
	sys("PKG_DELETE", lkNone, BtShellCommand)
	acl("PKG_DESTDIR_SUPPORT", lkShell, enum("destdir user-destdir"), "Makefile, Makefile.common: set")
	pkglist("PKG_FAIL_REASON", lkShell, BtShellWord)
	sysload("PKG_FORMAT", lkNone, BtIdentifier)
	acl("PKG_GECOS.*", lkNone, BtMessage, "Makefile: set")
	acl("PKG_GID.*", lkNone, BtInteger, "Makefile: set")
	acl("PKG_GROUPS", lkShell, BtShellWord, "Makefile: set, append")
	pkglist("PKG_GROUPS_VARS", lkShell, BtVariableName)
	acl("PKG_HOME.*", lkNone, BtPathname, "Makefile: set")
	acl("PKG_HACKS", lkShell, BtIdentifier, "hacks.mk: append")
	sys("PKG_INFO", lkNone, BtShellCommand)
	sys("PKG_JAVA_HOME", lkNone, BtPathname)
	sys("PKG_JVM", lkNone, jvms)
	acl("PKG_JVMS_ACCEPTED", lkShell, jvms, "Makefile: set; Makefile.common: default, set")
	usr("PKG_JVM_DEFAULT", lkNone, jvms)
	acl("PKG_LEGACY_OPTIONS", lkShell, BtOption, "")
	acl("PKG_LIBTOOL", lkNone, BtPathname, "Makefile: set")
	acl("PKG_OPTIONS", lkShell, BtOption, "bsd.options.mk: set; *: use-loadtime, use")
	usr("PKG_OPTIONS.*", lkShell, BtOption)
	acl("PKG_OPTIONS_DEPRECATED_WARNINGS", lkShell, BtShellWord, "")
	acl("PKG_OPTIONS_GROUP.*", lkShell, BtOption, "Makefile, options.mk: set, append")
	acl("PKG_OPTIONS_LEGACY_OPTS", lkShell, BtUnknown, "Makefile, Makefile.common, options.mk: append")
	acl("PKG_OPTIONS_LEGACY_VARS", lkShell, BtUnknown, "Makefile, Makefile.common, options.mk: append")
	acl("PKG_OPTIONS_NONEMPTY_SETS", lkShell, BtIdentifier, "")
	acl("PKG_OPTIONS_OPTIONAL_GROUPS", lkShell, BtIdentifier, "options.mk: set, append")
	acl("PKG_OPTIONS_REQUIRED_GROUPS", lkShell, BtIdentifier, "Makefile, options.mk: set")
	acl("PKG_OPTIONS_SET.*", lkShell, BtOption, "")
	acl("PKG_OPTIONS_VAR", lkNone, BtPkgOptionsVar, "Makefile, Makefile.common, options.mk: set; bsd.options.mk: use-loadtime")
	acl("PKG_PRESERVE", lkNone, BtYes, "Makefile: set")
	acl("PKG_SHELL", lkNone, BtPathname, "Makefile, Makefile.common: set")
	acl("PKG_SHELL.*", lkNone, BtPathname, "Makefile, Makefile.common: set")
	acl("PKG_SHLIBTOOL", lkNone, BtPathname, "")
	pkglist("PKG_SKIP_REASON", lkShell, BtShellWord)
	acl("PKG_SUGGESTED_OPTIONS", lkShell, BtOption, "Makefile, Makefile.common, options.mk: set, append")
	acl("PKG_SUGGESTED_OPTIONS.*", lkShell, BtOption, "Makefile, Makefile.common, options.mk: set, append")
	acl("PKG_SUPPORTED_OPTIONS", lkShell, BtOption, "Makefile: set, append; Makefile.common: set; options.mk: set, append, use")
	acl("PKG_SYSCONFDIR*", lkNone, BtPathname, ""+
		"Makefile: set, use, use-loadtime; "+
		"buildlink3.mk, builtin.mk: use-loadtime; "+
		"Makefile.*, *.mk: default, set, use, use-loadtime")
	pkglist("PKG_SYSCONFDIR_PERMS", lkShell, BtPerms)
	sys("PKG_SYSCONFBASEDIR", lkNone, BtPathname)
	pkg("PKG_SYSCONFSUBDIR", lkNone, BtPathname)
	acl("PKG_SYSCONFVAR", lkNone, BtIdentifier, "")
	acl("PKG_UID", lkNone, BtInteger, "Makefile: set")
	acl("PKG_USERS", lkShell, BtShellWord, "Makefile: set, append")
	pkglist("PKG_USERS_VARS", lkShell, BtVariableName)
	acl("PKG_USE_KERBEROS", lkNone, BtYes, "Makefile, Makefile.common: set")
	pkgload("PLIST.*", lkNone, BtYes)
	pkglist("PLIST_VARS", lkShell, BtIdentifier)
	pkglist("PLIST_SRC", lkShell, BtRelativePkgPath)
	pkglist("PLIST_SUBST", lkShell, BtShellWord)
	acl("PLIST_TYPE", lkNone, enum("dynamic static"), "")
	acl("PREPEND_PATH", lkShell, BtPathname, "")
	acl("PREFIX", lkNone, BtPathname, "*: use")
	acl("PREV_PKGPATH", lkNone, BtPathname, "*: use") // doesn't exist any longer
	acl("PRINT_PLIST_AWK", lkNone, BtAwkCommand, "*: append")
	acl("PRIVILEGED_STAGES", lkShell, enum("install package clean"), "")
	acl("PTHREAD_AUTO_VARS", lkNone, BtYesNo, "Makefile: set")
	sys("PTHREAD_CFLAGS", lkShell, BtCFlag)
	sys("PTHREAD_LDFLAGS", lkShell, BtLdFlag)
	sys("PTHREAD_LIBS", lkShell, BtLdFlag)
	acl("PTHREAD_OPTS", lkShell, enum("native optional require"), "Makefile: set, append; Makefile.common, buildlink3.mk: append")
	sysload("PTHREAD_TYPE", lkNone, BtIdentifier) // Or "native" or "none".
	pkg("PY_PATCHPLIST", lkNone, BtYes)
	acl("PYPKGPREFIX", lkNone, enumFromDirs("lang", `^python(\d+)$`, "py$1", "py27 py36"), ""+
		"pyversion.mk: set; "+
		"*: use-loadtime, use")
	pkg("PYTHON_FOR_BUILD_ONLY", lkNone, enum("yes no test tool YES")) // See lang/python/pyversion.mk
	pkglist("REPLACE_PYTHON", lkShell, BtPathmask)
	pkglist("PYTHON_VERSIONS_ACCEPTED", lkShell, BtVersion)
	pkglist("PYTHON_VERSIONS_INCOMPATIBLE", lkShell, BtVersion)
	usr("PYTHON_VERSION_DEFAULT", lkNone, BtVersion)
	usr("PYTHON_VERSION_REQD", lkNone, BtVersion)
	pkglist("PYTHON_VERSIONED_DEPENDENCIES", lkShell, BtPythonDependency)
	sys("RANLIB", lkNone, BtShellCommand)
	pkglist("RCD_SCRIPTS", lkShell, BtFileName)
	acl("RCD_SCRIPT_SRC.*", lkNone, BtPathname, "Makefile: set")
	acl("RCD_SCRIPT_WRK.*", lkNone, BtPathname, "Makefile: set")
	usr("REAL_ROOT_USER", lkNone, BtUserGroupName)
	usr("REAL_ROOT_GROUP", lkNone, BtUserGroupName)
	acl("REPLACE.*", lkNone, BtUnknown, "Makefile: set")
	pkglist("REPLACE_AWK", lkShell, BtPathmask)
	pkglist("REPLACE_BASH", lkShell, BtPathmask)
	pkglist("REPLACE_CSH", lkShell, BtPathmask)
	acl("REPLACE_EMACS", lkShell, BtPathmask, "")
	acl("REPLACE_FILES.*", lkShell, BtPathmask, "Makefile, Makefile.common: set, append")
	acl("REPLACE_INTERPRETER", lkShell, BtIdentifier, "Makefile, Makefile.common: append")
	pkglist("REPLACE_KSH", lkShell, BtPathmask)
	pkglist("REPLACE_LOCALEDIR_PATTERNS", lkShell, BtFileMask)
	pkglist("REPLACE_LUA", lkShell, BtPathmask)
	pkglist("REPLACE_PERL", lkShell, BtPathmask)
	pkglist("REPLACE_PYTHON", lkShell, BtPathmask)
	pkglist("REPLACE_SH", lkShell, BtPathmask)
	pkglist("REQD_DIRS", lkShell, BtPathname)
	pkglist("REQD_DIRS_PERMS", lkShell, BtPerms)
	pkglist("REQD_FILES", lkShell, BtPathname)
	pkg("REQD_FILES_MODE", lkNone, enum("0644 0640 0600 0400"))
	pkglist("REQD_FILES_PERMS", lkShell, BtPerms)
	pkg("RESTRICTED", lkNone, BtMessage)
	usr("ROOT_USER", lkNone, BtUserGroupName)
	usr("ROOT_GROUP", lkNone, BtUserGroupName)
	usr("RUBY_VERSION_REQD", lkNone, BtVersion)
	sys("RUN", lkNone, BtShellCommand)
	sys("RUN_LDCONFIG", lkNone, BtYesNo)
	acl("SCRIPTS_ENV", lkShell, BtShellWord, "Makefile, Makefile.common: append")
	usr("SETGID_GAMES_PERMS", lkShell, BtPerms)
	usr("SETUID_ROOT_PERMS", lkShell, BtPerms)
	pkg("SET_LIBDIR", lkNone, BtYes)
	sys("SHAREGRP", lkNone, BtUserGroupName)
	sys("SHAREMODE", lkNone, BtFileMode)
	sys("SHAREOWN", lkNone, BtUserGroupName)
	sys("SHCOMMENT", lkNone, BtShellCommand)
	acl("SHLIB_HANDLING", lkNone, enum("YES NO no"), "")
	acl("SHLIBTOOL", lkNone, BtShellCommand, "Makefile: use")
	acl("SHLIBTOOL_OVERRIDE", lkShell, BtPathmask, "Makefile: set, append; Makefile.common: append")
	sysload("SHLIB_TYPE", lkNone, enum("COFF ECOFF ELF SOM XCOFF Mach-O PE PEwin a.out aixlib dylib none"))
	acl("SITES.*", lkShell, BtFetchURL, "Makefile, Makefile.common, options.mk: set, append, use")
	usr("SMF_PREFIS", lkNone, BtPathname)
	pkg("SMF_SRCDIR", lkNone, BtPathname)
	pkg("SMF_NAME", lkNone, BtFileName)
	pkg("SMF_MANIFEST", lkNone, BtPathname)
	pkg("SMF_INSTANCES", lkShell, BtIdentifier)
	pkg("SMF_METHODS", lkShell, BtFileName)
	pkg("SMF_METHOD_SRC.*", lkNone, BtPathname)
	pkg("SMF_METHOD_SHELL", lkNone, BtShellCommand)
	pkglist("SPECIAL_PERMS", lkShell, BtPerms)
	sys("STEP_MSG", lkNone, BtShellCommand)
	sys("STRIP", lkNone, BtShellCommand) // see mk/tools/strip.mk
	acl("SUBDIR", lkShell, BtFileName, "Makefile: append; *:")
	acl("SUBST_CLASSES", lkShell, BtIdentifier, "Makefile: set, append; *: append")
	acl("SUBST_CLASSES.*", lkShell, BtIdentifier, "Makefile: set, append; *: append")
	acl("SUBST_FILES.*", lkShell, BtPathmask, "Makefile, Makefile.*, *.mk: set, append")
	acl("SUBST_FILTER_CMD.*", lkNone, BtShellCommand, "Makefile, Makefile.*, *.mk: set")
	acl("SUBST_MESSAGE.*", lkNone, BtMessage, "Makefile, Makefile.*, *.mk: set")
	acl("SUBST_SED.*", lkNone, BtSedCommands, "Makefile, Makefile.*, *.mk: set, append")
	pkg("SUBST_STAGE.*", lkNone, BtStage)
	pkglist("SUBST_VARS.*", lkShell, BtVariableName)
	pkglist("SUPERSEDES", lkSpace, BtDependency)
	acl("TEST_DEPENDS", lkSpace, BtDependencyWithPath, "Makefile, Makefile.common, *.mk: append")
	pkglist("TEST_DIRS", lkShell, BtWrksrcSubdirectory)
	pkglist("TEST_ENV", lkShell, BtShellWord)
	acl("TEST_TARGET", lkShell, BtIdentifier, "Makefile: set; Makefile.common: default, set; options.mk: set, append")
	pkglist("TEXINFO_REQD", lkShell, BtVersion)
	acl("TOOL_DEPENDS", lkSpace, BtDependencyWithPath, "Makefile, Makefile.common, *.mk: append")
	sys("TOOLS_ALIASES", lkShell, BtFileName)
	sys("TOOLS_BROKEN", lkShell, BtTool)
	sys("TOOLS_CMD.*", lkNone, BtPathname)
	acl("TOOLS_CREATE", lkShell, BtTool, "Makefile, Makefile.common, options.mk: append")
	acl("TOOLS_DEPENDS.*", lkSpace, BtDependencyWithPath, "buildlink3.mk:; Makefile, Makefile.*: set, default; *: use")
	sys("TOOLS_GNU_MISSING", lkShell, BtTool)
	sys("TOOLS_NOOP", lkShell, BtTool)
	sys("TOOLS_PATH.*", lkNone, BtPathname)
	sysload("TOOLS_PLATFORM.*", lkNone, BtShellCommand)
	sys("TOUCH_FLAGS", lkShell, BtShellWord)
	pkglist("UAC_REQD_EXECS", lkShell, BtPrefixPathname)
	acl("UNLIMIT_RESOURCES", lkShell, enum("cputime datasize memorysize stacksize"), "Makefile: set, append; Makefile.common: append")
	usr("UNPRIVILEGED_USER", lkNone, BtUserGroupName)
	usr("UNPRIVILEGED_GROUP", lkNone, BtUserGroupName)
	pkglist("UNWRAP_FILES", lkShell, BtPathmask)
	usr("UPDATE_TARGET", lkShell, BtIdentifier)
	pkg("USERGROUP_PHASE", lkNone, enum("configure build pre-install"))
	usr("USER_ADDITIONAL_PKGS", lkShell, BtPkgPath)
	pkg("USE_BSD_MAKEFILE", lkNone, BtYes)
	acl("USE_BUILTIN.*", lkNone, BtYesNoIndirectly, "buildlink3.mk: use-loadtime; builtin.mk: set, use, use-loadtime; options.mk: use-loadtime")
	pkg("USE_CMAKE", lkNone, BtYes)
	usr("USE_DESTDIR", lkNone, BtYes)
	pkglist("USE_FEATURES", lkShell, BtIdentifier)
	acl("USE_GAMESGROUP", lkNone, BtYesNo, "buildlink3.mk, builtin.mk:; *: set, default, use")
	pkg("USE_GCC_RUNTIME", lkNone, BtYesNo)
	pkg("USE_GNU_CONFIGURE_HOST", lkNone, BtYesNo)
	acl("USE_GNU_ICONV", lkNone, BtYes, "Makefile, Makefile.common, options.mk: set")
	acl("USE_IMAKE", lkNone, BtYes, "Makefile: set")
	pkg("USE_JAVA", lkNone, enum("run yes build"))
	pkg("USE_JAVA2", lkNone, enum("YES yes no 1.4 1.5 6 7 8"))
	acl("USE_LANGUAGES", lkShell, languages, "Makefile, Makefile.common, options.mk: set, append")
	pkg("USE_LIBTOOL", lkNone, BtYes)
	pkg("USE_MAKEINFO", lkNone, BtYes)
	pkg("USE_MSGFMT_PLURALS", lkNone, BtYes)
	pkg("USE_NCURSES", lkNone, BtYes)
	pkg("USE_OLD_DES_API", lkNone, BtYesNo)
	pkg("USE_PKGINSTALL", lkNone, BtYes)
	pkg("USE_PKGLOCALEDIR", lkNone, BtYesNo)
	usr("USE_PKGSRC_GCC", lkNone, BtYes)
	acl("USE_TOOLS", lkShell, BtTool, "*: append, use-loadtime")
	acl("USE_TOOLS.*", lkShell, BtTool, "*: append, use-loadtime")
	pkg("USE_X11", lkNone, BtYes)
	sys("WARNINGS", lkShell, BtShellWord)
	sys("WARNING_MSG", lkNone, BtShellCommand)
	sys("WARNING_CAT", lkNone, BtShellCommand)
	sysload("WRAPPER_DIR", lkNone, BtPathname)
	acl("WRAPPER_REORDER_CMDS", lkShell, BtWrapperReorder, "Makefile, Makefile.common, buildlink3.mk: append")
	pkg("WRAPPER_SHELL", lkNone, BtShellCommand)
	acl("WRAPPER_TRANSFORM_CMDS", lkShell, BtWrapperTransform, "Makefile, Makefile.common, buildlink3.mk: append")
	sys("WRKDIR", lkNone, BtPathname)
	pkg("WRKSRC", lkNone, BtWrkdirSubdirectory)
	pkglist("X11_LDFLAGS", lkShell, BtLdFlag)
	sys("X11_PKGSRCDIR.*", lkNone, BtPathname)
	usr("XAW_TYPE", lkNone, enum("3d neXtaw standard xpm"))
	acl("XMKMF_FLAGS", lkShell, BtShellWord, "")
	pkglist("_WRAP_EXTRA_ARGS.*", lkShell, BtShellWord)

	// Only for infrastructure files; see mk/misc/show.mk
	acl("_VARGROUPS", lkSpace, BtIdentifier, "*: append")
	acl("_USER_VARS.*", lkSpace, BtIdentifier, "*: append")
	acl("_PKG_VARS.*", lkSpace, BtIdentifier, "*: append")
	acl("_SYS_VARS.*", lkSpace, BtIdentifier, "*: append")
	acl("_DEF_VARS.*", lkSpace, BtIdentifier, "*: append")
	acl("_USE_VARS.*", lkSpace, BtIdentifier, "*: append")
}

func enum(values string) *BasicType {
	valueMap := make(map[string]bool)
	for _, value := range fields(values) {
		valueMap[value] = true
	}
	name := "enum: " + values + " " // See IsEnum
	basicType := &BasicType{name, nil}
	basicType.checker = func(check *VartypeCheck) {
		check.Enum(valueMap, basicType)
	}
	return basicType
}

func parseACLEntries(varname string, aclEntries string) []ACLEntry {
	if aclEntries == "" {
		return nil
	}
	var result []ACLEntry
	prevperms := "(first)"
	for _, arg := range strings.Split(aclEntries, "; ") {
		var globs, perms string
		if fields := strings.SplitN(arg, ": ", 2); len(fields) == 2 {
			globs, perms = fields[0], fields[1]
		} else {
			globs = strings.TrimSuffix(arg, ":")
		}
		G.Assertf(perms != prevperms, "Repeated permissions %q for %q.", perms, varname)
		prevperms = perms

		var permissions ACLPermissions
		for _, perm := range strings.Split(perms, ", ") {
			switch perm {
			case "append":
				permissions |= aclpAppend
			case "default":
				permissions |= aclpSetDefault
			case "set":
				permissions |= aclpSet
			case "use":
				permissions |= aclpUse
			case "use-loadtime":
				permissions |= aclpUseLoadtime
			case "":
				break
			default:
				G.Assertf(false, "Invalid ACL permission %q for %q.", perm, varname)
			}
		}

		for _, glob := range strings.Split(globs, ", ") {
			switch glob {
			case "*",
				"Makefile", "Makefile.common", "Makefile.*",
				"buildlink3.mk", "builtin.mk", "options.mk", "hacks.mk", "*.mk",
				"bsd.options.mk", "pkgconfig-builtin.mk", "pyversion.mk":
				break
			default:
				G.Assertf(false, "Invalid ACL glob %q for %q.", glob, varname)
			}
			for _, prev := range result {
				matched, err := path.Match(prev.glob, glob)
				G.Assertf(err == nil && !matched, "Ineffective ACL glob %q for %q.", glob, varname)
			}
			result = append(result, ACLEntry{glob, permissions})
		}
	}
	return result
}
