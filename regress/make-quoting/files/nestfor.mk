# $NetBSD: nestfor.mk,v 1.1.1.1 2005/05/15 21:10:16 rillig Exp $
#
# This file tests what happens if the same variable name is used in
# nested .for loops.
#
# The result is somewhat surprising, in that the outer i is used.
#

X=		# empty
.for i in a b c
.  for i in 0 1 2
X+=		${i}
.  endfor
.endfor

all:
	echo ${X:M*:Q}
