# $NetBSD: include-pkgsubdir.mk,v 1.1.1.1 2004/08/27 21:34:58 jlam Exp $

.PHONY: include-pkgsubdir
do-regress: include-pkgsubdir
include-pkgsubdir:
	@test="-I${LOCALBASE}/include/krb5";				\
	expected="-I${BUILDLINK_DIR}/include/krb5";			\
	${TEST_RESULT}
