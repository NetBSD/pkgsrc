# $NetBSD: libpath-shlib.mk,v 1.1 2005/01/26 05:01:44 jlam Exp $

.PHONY: libpath-shlib
do-regress: libpath-shlib
libpath-shlib:
	@test="${LOCALBASE}/lib/libfoo.so";				\
	expected="-L${BUILDLINK_DIR}/lib -lfoo";			\
	${TEST_RESULT}
