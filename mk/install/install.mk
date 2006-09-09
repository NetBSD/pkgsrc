# $NetBSD: install.mk,v 1.18 2006/09/09 02:35:13 obache Exp $

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

.PHONY: install
.if !target(install)
.  if exists(${_COOKIE.install})
install:
	@${DO_NADA}
.  elif defined(_PKGSRC_BARRIER)
install: ${_INSTALL_TARGETS}
.  else
install: barrier
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
_REAL_INSTALL_TARGETS+=	install-vars
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
install-check-interactive:
.if !empty(INTERACTIVE_STAGE:Minstall) && defined(BATCH)
	@${ERROR_MSG} "The installation stage of this package requires user interaction"
	@${ERROR_MSG} "Please install manually with:"
	@${ERROR_MSG} "	\"cd ${.CURDIR} && ${MAKE} install\""
	@${TOUCH} ${_INTERACTIVE_COOKIE}
	@${FALSE}
.else
	@${DO_NADA}
.endif

######################################################################
### unprivileged-install-hook (PRIVATE, override, hook)
######################################################################
### unprivileged-install-hook is a generic hook target that is run just
### before pkgsrc elevates privileges for install-all.
###
.PHONY: unprivileged-install-hook
.if !target(unprivileged-install-hook)
unprivileged-install-hook:
	@${DO_NADA}
.endif

######################################################################
### install-check-version (PRIVATE)
######################################################################
### install-check-version will verify that the built package located in
### ${WRKDIR} matches the version specified in the package Makefile.
### This is a check against stale work directories.
###
.PHONY: install-check-version
install-check-version: ${_COOKIE.extract}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	extractname=`${CAT} ${_COOKIE.extract}`;			\
	pkgname=${PKGNAME};						\
	case "$$extractname" in						\
	"")	${WARNING_MSG} "${WRKDIR} may contain an older version of ${PKGBASE}" ;; \
	"$$pkgname")	;;						\
	*)	${WARNING_MSG} "Package version $$extractname in ${WRKDIR}"; \
		${WARNING_MSG} "Current version $$pkgname in ${PKGPATH}"; \
		${WARNING_MSG} "Cleaning and rebuilding $$pkgname...";	\
		${RECURSIVE_MAKE} clean build ;;			\
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
_INSTALL_ALL_TARGETS+=		acquire-install-localbase-lock
.if !defined(NO_PKG_REGISTER) && !defined(FORCE_PKG_REGISTER)
_INSTALL_ALL_TARGETS+=		install-check-conflicts
_INSTALL_ALL_TARGETS+=		install-check-installed
.endif
_INSTALL_ALL_TARGETS+=		install-check-umask
.if empty(CHECK_FILES:M[nN][oO])
_INSTALL_ALL_TARGETS+=		check-files-pre
.endif
_INSTALL_ALL_TARGETS+=		install-makedirs
_INSTALL_ALL_TARGETS+=		pre-install-script
_INSTALL_ALL_TARGETS+=		pre-install
_INSTALL_ALL_TARGETS+=		do-install
_INSTALL_ALL_TARGETS+=		post-install
_INSTALL_ALL_TARGETS+=		plist
_INSTALL_ALL_TARGETS+=		install-doc-handling
_INSTALL_ALL_TARGETS+=		install-script-data
.if empty(CHECK_FILES:M[nN][oO])
_INSTALL_ALL_TARGETS+=		check-files-post
.endif
_INSTALL_ALL_TARGETS+=		post-install-script
.if !defined(NO_PKG_REGISTER)
_INSTALL_ALL_TARGETS+=		register-pkg
.endif
_INSTALL_ALL_TARGETS+=		privileged-install-hook
_INSTALL_ALL_TARGETS+=		release-install-localbase-lock
_INSTALL_ALL_TARGETS+=		error-check

.if empty(CHECK_SHLIBS:M[nN][oO])
privileged-install-hook: check-shlibs
.endif
.if empty(CHECK_WRKREF:M[nN][oO])
privileged-install-hook: check-wrkref
.endif
.if empty(CHECK_FILES:M[nN][oO])
privileged-install-hook: check-files
.endif
.if empty(CHECK_INTERPRETER:M[nN][oO])
privileged-install-hook: check-interpreter
.endif

.PHONY: install-all su-install-all
install-all: su-target
su-install-all: ${_INSTALL_ALL_TARGETS}

######################################################################
### install-check-conflicts (PRIVATE, override)
######################################################################
### install-check-conflicts check for conflicts between the package and
### any installed packages.  This should be overridden per package
### system flavor.
###
.PHONY: install-check-conflicts
.if !target(install-check-conflicts)
install-check-conflicts:
	@${DO_NADA}
.endif

######################################################################
### install-check-installed (PRIVATE, override)
######################################################################
### install-check-installed checks if the package (perhaps an older
### version) is already installed on the system.  This should be
### overridden per package system flavor.
###
.PHONY: install-check-installed
.if !target(install-check-installed)
install-check-installed:
	@${DO_NADA}
.endif

######################################################################
### install-check-umask (PRIVATE)
######################################################################
### install-check-umask tests whether the umask is properly set and
### emits a non-fatal warning otherwise.
###
.PHONY: install-check-umask
install-check-umask:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	umask=`${SH} -c umask`;						\
	if ${TEST} "$$umask" -ne ${DEF_UMASK}; then			\
		${WARNING_MSG} "Your umask is \`\`$$umask''.";	\
		${WARNING_MSG} "If this is not desired, set it to an appropriate value (${DEF_UMASK}) and install"; \
		${WARNING_MSG} "this package again by \`\`${MAKE} deinstall reinstall''."; \
        fi

######################################################################
### install-makedirs (PRIVATE)
######################################################################
### install-makedirs is a target to create directories expected to
### exist prior to installation.  If a package sets INSTALLATION_DIRS,
### then it's known to pre-create all of the directories that it needs
### at install-time, so we don't need mtree to do it for us.
###
MTREE_FILE?=	${PKGSRCDIR}/mk/platform/${OPSYS}.pkg.dist
MTREE_ARGS?=	-U -f ${MTREE_FILE} -d -e -p

.PHONY: install-makedirs
install-makedirs:
	${_PKG_SILENT}${_PKG_DEBUG}${TEST} -d ${PREFIX} || ${MKDIR} ${PREFIX}
.if !defined(NO_MTREE)
	${_PKG_SILENT}${_PKG_DEBUG}${TEST} ! -f ${MTREE_FILE} ||	\
		${MTREE} ${MTREE_ARGS} ${PREFIX}/
.endif
.if defined(INSTALLATION_DIRS) && !empty(INSTALLATION_DIRS)
	@${STEP_MSG} "Creating installation directories"
	${_PKG_SILENT}${_PKG_DEBUG}					\
	for dir in ${INSTALLATION_DIRS}; do				\
		case "$$dir" in						\
		${PREFIX}/*)						\
			dir=`${ECHO} $$dir | ${SED} "s|^${PREFIX}/||"` ;; \
		/*)	continue ;;					\
		esac;							\
		case "$$dir" in						\
		*bin|*bin/*|*libexec|*libexec/*)			\
			${INSTALL_PROGRAM_DIR} ${PREFIX}/$$dir ;;	\
		${PKGMANDIR}/*)						\
			${INSTALL_MAN_DIR} ${PREFIX}/$$dir ;;		\
		*)							\
			${INSTALL_DATA_DIR} ${PREFIX}/$$dir ;;		\
		esac;							\
	done
.endif	# INSTALLATION_DIRS

######################################################################
### pre-install, do-install, post-install (PUBLIC, override)
######################################################################
### {pre,do,post}-install are the heart of the package-customizable
### install targets, and may be overridden within a package Makefile.
###
.PHONY: pre-install do-install post-install

INSTALL_DIRS?=		${BUILD_DIRS}
INSTALL_MAKE_FLAGS?=	${MAKE_FLAGS}
INSTALL_TARGET?=	install ${USE_IMAKE:D${NO_INSTALL_MANPAGES:D:Uinstall.man}}

.if !target(do-install)
do-install:
.  for _dir_ in ${INSTALL_DIRS}
	${_PKG_SILENT}${_PKG_DEBUG}${_ULIMIT_CMD}			\
	cd ${WRKSRC} && cd ${_dir_} &&					\
	${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${INSTALL_MAKE_FLAGS}	\
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
	${SETENV} PATH=${PATH:Q}					\
		MANZ=${_MANZ}						\
		PKG_VERBOSE=${PKG_VERBOSE}				\
		TEST=${TOOLS_TEST:Q}					\
	${SH} ${PKGSRCDIR}/mk/plist/doc-compress ${PREFIX}

.PHONY: install-doc-handling
install-doc-handling: plist
	@${STEP_MSG} "Automatic manual page handling"
	${_PKG_SILENT}${_PKG_DEBUG}${CAT} ${PLIST} | ${GREP} -v "^@" |	\
	${EGREP} ${_PLIST_REGEXP.man:Q} | ${_DOC_COMPRESS}

######################################################################
### register-pkg (PRIVATE, override)
######################################################################
### register-pkg registers the package as being installed on the system.
###
.PHONY: register-pkg
.if !target(register-pkg)
register-pkg:
	@${DO_NADA}
.endif

######################################################################
### privileged-install-hook (PRIVATE, override, hook)
######################################################################
### privileged-install-hook is a generic hook target that is run just
### before pkgsrc drops elevated privileges.
###
.PHONY: privileged-install-hook
.if !target(privileged-install-hook)
privileged-install-hook:
	@${DO_NADA}
.endif

######################################################################
### install-clean (PRIVATE)
######################################################################
### install-clean removes the state files for the "install" and
### later phases so that the "install" target may be re-invoked.
###
install-clean: package-clean check-clean
	${_PKG_SILENT}${_PKG_DEBUG}${RM} -f ${PLIST} ${_COOKIE.install}

######################################################################
### bootstrap-register (PUBLIC)
######################################################################
### bootstrap-register registers "bootstrap" packages that are installed
### by the pkgsrc/bootstrap/bootstrap script.
###
bootstrap-register: register-pkg clean
	@${DO_NADA}
