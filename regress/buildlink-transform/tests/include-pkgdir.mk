# $NetBSD: include-pkgdir.mk,v 1.1.1.1 2004/08/27 21:34:58 jlam Exp $

.PHONY: include-pkgdir
do-regress: include-pkgdir
include-pkgdir:
	@test="-I${LOCALBASE}/include";					\
	expected="-I${BUILDLINK_DIR}/include";				\
	${TEST_RESULT}
