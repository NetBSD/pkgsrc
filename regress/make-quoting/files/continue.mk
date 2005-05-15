# $NetBSD: continue.mk,v 1.1.1.1 2005/05/15 21:10:16 rillig Exp $
#
# This file demonstrates that .for variables that end in a backslash are
# interpreted as line-continuations when they are placed at the end of a
# line.
#

LIST=		a:\ a:\foo.bar

.PHONY: all
all:
.for l in ${LIST}
	echo ${l:Q}
	echo "second line"
.endfor
.for l in ${LIST}
	echo ${l:Q}""
	echo "second line"
.endfor
