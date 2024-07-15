# $NetBSD: varmod-order-reverse.mk,v 1.1 2024/07/15 09:10:30 jperkin Exp $
#
# Tests for the :Or variable modifier, which returns the words, sorted in
# descending order.

WORDS=		one two three four five six seven eight nine ten

.if ${WORDS:Or} != "two three ten six seven one nine four five eight"
.  error ${WORDS:Or}
.endif

all:
