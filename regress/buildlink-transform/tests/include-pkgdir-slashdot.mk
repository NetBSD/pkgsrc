# $NetBSD: include-pkgdir-slashdot.mk,v 1.1.1.1 2004/08/27 21:34:58 jlam Exp $

.PHONY: include-pkgdir-slashdot
do-regress: include-pkgdir-slashdot
include-pkgdir-slashdot:
	@test="-I${LOCALBASE}/include/.";				\
	expected="-I${BUILDLINK_DIR}/include";				\
	${TEST_RESULT}
