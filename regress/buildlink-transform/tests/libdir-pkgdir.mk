# $NetBSD: libdir-pkgdir.mk,v 1.1.1.1 2004/08/27 21:34:58 jlam Exp $

.PHONY: libdir-pkgdir
do-regress: libdir-pkgdir
libdir-pkgdir:
	@test="-L${LOCALBASE}/lib";					\
	expected="-L${BUILDLINK_DIR}/lib";				\
	${TEST_RESULT}
