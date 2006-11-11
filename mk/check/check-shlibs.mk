# $NetBSD: check-shlibs.mk,v 1.7 2006/11/11 23:31:38 rillig Exp $
#
# This file verifies that all libraries used by the package can be found
# at run-time.
#
# User-settable variables:
#
# CHECK_SHLIBS:
#	Whether the check should be enabled or not.
#
#	Default value: "yes" for PKG_DEVELOPERs, "no" otherwise.
#
# Package-settable variables:
#
# CHECK_LIBS_SUPPORTED:
#	Whether the check should be enabled for this package or not.
#
#	Default value: yes
#

.if defined(PKG_DEVELOPER)
CHECK_SHLIBS?=			yes
.endif
CHECK_SHLIBS?=			no
CHECK_SHLIBS_SUPPORTED?=	yes

# All binaries and shared libraries.
_CHECK_SHLIBS_ERE=	/(bin/|sbin/|libexec/|lib/lib.*\.so|lib/lib.*\.dylib)

_CHECK_SHLIBS_FILELIST_CMD?=	${SED} -e '/^@/d' ${PLIST}

.if !empty(CHECK_SHLIBS:M[Yy][Ee][Ss]) && \
    !empty(CHECK_SHLIBS_SUPPORTED:M[Yy][Ee][Ss])
privileged-install-hook: _check-shlibs
.endif

_check-shlibs: error-check .PHONY
	@${STEP_MSG} "Checking for missing run-time search paths in ${PKGNAME}"
	${RUN} rm -f ${ERROR_DIR}/${.TARGET}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	exec 1>${ERROR_DIR}/${.TARGET};					\
	case ${LDD:Q}"" in						\
	"")	ldd=`${TYPE} ldd 2>/dev/null | ${AWK} '{ print $$NF }'` ;; \
	*)	ldd=${LDD:Q} ;;						\
	esac;								\
	${TEST} -x "$$ldd" || exit 0;					\
	${_CHECK_SHLIBS_FILELIST_CMD} |					\
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
