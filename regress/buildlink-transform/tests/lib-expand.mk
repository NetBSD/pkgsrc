# $NetBSD: lib-expand.mk,v 1.1 2004/08/28 06:26:41 jlam Exp $

.PHONY: lib-expand
do-regress: lib-expand
lib-expand:
	@test="-lreadline";						\
	expected="-ledit -ltermcap -lm";				\
	${TEST_RESULT}
