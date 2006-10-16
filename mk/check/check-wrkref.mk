# $NetBSD: check-wrkref.mk,v 1.6 2006/10/16 19:02:53 seb Exp $

.if defined(PKG_DEVELOPER)
CHECK_WRKREF?=		tools
.endif
CHECK_WRKREF?=		no

###########################################################################
# CHECK_WRKREF_SKIP is a list of shell globs.  Installed files that
# match these globs are skipped when running the check-wrkref target.
#
.if !defined(_CHECK_WRKREF_SKIP_FILTER)
_CHECK_WRKREF_SKIP_FILTER=	${TRUE}
.  if defined(CHECK_WRKREF_SKIP) && !empty(CHECK_WRKREF_SKIP)
_CHECK_WRKREF_SKIP_FILTER=	case "$$file" in
_CHECK_WRKREF_SKIP_FILTER+=	${_CHECK_WRKREF_SKIP_FILTER_BODY}
_CHECK_WRKREF_SKIP_FILTER+=	*) ;;
_CHECK_WRKREF_SKIP_FILTER+=	esac
.  endif
.endif
.if !defined(_CHECK_WRKREF_SKIP_FILTER_BODY)
.  for _pattern_ in ${CHECK_WRKREF_SKIP}
_CHECK_WRKREF_SKIP_FILTER_BODY+=	${_pattern_}) continue ;;
.  endfor
.endif
MAKEVARS+=	_CHECK_WRKREF_SKIP_FILTER_BODY

_CHECK_WRKREF:=		${CHECK_WRKREF}
.if !empty(_CHECK_WRKREF:Mwork)
_CHECK_WRKREF:=		work		# "work" is the "max" option
.endif

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
	cd ${PREFIX};							\
	${_CHECK_WRKREF_FILELIST_CMD} | ${SORT} |			\
	while read file; do						\
		${_CHECK_WRKREF_SKIP_FILTER};				\
		${SHCOMMENT} [$$file];					\
		case ${_CHECK_WRKREF:Mwork:Q}"" in			\
		work)							\
			${GREP} ${WRKDIR} "$$file" 2>/dev/null |	\
			${SED} -e "s|^|$$file:	|";			\
			;;						\
		esac;							\
		case ${_CHECK_WRKREF:Mtools:Q}"" in			\
		tools)							\
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
