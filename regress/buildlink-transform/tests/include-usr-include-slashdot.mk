# $NetBSD: include-usr-include-slashdot.mk,v 1.1.1.1 2004/08/27 21:34:58 jlam Exp $

.PHONY: include-usr-include-slashdot
do-regress: include-usr-include-slashdot
include-usr-include-slashdot:
	@test="-I/usr/include/.";					\
	expected="";							\
	${TEST_RESULT}
