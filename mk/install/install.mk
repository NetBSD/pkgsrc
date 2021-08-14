# $NetBSD: install.mk,v 1.80 2021/08/14 08:38:01 rillig Exp $
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

# User-settable variables:
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
# Package-settable variables:
#
# INSTALLATION_DIRS
#	A list of directories that should be created at the very
#	beginning of the install phase. These directories MUST either
#	be paths that contain a leading {PREFIX}/ or be relative
#	paths. As a convenience, a leading gnu/ is transformed to
#	${PKGGNUDIR} and a leading man/ is transformed to ${PKGMANDIR},
#	to save package authors from typing too much.
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
#
# STRIP_DEBUG_SUPPORTED
#	If set to anything other than "yes" (the default), stripping will
#	be disabled for the package.
#
# STRIP_FILES_SKIP
#	A list of files relative to ${PREFIX} that will not be stripped.

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
.  if exists(${_COOKIE.install}) && !${_CLEANING}
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

.if exists(${_COOKIE.install}) && !${_CLEANING}
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
### install-all, su-install-all (PRIVATE)
######################################################################
### install-all is a helper target to run the install target of
### the built software, register the software installation, and run
### some sanity checks.
###
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
_INSTALL_ALL_TARGETS+=		pre-install
_INSTALL_ALL_TARGETS+=		do-install
_INSTALL_ALL_TARGETS+=		post-install
_INSTALL_ALL_TARGETS+=		plist
.if ${_PKGSRC_USE_CTF} == "yes"
_INSTALL_ALL_TARGETS+=		install-ctf
.endif
.if ${STRIP_DEBUG:Uno:tl} == "yes" && ${STRIP_DEBUG_SUPPORTED:Uyes:tl} == "yes"
_INSTALL_ALL_TARGETS+=		install-strip-debug
.endif
_INSTALL_ALL_TARGETS+=		install-doc-handling
.if ${_USE_NEW_PKGINSTALL:Uno} == "no"
_INSTALL_ALL_TARGETS+=		install-script-data
.endif
.if empty(CHECK_FILES:M[nN][oO]) && !empty(CHECK_FILES_SUPPORTED:M[Yy][Ee][Ss])
_INSTALL_ALL_TARGETS+=		check-files-post
.endif
_INSTALL_ALL_TARGETS+=		_pkgformat-generate-metadata
_INSTALL_ALL_TARGETS+=		privileged-install-hook
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

# _INSTALLATION_DIRS
#	Contains the items listed in ${INSTALLATION_DIRS} with the
#	following transformations performed, in order:
#
#	1. Leading "${PREFIX}/" is stripped.
#	2. Leading "gnu/" is transformed into "${PKGGNUDIR}".
#	3. Leading "man/" is transformed into "${PKGMANDIR}/".
#
# Check that paths listed in ${_INSTALLATION_DIRS} are relative paths.
# This can't be an assertion because some variables used when listing
# directories in INSTALLATION_DIRS are not expanded until they are
# used.
#
_INSTALLATION_DIRS=	${INSTALLATION_DIRS:C,^${PREFIX}/,,:C,^gnu/,${PKGGNUDIR},:C,^man/,${PKGMANDIR}/,}

.PHONY: install-makedirs
install-makedirs:
	${RUN} ${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}
.if defined(INSTALLATION_DIRS) && !empty(INSTALLATION_DIRS)
	@${STEP_MSG} "Creating installation directories"
	${RUN} set -- args ${_INSTALLATION_DIRS}; shift;		\
	while ${TEST} "$$#" -gt 0; do					\
		dir="$$1"; shift;					\
		case "$$dir" in						\
		/*)	${FAIL_MSG} "INSTALLATION_DIRS: $$dir must be in "${PREFIX:Q}"." ;; \
		*)	${_INSTALL_ONE_DIR_CMD}	;;			\
		esac;							\
	done
.endif	# INSTALLATION_DIRS

# Creates the directories for all files that are listed unconditionally
# in the static PLIST files of the package, to make the declaration of
# INSTALLATION_DIRS redundant in some cases.
#
# To enable this, set AUTO_MKDIRS to "yes".
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
	| ${TOOLS_PLATFORM.uniq:Uuniq}					\
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
.if !empty(DESTDIR_VARNAME)
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
### install-ctf (PRIVATE)
######################################################################
### install-ctf creates CTF information from debug binaries.
###
.PHONY: install-ctf
install-ctf: plist
	@${STEP_MSG} "Generating CTF data"
	${RUN}cd ${DESTDIR:Q}${PREFIX:Q};				\
	${CAT} ${_PLIST_NOKEYWORDS} | while read f; do			\
		case "$${f}" in						\
		${CTF_FILES_SKIP:@p@${p}) continue ;;@}			\
		*) ;;							\
		esac;							\
		[ ! -h "$${f}" ] || continue;				\
		tmp_f="$${f}.XXX";					\
		if ${CTFCONVERT} -o "$${tmp_f}" "$${f}" 2>/dev/null; then \
			if [ -f "$${tmp_f}" -a -f "$${f}" ]; then	\
				${MV} "$${tmp_f}" "$${f}";		\
			fi;						\
		fi;							\
		${RM} -f "$${tmp_f}";					\
	done

######################################################################
### install-strip-debug (PRIVATE)
######################################################################
### install-strip-debug tries to strip debug information from
### the files in PLIST.
###
.PHONY: install-strip-debug
install-strip-debug: plist
	@${STEP_MSG} "Automatic stripping of debug information"
	${RUN}cd ${DESTDIR:Q}${PREFIX:Q};				\
	${CAT} ${_PLIST_NOKEYWORDS} | while read f; do			\
		case "$${f}" in						\
		${STRIP_FILES_SKIP:@p@${p}) continue;;@}		\
		*) ;;							\
		esac;							\
		[ ! -h "$${f}" ] || continue;				\
		tmp_f="$${f}.XXX";					\
		if ${STRIP_DBG} -o "$${tmp_f}" "$${f}" 2>/dev/null; then \
			if [ -f "$${tmp_f}" -a -f "$${f}" ]; then	\
				${MV} "$${tmp_f}" "$${f}";		\
			fi;						\
		fi;							\
		${RM} -f "$${tmp_f}";					\
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
	^([^/]*/)+((man|html)[1-9ln](am|f)?/[^/]*\.([1-9ln](am|f)?|html)|cat[1-9ln](am|f)?/[^/]*\.[0-9])(\.gz)?$$

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
