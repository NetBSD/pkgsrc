# $NetBSD: varmod-to-one-word.mk,v 1.2 2024/09/17 11:52:34 jperkin Exp $
#
# Tests for the :tW variable modifier, which treats the variable value
# as a single word, for all following modifiers.

SENTENCE=	The quick brown fox jumps over the lazy brown dog.

.if ${SENTENCE:tW:[#]} != 1
.  error
.endif
.if ${SENTENCE:tw:[#]} != 10
.  error
.endif

# Protect against accidental freeing of the variable value.
.if ${SENTENCE} != "The quick brown fox jumps over the lazy brown dog."
.  error
.endif

all:
	@:;
