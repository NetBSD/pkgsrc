# $NetBSD: libdir-usr-lib.mk,v 1.1.1.1 2004/08/27 21:34:58 jlam Exp $

.PHONY: libdir-usr-lib
do-regress: libdir-usr-lib
libdir-usr-lib:
	@test="-L/usr/lib";						\
	expected="";							\
	${TEST_RESULT}
