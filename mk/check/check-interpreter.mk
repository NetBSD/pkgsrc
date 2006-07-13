# $NetBSD: check-interpreter.mk,v 1.11 2006/07/13 19:07:54 heinz Exp $

# This file checks that after installation, all files of the package
# that start with a "#!" line will find their interpreter. Files that
# have a "#!" line with a non-existent interpreter will generate an
# error message if they are executable, and a warning message otherwise.
#
# The following variables may be set by the pkgsrc user in mk.conf:
#
# CHECK_INTERPRETER: YesNo (default: no)
#	Whether this check should be enabled or not.
#
# The following variables may be set by a package:
#
# CHECK_INTERPRETER_SKIP: List of paths or paths with wildcards
#	(default: empty)
#	(example: share/package1/* share/package2/somefile)
#	The list of files that are skipped when running the check.
#	Additionally, all files in share/examples and share/doc are
#	skipped as well.
#

CHECK_INTERPRETER?=		no
CHECK_INTERPRETER_SKIP?=	# empty

_CHECK_INTERP_SKIP=		share/doc/*
_CHECK_INTERP_SKIP+=		share/examples/*
_CHECK_INTERP_SKIP+=		${CHECK_INTERPRETER_SKIP}

_CHECK_INTERP_SKIP_FILTER=	case $$file in
_CHECK_INTERP_SKIP_FILTER+=	${_CHECK_INTERP_SKIP:@.pattern.@${PREFIX}/${.pattern.}|${.pattern.}) continue ;;@}
_CHECK_INTERP_SKIP_FILTER+=	*) ;;
_CHECK_INTERP_SKIP_FILTER+=	esac

_CHECK_INTERP_FILELIST_CMD?=	${PKG_FILELIST_CMD}

######################################################################
### check-interpreter (PRIVATE)
######################################################################
### check-interpreter verifies that the interpreters for all installed
### scripts exist.
###
.PHONY: check-interpreter
check-interpreter: error-check
	@${STEP_MSG} "Checking for non-existent script interpreters"	\
		     "in ${PKGNAME}"
.if !defined(NO_PKG_REGISTER)
	${_PKG_SILENT}${_PKG_DEBUG}					\
	set -e;								\
	${_CHECK_INTERP_FILELIST_CMD} | ${SORT} | ${SED} 's,\\,\\\\,g' |\
	while read file; do						\
		${_CHECK_INTERP_SKIP_FILTER};				\
		if ${TEST} ! -r "$$file"; then				\
			${DELAYED_WARNING_MSG} "[check-interpreter.mk] File \"$$file\" cannot be read."; \
			continue;					\
		fi;							\
		${SHCOMMENT} "[$$file]";				\
		interp=`${SED} -n -e '1s/^#![[:space:]]*\([^[:space:]]*\).*/\1/p' -e '1q' < "$$file"` \
		|| {	${DELAYED_WARNING_MSG} "[check-interpreter.mk] sed(1) failed for \"$$file\"."; \
			continue;					\
		};							\
		case $$interp in					\
		"") continue;						\
		esac;							\
		if ${TEST} ! -f "$$interp"; then			\
			if ${TEST} -x "$$file"; then			\
				${DELAYED_ERROR_MSG} "[check-interpreter.mk] The interpreter \"$$interp\" of \"$$file\" does not exist."; \
			else						\
				${DELAYED_WARNING_MSG} "[check-interpreter.mk] The interpreter \"$$interp\" of \"$$file\" does not exist."; \
			fi;						\
		fi;							\
	done
.endif
