# $NetBSD: rpath-pkgdir-slashdot.mk,v 1.2 2004/08/30 05:03:32 jlam Exp $

.PHONY: rpath-pkgdir-slashdot
do-regress: rpath-pkgdir-slashdot
rpath-pkgdir-slashdot:
	@test="${COMPILER_RPATH_FLAG}${LOCALBASE}/lib/.";		\
	case "${_USE_RPATH}" in						\
	[yY][eE][sS])							\
		expected="${COMPILER_RPATH_FLAG}${LOCALBASE}/lib";	\
		;;							\
	*)								\
		expected="";						\
		;;							\
	esac;								\
	${TEST_RESULT}
