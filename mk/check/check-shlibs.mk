# $NetBSD: check-shlibs.mk,v 1.1 2006/06/03 23:11:42 jlam Exp $

# For PKG_DEVELOPERs, cause some checks to be run automatically by default.
.if defined(PKG_DEVELOPER)
CHECK_SHLIBS?=		yes
.endif
CHECK_SHLIBS?=		no

# All binaries and shared libraries.
_CHECK_SHLIBS_ERE=	/(bin/|sbin/|libexec/|lib/lib.*\.so|lib/lib.*\.dylib)

###########################################################################
# check-shlibs target
#
.PHONY: check-shlibs
check-shlibs:
.if !empty(CHECK_SHLIBS_SUPPORTED:M[yY][eE][sS]) && !defined(NO_PKG_REGISTER)
	${_PKG_SILENT}${_PKG_DEBUG}${STEP_MSG}				\
		"Checking for missing run-time search paths in ${PKGNAME}"
	${_PKG_SILENT}${_PKG_DEBUG}					\
	case ${LDD:Q}"" in						\
	"")	ldd=`${TYPE} ldd 2>/dev/null | ${AWK} '{ print $$NF }'` ;; \
	*)	ldd=${LDD:Q} ;;						\
	esac;								\
	${TEST} -x "$$ldd" || exit 0;					\
	${PKG_FILELIST_CMD} |						\
	{ ${EGREP} -h ${_CHECK_SHLIBS_ERE:Q} || ${TRUE}; } |		\
	{ while read file; do						\
		${TEST} -z ${PKG_VERBOSE:Q}"" || ${ECHO} "$$ldd $$file"; \
		err=`{ $$ldd $$file 2>&1 || ${TRUE}; } | { ${GREP} "not found" || ${TRUE}; }`; \
		if ${TEST} -n "$$err"; then				\
			${ECHO} "$$file: $$err";			\
			error=1;					\
		fi;							\
	  done;								\
	  if ${TEST} "$$error" = 1; then				\
		${ECHO} "*** The above programs/libs will not find the listed shared libraries"; \
		${ECHO} "    at runtime.  Please fix the package (add -Wl,-R.../lib in the right"; \
		${ECHO} "    places)!";					\
		${SHCOMMENT} Might not error-out for non-pkg-developers; \
		exit 1;							\
          fi; }
.endif
