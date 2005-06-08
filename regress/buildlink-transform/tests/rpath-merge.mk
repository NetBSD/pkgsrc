# $NetBSD: rpath-merge.mk,v 1.1 2005/06/08 05:49:21 jlam Exp $

.PHONY: rpath-merge
do-regress: rpath-merge
rpath-merge:
	@test="${COMPILER_RPATH_FLAG} -Wl,${LOCALBASE}/lib:${LOCALBASE}/lib/foo"; \
	case "${_USE_RPATH}" in						\
	[yY][eE][sS])							\
		expected="${COMPILER_RPATH_FLAG}${LOCALBASE}/lib ${COMPILER_RPATH_FLAG}${LOCALBASE}/lib/foo"; \
		;;							\
	*)								\
		expected="";						\
		;;							\
	esac;								\
	${TEST_RESULT}
