# $NetBSD: libdir-pkgdir-slashdot.mk,v 1.1.1.1 2004/08/27 21:34:58 jlam Exp $

.PHONY: libdir-pkgdir-slashdot
do-regress: libdir-pkgdir-slashdot
libdir-pkgdir-slashdot:
	@test="-L${LOCALBASE}/lib/.";					\
	expected="-L${BUILDLINK_DIR}/lib";				\
	${TEST_RESULT}
