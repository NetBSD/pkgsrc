# $NetBSD: suff-self.mk,v 1.2 2024/09/17 11:52:33 jperkin Exp $
#
# See what happens if someone defines a self-referencing suffix
# transformation rule.

.SUFFIXES: .suff

.suff.suff:
	: Making ${.TARGET} out of ${.IMPSRC}.

all: suff-self.suff
