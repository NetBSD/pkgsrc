# $NetBSD: libdir-usr-lib-slashdot.mk,v 1.1.1.1 2004/08/27 21:34:58 jlam Exp $

.PHONY: libdir-usr-lib-slashdot
do-regress: libdir-usr-lib-slashdot
libdir-usr-lib-slashdot:
	@test="-L/usr/lib/.";						\
	expected="";							\
	${TEST_RESULT}
