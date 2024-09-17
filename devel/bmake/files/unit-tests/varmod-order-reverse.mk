# $NetBSD: varmod-order-reverse.mk,v 1.2 2024/09/17 11:52:34 jperkin Exp $
#
# Tests for the :Or variable modifier, which returns the words, sorted in
# descending order.

WORDS=		one two three four five six seven eight nine ten

.if ${WORDS:Or} != "two three ten six seven one nine four five eight"
.  error ${WORDS:Or}
.endif

all:
