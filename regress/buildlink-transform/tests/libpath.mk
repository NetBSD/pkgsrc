# $NetBSD: libpath.mk,v 1.1 2004/11/09 16:44:49 jlam Exp $

.PHONY: libpath
do-regress: libpath
libpath:
	@test="${LOCALBASE}/lib/libfoo.la";				\
	expected="${BUILDLINK_DIR}/lib/libfoo.la";			\
	${TEST_RESULT}
