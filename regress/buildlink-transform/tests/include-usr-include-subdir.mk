# $NetBSD: include-usr-include-subdir.mk,v 1.1.1.1 2004/08/27 21:34:58 jlam Exp $

.PHONY: include-usr-include-subdir
do-regress: include-usr-include-subdir
include-usr-include-subdir:
	@test="-I/usr/include/krb5";					\
	expected="-I/usr/include/krb5";					\
	${TEST_RESULT}
