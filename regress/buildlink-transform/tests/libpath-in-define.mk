# $NetBSD: libpath-in-define.mk,v 1.1 2004/11/09 16:44:49 jlam Exp $

.PHONY: libpath-in-define
do-regress: libpath-in-define
libpath-in-define:
	@test="-DFOO=\"${LOCALBASE}/lib/libfoo.la\"";			\
	expected="-DFOO=\"${LOCALBASE}/lib/libfoo.la\"";		\
	${TEST_RESULT}
