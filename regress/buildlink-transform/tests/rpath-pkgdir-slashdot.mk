# $NetBSD: rpath-pkgdir-slashdot.mk,v 1.1.1.1 2004/08/27 21:34:58 jlam Exp $

.PHONY: rpath-pkgdir-slashdot
do-regress: rpath-pkgdir-slashdot
rpath-pkgdir-slashdot:
	@test="${COMPILER_RPATH_FLAG}${LOCALBASE}/lib/.";		\
	expected="${COMPILER_RPATH_FLAG}${LOCALBASE}/lib";		\
	${TEST_RESULT}
