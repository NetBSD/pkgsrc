# $NetBSD: check-wrkref.mk,v 1.2 2006/06/06 18:07:50 jlam Exp $

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
.PHONY: check-wrkref
check-wrkref:
.if !defined(NO_PKG_REGISTER)
	${_PKG_SILENT}${_PKG_DEBUG}${STEP_MSG}				\
		"Checking for work-directory references in ${PKGNAME}"
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${PKG_FILELIST_CMD} | ${SORT} |					\
	{ while read file; do						\
		${_CHECK_WRKREF_SKIP_FILTER};				\
		${SHCOMMENT} [$$file];					\
		case ${_CHECK_WRKREF:Mwork:Q}"" in			\
		work)							\
			if ${GREP} -H ${WRKDIR} "$$file" 2>/dev/null; then \
				found=1;				\
			fi;						\
			;;						\
		esac;							\
		case ${_CHECK_WRKREF:Mtools:Q}"" in			\
		tools)							\
			if ${GREP} -H ${TOOLS_DIR} "$$file" 2>/dev/null; then \
				found=1;				\
			fi;						\
			;;						\
		esac;							\
	  done;								\
	  if ${TEST} "$$found" = 1; then				\
		${ECHO} "***";						\
		${ECHO} "*** The above files still have references to the build directory."; \
		${ECHO} "*** This is possibly an error that should be fixed by unwrapping"; \
		${ECHO} "*** the files or adding missing tools to the package makefile!"; \
		${ECHO} "***";						\
		exit 1;							\
	  fi; }
.endif
