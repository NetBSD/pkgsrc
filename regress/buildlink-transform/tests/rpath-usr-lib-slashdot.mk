# $NetBSD: rpath-usr-lib-slashdot.mk,v 1.1.1.1 2004/08/27 21:34:58 jlam Exp $

.PHONY: rpath-usr-lib-slashdot
do-regress: rpath-usr-lib-slashdot
rpath-usr-lib-slashdot:
	@test="${COMPILER_RPATH_FLAG}/usr/lib/.";			\
	expected="";							\
	${TEST_RESULT}
