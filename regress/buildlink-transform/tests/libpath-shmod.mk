# $NetBSD: libpath-shmod.mk,v 1.1 2005/01/26 05:01:44 jlam Exp $

.PHONY: libpath-shmod
do-regress: libpath-shmod
libpath-shmod:
	@test="${LOCALBASE}/lib/module/foo.so";				\
	expected="${LOCALBASE}/lib/module/foo.so";			\
	${TEST_RESULT}
