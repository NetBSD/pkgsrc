# $NetBSD: include-usr-include.mk,v 1.1.1.1 2004/08/27 21:34:58 jlam Exp $

.PHONY: include-usr-include
do-regress: include-usr-include
include-usr-include:
	@test="-I/usr/include";						\
	expected="";							\
	${TEST_RESULT}
