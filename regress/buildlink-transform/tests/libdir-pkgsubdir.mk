# $NetBSD: libdir-pkgsubdir.mk,v 1.1.1.1 2004/08/27 21:34:58 jlam Exp $

.PHONY: libdir-pkgsubdir
do-regress: libdir-pkgsubdir
libdir-pkgsubdir:
	@test="-L${LOCALBASE}/lib/mysql";				\
	expected="-L${BUILDLINK_DIR}/lib/mysql";			\
	${TEST_RESULT}
