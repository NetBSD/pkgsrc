# $NetBSD: rpath-pkgsubdir.mk,v 1.2 2004/08/30 05:03:32 jlam Exp $

.PHONY: rpath-pkgsubdir
do-regress: rpath-pkgsubdir
rpath-pkgsubdir:
	@test="${COMPILER_RPATH_FLAG}${LOCALBASE}/lib/mysql";		\
	case "${_USE_RPATH}" in						\
	[yY][eE][sS])							\
		expected="${COMPILER_RPATH_FLAG}${LOCALBASE}/lib/mysql"; \
		;;							\
	*)								\
		expected="";						\
		;;							\
	esac;								\
	${TEST_RESULT}
