# $NetBSD: remove-dir.mk,v 1.1 2004/09/25 22:05:46 jlam Exp $

.PHONY: remove-dir
do-regress: remove-dir
remove-dir:
	@test="-L/opt/schily/lib -I/opt/schily/include";		\
	expected="";							\
	${TEST_RESULT}
