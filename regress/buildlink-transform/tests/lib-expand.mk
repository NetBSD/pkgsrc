# $NetBSD: lib-expand.mk,v 1.2 2004/08/29 06:23:12 jlam Exp $

.PHONY: lib-expand
do-regress: lib-expand
lib-expand:
	@test="-lreadline -lreadline";					\
	expected="-ledit -ltermcap -lm";				\
	${TEST_RESULT}
