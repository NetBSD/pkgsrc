# $NetBSD: libdir-usr-lib-subdir.mk,v 1.1.1.1 2004/08/27 21:34:58 jlam Exp $

.PHONY: libdir-usr-lib-subdir
do-regress: libdir-usr-lib-subdir
libdir-usr-lib-subdir:
	@test="-L/usr/lib/i18n";					\
	expected="-L/usr/lib/i18n";					\
	${TEST_RESULT}
