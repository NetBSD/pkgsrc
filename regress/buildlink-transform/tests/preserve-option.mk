# $NetBSD: preserve-option.mk,v 1.1 2004/08/28 06:26:41 jlam Exp $

.PHONY: preserve-option
do-regress: preserve-option
preserve-option:
	@test="-O2ABC";							\
	expected="-O2ABC";						\
	${TEST_RESULT}
