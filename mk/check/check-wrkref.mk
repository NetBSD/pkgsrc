# $NetBSD: check-wrkref.mk,v 1.3 2006/06/07 17:05:25 jlam Exp $

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

###########################################################################
# check-wrkref target
#
_CHECK_WRKREF_FOUND=	${WRKDIR}/.check_wrkref_found

.PHONY: check-wrkref
check-wrkref: check-wrkref-message check-wrkref-clean ${_CHECK_WRKREF_FOUND}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	if ${_ZERO_FILESIZE_P} ${_CHECK_WRKREF_FOUND}; then		\
		${DO_NADA};						\
	else								\
		${ERROR_MSG} "The following files still have references to the build directory."; \
		${ERROR_MSG} "This is possibly an error that should be fixed by unwrapping"; \
		${ERROR_MSG} "the files or adding missing tools to the package makefile!"; \
		${ERROR_MSG} "";					\
		${CAT} ${_CHECK_WRKREF_FOUND} | ${ERROR_CAT};		\
		exit 1;							\
	fi

.PHONY: check-wrkref-message
check-wrkref-message:
	@${STEP_MSG} "Checking for work-directory references in ${PKGNAME}"

check-clean: check-wrkref-clean
.PHONY: check-wrkref-clean
check-wrkref-clean:
	${_PKG_SILENT}${_PKG_DEBUG}${RM} -f ${_CHECK_WRKREF_FOUND}

${_CHECK_WRKREF_FOUND}:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${PKG_FILELIST_CMD} | ${SORT} |					\
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
	done > ${.TARGET}.tmp
	${_PKG_SILENT}${_PKG_DEBUG}${MV} -f ${.TARGET}.tmp ${.TARGET}
