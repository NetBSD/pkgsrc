# $NetBSD: remove-option.mk,v 1.1 2004/08/28 06:26:41 jlam Exp $

.PHONY: remove-option
do-regress: remove-option
remove-option:
	@test="-O2 -O5 -O9";						\
	expected="";							\
	${TEST_RESULT}
