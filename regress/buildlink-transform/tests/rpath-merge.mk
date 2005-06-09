# $NetBSD: rpath-merge.mk,v 1.2 2005/06/09 17:01:11 jlam Exp $

.PHONY: rpath-merge
do-regress: rpath-merge
rpath-merge:
	@test="${COMPILER_RPATH_FLAG:S/,$//} -Wl,${LOCALBASE}/lib:${LOCALBASE}/lib/foo"; \
	case "${_USE_RPATH}" in						\
	[yY][eE][sS])							\
		expected="${COMPILER_RPATH_FLAG}${LOCALBASE}/lib ${COMPILER_RPATH_FLAG}${LOCALBASE}/lib/foo"; \
		;;							\
	*)								\
		expected="";						\
		;;							\
	esac;								\
	${TEST_RESULT}
