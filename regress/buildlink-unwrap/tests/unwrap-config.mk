# $NetBSD: unwrap-config.mk,v 1.1.1.1 2004/08/28 06:17:21 jlam Exp $

.PHONY: unwrap-config-cflags
do-regress: unwrap-config-cflags
unwrap-config-cflags:
	@test="unwrap-config --cflags";					\
	expected="-I${PREFIX}/include";					\
	${TEST_RESULT}

.PHONY: unwrap-config-ldflags
do-regress: unwrap-config-ldflags
unwrap-config-ldflags:
	@test="unwrap-config --ldflags";				\
	expected="-L${PREFIX}/lib ${COMPILER_RPATH_FLAG}${PREFIX}/lib";	\
	${TEST_RESULT}

.PHONY: unwrap-config-libs
do-regress: unwrap-config-libs
unwrap-config-libs:
	@test="unwrap-config --libs";					\
	expected="-ledit -ltermcap -lm";				\
	${TEST_RESULT}
