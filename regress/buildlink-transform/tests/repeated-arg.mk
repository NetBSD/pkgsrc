# $NetBSD: repeated-arg.mk,v 1.1.1.1 2004/08/27 21:34:58 jlam Exp $

.PHONY: repeated-arg
do-regress: repeated-arg
repeated-arg:
	@test="-L${LOCALBASE}/lib -L${LOCALBASE}/lib";			\
	expected="-L${BUILDLINK_DIR}/lib";				\
	${TEST_RESULT}
