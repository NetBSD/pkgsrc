# $NetBSD: rpath-usr-lib.mk,v 1.1.1.1 2004/08/27 21:34:58 jlam Exp $

.PHONY: rpath-usr-lib
do-regress: rpath-usr-lib
rpath-usr-lib:
	@test="${COMPILER_RPATH_FLAG}/usr/lib";				\
	expected="";							\
	${TEST_RESULT}
