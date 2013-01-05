# $NetBSD: install.mk,v 1.66 2013/01/05 07:32:49 sbd Exp $
#
# This file provides the code for the "install" phase.
#
# Public targets:
#
# stage-install:
#	Installs the package files into LOCALBASE or ${DESTDIR}${LOCALBASE}.
#

# Interface for other infrastructure components:
#
# Hooks for use by the infrastructure:
#
# privileged-install-hook:
#	This hook is placed after the package has been installed,
#	before leaving the privileged mode.
#
# unprivileged-install-hook:
#	This hook is placed _before_ switching to privileged mode
#	in order to install the package.
#

# === User-settable variables ===
#
# INSTALL_UNSTRIPPED
#	If "yes", all binaries and shared libraries are installed
#	unstripped. Otherwise they are stripped while being installed.
#	This option is not supported by all packages.
#
# STRIP_DEBUG
#	If set to "yes", call ${STRIP} -g to remove debug information
#	from all files. The symbol tables are still preserved.
#
# Keywords: strip unstripped
#
# === Package-settable variables ===
#
# INSTALLATION_DIRS
#	A list of directories that should be created at the very
#	beginning of the install phase. These directories are relative
#	to ${PREFIX}. As a convenience, a leading gnu/ is transformed
#	to ${PKGGNUDIR} and a leading man/ is transformed to
#	${PKGMANDIR}, to save package authors from typing too much.
#
# AUTO_MKDIRS
# INSTALLATION_DIRS_FROM_PLIST
#	In most (or even all?) cases the PLIST files in the package
#	directory already contain all directories that are needed.
#	When this variable is set to "yes", all directories mentioned
#	in the PLIST files will be created like in INSTALLATION_DIRS.
#
# DESTDIR_VARNAME
#	A variable name that should be set as staged installation location
#	presented as ${DESTDIR} at install phase.
#	"DESTDIR" is set by default.

######################################################################
### install (PUBLIC)
######################################################################
### install is a public target to install the package.  It will
### acquire elevated privileges just-in-time.
###
_INSTALL_TARGETS+=	check-vulnerable
_INSTALL_TARGETS+=	${_PKGSRC_BUILD_TARGETS}
_INSTALL_TARGETS+=	acquire-install-lock
_INSTALL_TARGETS+=	${_COOKIE.install}
_INSTALL_TARGETS+=	release-install-lock

.PHONY: stage-install
.if !target(stage-install)
.  if exists(${_COOKIE.install})
stage-install:
	@${DO_NADA}
.  elif defined(_PKGSRC_BARRIER)
stage-install: ${_INSTALL_TARGETS}
.  else
stage-install: barrier
.  endif
.endif

.PHONY: acquire-install-lock release-install-lock
acquire-install-lock: acquire-lock
release-install-lock: release-lock

.if exists(${_COOKIE.install})
${_COOKIE.install}:
	@${DO_NADA}
.else
${_COOKIE.install}: real-install
.endif

######################################################################
### real-install (PRIVATE)
######################################################################
### real-install is a helper target onto which one can hook all of the
### targets that do the actual installing of the built objects.
###
_REAL_INSTALL_TARGETS+=	install-check-interactive
_REAL_INSTALL_TARGETS+=	install-check-version
_REAL_INSTALL_TARGETS+=	install-message
_REAL_INSTALL_TARGETS+=	stage-install-vars
_REAL_INSTALL_TARGETS+=	unprivileged-install-hook
_REAL_INSTALL_TARGETS+=	install-all
_REAL_INSTALL_TARGETS+=	install-cookie

.PHONY: real-install
real-install: ${_REAL_INSTALL_TARGETS}

.PHONY: install-message
install-message:
	@${PHASE_MSG} "Installing for ${PKGNAME}"

######################################################################
### install-check-interactive (PRIVATE)
######################################################################
### install-check-interactive checks whether we must do an interactive
### install or not.
###
install-check-interactive: .PHONY
.if !empty(INTERACTIVE_STAGE:Minstall) && defined(BATCH)
	@${ERROR_MSG} "The installation stage of this package requires user interaction"
	@${ERROR_MSG} "Please install manually with:"
	@${ERROR_MSG} "	\"cd ${.CURDIR} && ${MAKE} install\""
	${RUN} ${FALSE}
.else
	@${DO_NADA}
.endif

.PHONY: unprivileged-install-hook
unprivileged-install-hook:
	@${DO_NADA}

######################################################################
### install-check-version (PRIVATE)
######################################################################
### install-check-version will verify that the built package located in
### ${WRKDIR} matches the version specified in the package Makefile.
### This is a check against stale work directories.
###
.PHONY: install-check-version
install-check-version: ${_COOKIE.extract}
	${RUN}								\
	extractname=`${CAT} ${_COOKIE.extract}`;			\
	pkgname=${PKGNAME};						\
	case "$$extractname" in						\
	"")	${WARNING_MSG} "${WRKDIR} may contain an older version of ${PKGBASE}" ;; \
	"$$pkgname")	;;						\
	*)	${WARNING_MSG} "Package version $$extractname in ${WRKDIR}"; \
		${WARNING_MSG} "Current version $$pkgname in ${PKGPATH}"; \
		${WARNING_MSG} "Cleaning and rebuilding $$pkgname...";	\
		${RECURSIVE_MAKE} ${MAKEFLAGS} clean;			\
		${RECURSIVE_MAKE} ${MAKEFLAGS} build ;;			\
	esac

######################################################################
### The targets below are run with elevated privileges.
######################################################################

.PHONY: acquire-install-localbase-lock release-install-localbase-lock
acquire-install-localbase-lock: acquire-localbase-lock
release-install-localbase-lock: release-localbase-lock

######################################################################
### install-all, su-install-all (PRIVATE)
######################################################################
### install-all is a helper target to run the install target of
### the built software, register the software installation, and run
### some sanity checks.
###
.if ${_USE_DESTDIR} != "user-destdir"
_INSTALL_ALL_TARGETS+=		acquire-install-localbase-lock
.endif
.if ${_USE_DESTDIR} == "no"
_INSTALL_ALL_TARGETS+=		_pkgformat-check-conflicts
_INSTALL_ALL_TARGETS+=		_pkgformat-check-installed
.endif
_INSTALL_ALL_TARGETS+=		install-check-umask
.if empty(CHECK_FILES:M[nN][oO]) && !empty(CHECK_FILES_SUPPORTED:M[Yy][Ee][Ss])
_INSTALL_ALL_TARGETS+=		check-files-pre
.endif
_INSTALL_ALL_TARGETS+=		install-makedirs
.if defined(INSTALLATION_DIRS_FROM_PLIST) && \
	!empty(INSTALLATION_DIRS_FROM_PLIST:M[Yy][Ee][Ss])
_INSTALL_ALL_TARGETS+=		install-dirs-from-PLIST
.elif defined(AUTO_MKDIRS) && !empty(AUTO_MKDIRS:M[Yy][Ee][Ss])
_INSTALL_ALL_TARGETS+=		install-dirs-from-PLIST
.endif
.if ${_USE_DESTDIR} == "no"
_INSTALL_ALL_TARGETS+=		pre-install-script
.endif
_INSTALL_ALL_TARGETS+=		pre-install
_INSTALL_ALL_TARGETS+=		do-install
_INSTALL_ALL_TARGETS+=		post-install
_INSTALL_ALL_TARGETS+=		plist
.if !empty(STRIP_DEBUG:M[Yy][Ee][Ss])
_INSTALL_ALL_TARGETS+=		install-strip-debug
.endif
_INSTALL_ALL_TARGETS+=		install-doc-handling
_INSTALL_ALL_TARGETS+=		install-script-data
.if empty(CHECK_FILES:M[nN][oO]) && !empty(CHECK_FILES_SUPPORTED:M[Yy][Ee][Ss])
_INSTALL_ALL_TARGETS+=		check-files-post
.endif
.if ${_USE_DESTDIR} == "no"
_INSTALL_ALL_TARGETS+=		post-install-script
.endif
.if ${_USE_DESTDIR} == "no"
_INSTALL_ALL_TARGETS+=		_pkgformat-register
.else
_INSTALL_ALL_TARGETS+=		_pkgformat-generate-metadata
.endif
_INSTALL_ALL_TARGETS+=		privileged-install-hook
.if ${_USE_DESTDIR} != "user-destdir"
_INSTALL_ALL_TARGETS+=		release-install-localbase-lock
.endif
_INSTALL_ALL_TARGETS+=		error-check

.PHONY: install-all su-install-all
.  if !empty(_MAKE_INSTALL_AS_ROOT:M[Yy][Ee][Ss])
install-all: su-target
.  else
install-all: su-install-all
.  endif
su-install-all: ${_INSTALL_ALL_TARGETS}

######################################################################
### install-check-umask (PRIVATE)
######################################################################
### install-check-umask tests whether the umask is properly set and
### emits a non-fatal warning otherwise.
###
.PHONY: install-check-umask
install-check-umask:
	${RUN}								\
	umask=`${SH} -c umask`;						\
	if [ "$$umask" -ne ${DEF_UMASK} ]; then			\
		${WARNING_MSG} "Your umask is \`\`$$umask''.";	\
		${WARNING_MSG} "If this is not desired, set it to an appropriate value (${DEF_UMASK}) and install"; \
		${WARNING_MSG} "this package again by \`\`${MAKE} deinstall reinstall''."; \
        fi

######################################################################
### install-makedirs (PRIVATE)
######################################################################
### install-makedirs is a target to create directories expected to
### exist prior to installation.  The package is supposed to create
### all directories not listed in INSTALLATION_DIRS.
###

# A shell command that creates the directory ${DESTDIR}${PREFIX}/$$dir
# with appropriate permissions and ownership.
#
_INSTALL_ONE_DIR_CMD= { \
	ddir="${DESTDIR}${PREFIX}/$$dir";				\
	[ ! -f "$$ddir" ] || ${FAIL_MSG} "[install.mk] $$ddir should be a directory, but is a file."; \
	case "$$dir" in							\
	*bin|*bin/*|*libexec|*libexec/*)				\
		${INSTALL_PROGRAM_DIR} "$$ddir" ;;			\
	${PKGMANDIR}/*)							\
		${INSTALL_MAN_DIR} "$$ddir" ;;				\
	*)								\
		${INSTALL_DATA_DIR} "$$ddir" ;;				\
	esac;								\
	}

.PHONY: install-makedirs
install-makedirs:
	${RUN} ${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}
.if defined(INSTALLATION_DIRS) && !empty(INSTALLATION_DIRS)
	@${STEP_MSG} "Creating installation directories"
	${RUN}								\
	for dir in ${INSTALLATION_DIRS:C,^gnu/,${PKGGNUDIR},:C,^man/,${PKGMANDIR}/,}; do \
		case "$$dir" in						\
		${PREFIX}/*)						\
			dir=`${ECHO} "$$dir" | ${SED} "s|^${PREFIX}/||"` ;; \
		/*)	continue ;;					\
		esac;							\
		${_INSTALL_ONE_DIR_CMD};				\
	done
.endif	# INSTALLATION_DIRS

# Creates the directories for all files that are mentioned in the static
# PLIST files of the package, to make the declaration of
# INSTALLATION_DIRS redundant in some cases.
#
# To enable this, the variable INSTALLATION_DIRS_FROM_PLIST must be set
# to "yes".
#
.PHONY: install-dirs-from-PLIST
install-dirs-from-PLIST:
	@${STEP_MSG} "Creating installation directories from PLIST files"
	${RUN}								\
	${CAT} ${PLIST_SRC}						\
	| sed -n							\
		-e 's,\\,\\\\,'						\
		-e 's,^gnu/man/,${PKGGNUDIR}${PKGMANDIR}/,'		\
		-e 's,^gnu/,${PKGGNUDIR},'				\
		-e 's,^man/,${PKGMANDIR}/,'				\
		-e 's,^info/,${PKGINFODIR}/,'				\
		-e 's,^share/locale/,${PKGLOCALEDIR}/locale/,'		\
		-e 's,^\([^$$@]*\)/[^/]*$$,\1,p'			\
	| while read dir; do						\
		${_INSTALL_ONE_DIR_CMD};				\
	done

######################################################################
### pre-install, do-install, post-install (PUBLIC, override)
######################################################################
### {pre,do,post}-install are the heart of the package-customizable
### install targets, and may be overridden within a package Makefile.
###
.PHONY: pre-install do-install post-install

INSTALL_DIRS?=		${BUILD_DIRS}
INSTALL_MAKE_FLAGS?=	# none
INSTALL_TARGET?=	install ${USE_IMAKE:D${NO_INSTALL_MANPAGES:D:Uinstall.man}}
DESTDIR_VARNAME?=	DESTDIR
.if ${_USE_DESTDIR} != "no" && !empty(DESTDIR_VARNAME)
INSTALL_ENV+=		${DESTDIR_VARNAME}=${DESTDIR:Q}
INSTALL_MAKE_FLAGS+=	${DESTDIR_VARNAME}=${DESTDIR:Q}
.endif

.if !target(do-install)
do-install:
.  for _dir_ in ${INSTALL_DIRS}
	${RUN} ${_ULIMIT_CMD}						\
	cd ${WRKSRC} && cd ${_dir_} &&					\
	${PKGSRC_SETENV} ${INSTALL_ENV} ${MAKE_ENV} 			\
		${MAKE_PROGRAM} ${MAKE_FLAGS} ${INSTALL_MAKE_FLAGS}	\
			-f ${MAKE_FILE} ${INSTALL_TARGET}
.  endfor
.endif

.if !target(pre-install)
pre-install:
	@${DO_NADA}
.endif
.if !target(post-install)
post-install:
	@${DO_NADA}
.endif

######################################################################
### install-strip-debug (PRIVATE)
######################################################################
### install-strip-debug tries to strip debug information from
### the files in PLIST.
###
.PHONY: install-strip-debug
install-strip-debug: plist
	@${STEP_MSG} "Automatic stripping of debug information"
	${RUN}${CAT} ${_PLIST_NOKEYWORDS} \
	| ${SED} -e 's|^|${DESTDIR}${PREFIX}/|' \
	| while read f; do \
		tmp_f="$${f}.XXX"; \
		if ${STRIP} -g -o "$${tmp_f}" "$${f}" 2> /dev/null; then \
			[ ! -f "$${f}" ] || \
			    ${MV} "$${tmp_f}" "$${f}"; \
		else \
			${RM} -f "$${tmp_f}"; \
		fi \
	done

######################################################################
### install-doc-handling (PRIVATE)
######################################################################
### install-doc-handling does automatic document (de)compression based
### on the contents of the PLIST.
###
_PLIST_REGEXP.info=	\
	^([^\/]*\/)*${PKGINFODIR}/[^/]*(\.info)?(-[0-9]+)?(\.gz)?$$
_PLIST_REGEXP.man=	\
	^([^/]*/)+(man[1-9ln]/[^/]*\.[1-9ln]|cat[1-9ln]/[^/]*\.[0-9])(\.gz)?$$

_DOC_COMPRESS=								\
	${PKGSRC_SETENV} PATH=${PATH:Q}					\
		MANZ=${_MANZ}						\
		PKG_VERBOSE=${PKG_VERBOSE}				\
		TEST=${TOOLS_TEST:Q}					\
	${SH} ${PKGSRCDIR}/mk/plist/doc-compress ${DESTDIR}${PREFIX}

.PHONY: install-doc-handling
install-doc-handling: plist
	@${STEP_MSG} "Automatic manual page handling"
	${RUN} \
	${CAT} ${_PLIST_NOKEYWORDS} \
	| ${EGREP} ${_PLIST_REGEXP.man:Q} \
	| ${_DOC_COMPRESS}

privileged-install-hook: .PHONY
	@${DO_NADA}

######################################################################
### install-clean (PRIVATE)
######################################################################
### install-clean removes the state files for the "install" and
### later phases so that the "install" target may be re-invoked.
###
install-clean: .PHONY package-eat-cookie check-clean _pkgformat-install-clean
	${RUN} ${RM} -f ${PLIST} ${_COOKIE.install} ${_DEPENDS_PLIST}
