# $NetBSD: no-abspath.mk,v 1.1.1.1 2004/08/27 21:34:58 jlam Exp $

.PHONY: no-abspath
do-regress: no-abspath
no-abspath:
	@test="-L/bad/path/lib -I/bad/path/include ${COMPILER_RPATH_FLAG}/bad/path/lib"; \
	expected="";							\
	${TEST_RESULT}
