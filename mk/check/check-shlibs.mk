# $NetBSD: check-shlibs.mk,v 1.4 2006/09/14 22:00:49 rillig Exp $

# For PKG_DEVELOPERs, cause some checks to be run automatically by default.
.if defined(PKG_DEVELOPER)
CHECK_SHLIBS?=		yes
.endif
CHECK_SHLIBS?=		no

# All binaries and shared libraries.
_CHECK_SHLIBS_ERE=	/(bin/|sbin/|libexec/|lib/lib.*\.so|lib/lib.*\.dylib)

######################################################################
### check-shlibs (PRIVATE)
######################################################################
### check-shlibs verifies that all libraries used by the package can be
### found at run-time.
###
.PHONY: check-shlibs
.if !empty(CHECK_SHLIBS_SUPPORTED:M[nN][oO])
check-shlibs:
	@${DO_NADA}
.else
check-shlibs: error-check
	@${STEP_MSG} "Checking for missing run-time search paths in ${PKGNAME}"
.  if !defined(NO_PKG_REGISTER)
	${_PKG_SILENT}${_PKG_DEBUG}${RM} -f ${ERROR_DIR}/${.TARGET}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	exec 1>${ERROR_DIR}/${.TARGET};					\
	case ${LDD:Q}"" in						\
	"")	ldd=`${TYPE} ldd 2>/dev/null | ${AWK} '{ print $$NF }'` ;; \
	*)	ldd=${LDD:Q} ;;						\
	esac;								\
	${TEST} -x "$$ldd" || exit 0;					\
	${PKG_FILELIST_CMD} |						\
	${EGREP} -h ${_CHECK_SHLIBS_ERE:Q} |				\
	while read file; do						\
		err=`$$ldd $$file 2>&1 | ${GREP} "not found" || ${TRUE}`; \
		${TEST} -z "$$err" || ${ECHO} "$$file: $$err";		\
	done
	${_PKG_SILENT}${_PKG_DEBUG}					\
	exec 1>>${ERROR_DIR}/${.TARGET};				\
	if ${_NONZERO_FILESIZE_P} ${ERROR_DIR}/${.TARGET}; then		\
		${ECHO} "*** The above programs/libs will not find the listed shared libraries"; \
		${ECHO} "    at runtime.  Please fix the package (add -Wl,-R.../lib in the right"; \
		${ECHO} "    places)!";					\
		${SHCOMMENT} Might not error-out for non-pkg-developers; \
	fi
.  endif
.endif
