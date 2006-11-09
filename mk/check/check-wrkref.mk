# $NetBSD: check-wrkref.mk,v 1.8 2006/11/09 15:10:16 rillig Exp $
#
# This file checks that the installed files don't contain any strings
# that point to the directory where the package had been built, to make
# sure that the package still works after the source code has been
# cleaned up.
#
# User-settable variables:
#
# CHECK_WRKREF:
#	The kind of check that should be done. Say "no" for no check
#	at all, "tools" for checking references to the directory where
#	the tool wrappers had been, and "work" to check references to
#	anything from the working directory.
#
#	Default value: "tools" for PKG_DEVELOPERs, "no" otherwise.
#
# Package-settable variables:
#
# CHECK_WRKREF_SKIP:
#	The list of filename patterns that should be excluded from this
#	test.
#

.if defined(PKG_DEVELOPER)
CHECK_WRKREF?=		tools
.endif
CHECK_WRKREF?=		no
CHECK_WRKREF_SKIP?=	# none

_CHECK_WRKREF_FILELIST_CMD?=	${SED} -e '/^@/d' ${PLIST}

######################################################################
### check-wrkref (PRIVATE)
######################################################################
### check-wrkref verifies that the installed files are free of
### hard-coded references to the work directory.
###
.PHONY: check-wrkref
check-wrkref: error-check
	@${STEP_MSG} "Checking for work-directory references in ${PKGNAME}"
.if !defined(NO_PKG_REGISTER)
	${_PKG_SILENT}${_PKG_DEBUG}${RM} -f ${ERROR_DIR}/${.TARGET}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	exec 1>${ERROR_DIR}/${.TARGET};					\
	cd ${DESTDIR}${PREFIX};						\
	${_CHECK_WRKREF_FILELIST_CMD} | ${SORT} |			\
	while read file; do						\
		case "$$file" in					\
		${CHECK_WRKREF_SKIP:@p@${p}) continue;; @}		\
		*) ;;							\
		esac;							\
		${SHCOMMENT} [$$file];					\
		case ${CHECK_WRKREF:Q}"" in				\
		*work*)							\
			${GREP} ${WRKDIR} "$$file" 2>/dev/null |	\
			${SED} -e "s|^|$$file:	|";			\
			;;						\
		*tools*)						\
			${GREP} ${TOOLS_DIR} "$$file" 2>/dev/null |	\
			${SED} -e "s|^|$$file:	|";			\
			;;						\
		esac;							\
	done
	${_PKG_SILENT}${_PKG_DEBUG}					\
	exec 1>>${ERROR_DIR}/${.TARGET};				\
	if ${_NONZERO_FILESIZE_P} ${ERROR_DIR}/${.TARGET}; then		\
		${ECHO} "*** The above files still have references to the build directory."; \
		${ECHO} "    This is possibly an error that should be fixed by unwrapping"; \
		${ECHO} "    the files or adding missing tools to the package makefile!"; \
	fi
.endif
