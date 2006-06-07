# $NetBSD: check-interpreter.mk,v 1.3 2006/06/07 17:41:14 jlam Exp $

CHECK_INTERPRETER?=	no

###########################################################################
# CHECK_INTERPRETER_SKIP is a list of shell globs.  Installed files that
# match these globs are skipped when running the check-interpreter target.
#
CHECK_INTERPRETER_SKIP?=	# empty

_CHECK_INTERP_SKIP_FILTER=	case $$file in
.for _pattern_ in ${CHECK_INTERPRETER_SKIP}
_CHECK_INTERP_SKIP_FILTER+=	${PREFIX}/${_pattern_}|${_pattern_}) continue ;;
.endfor
_CHECK_INTERP_SKIP_FILTER+=	*) ;;
_CHECK_INTERP_SKIP_FILTER+=	esac

###########################################################################
# check-interpreter target
#
.PHONY: check-interpreter
check-interpreter:
	${_PKG_SILENT}${_PKG_DEBUG}${STEP_MSG}				\
		"Checking for non-existent script interpreters in ${PKGNAME}"
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${PKG_FILELIST_CMD} | ${SORT} | ${SED} 's,\\,\\\\,g' |		\
	{ exitcode=0;							\
	  while read file; do						\
		${_CHECK_INTERP_SKIP_FILTER};				\
		${SHCOMMENT} "[$$file]";				\
		interp=`${SED} -n -e '1s/^#![[:space:]]*\([^[:space:]]*\).*/\1/p' -e '1q' < "$$file"` \
		|| {	${WARNING_MSG} "[check-interpreter.mk] sed(1) failed for \"$$file\"."; \
			continue;					\
		};							\
		case $$interp in					\
		"") continue;						\
		esac;							\
		if ${TEST} ! -f "$$interp"; then			\
			if ${TEST} -x "$$file"; then			\
				${ERROR_MSG} "[check-interpreter.mk] The interpreter \"$$interp\" of \"$$file\" does not exist."; \
				exitcode=1;				\
			else						\
				${WARNING_MSG} "[check-interpreter.mk] The interpreter \"$$interp\" of \"$$file\" does not exist."; \
			fi;						\
		fi;							\
	  done;								\
	  exit $$exitcode; }
