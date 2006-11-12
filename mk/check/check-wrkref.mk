# $NetBSD: check-wrkref.mk,v 1.9 2006/11/12 00:09:50 rillig Exp $
#
# This file checks that the installed files don't contain any strings
# that point to the directory where the package had been built, to make
# sure that the package still works after the source code has been
# cleaned up.
#
# User-settable variables:
#
# CHECK_WRKREF:
#	The kind of directory that must not appear in installed files.
#
#	* "no" to disable this check at all
#	* "tools" for the tool wrapper directory
#	* "work" for WRKDIR
#	* "wrkobjdir" for WRKOBJDIR
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

_CHECK_WRKREF_DIR.no=		# none
_CHECK_WRKREF_DIR.work=		${WRKDIR}
_CHECK_WRKREF_DIR.tools=	${TOOLS_DIR}
_CHECK_WRKREF_DIR.wrkobjdir=	${WRKOBJDIR}

.if !defined(_CHECK_WRKREF_DIR.${CHECK_WRKREF})
PKG_FAIL_REASON+=	"[check-wrkref.mk] CHECK_WRKREF must be one of { no tools work objwrkdir }."
.endif
_CHECK_WRKREF_DIR=	${_CHECK_WRKREF_DIR.${CHECK_WRKREF}}

check-wrkref: error-check .PHONY
	@${STEP_MSG} "Checking for work-directory references in ${PKGNAME}"
	${RUN} rm -f ${ERROR_DIR}/${.TARGET}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	exec 1>${ERROR_DIR}/${.TARGET};					\
	cd ${DESTDIR}${PREFIX};						\
	${_CHECK_WRKREF_FILELIST_CMD} | ${SORT} |			\
	while read file; do						\
		case "$$file" in					\
		${CHECK_WRKREF_SKIP:@p@${p}) continue;; @}		\
		*) ;;							\
		esac;							\
		${SHCOMMENT} "[$$file]";				\
		case ${_CHECK_WRKREF_DIR:Q}"" in			\
		"")	${ERROR_MSG} "[check-wrkref.mk] The directory to check is empty."; \
			exit 1;						\
			;;						\
		*)	grep ${_CHECK_WRKREF_DIR:Q}"" "$$file" 2>/dev/null | \
			sed -e "s|^|$$file:	|";			\
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
