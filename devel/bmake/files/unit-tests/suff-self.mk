# $NetBSD: suff-self.mk,v 1.1 2024/07/15 09:10:27 jperkin Exp $
#
# See what happens if someone defines a self-referencing suffix
# transformation rule.

.SUFFIXES: .suff

.suff.suff:
	: Making ${.TARGET} out of ${.IMPSRC}.

all: suff-self.suff
