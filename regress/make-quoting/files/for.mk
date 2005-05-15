# $NetBSD: for.mk,v 1.1.1.1 2005/05/15 21:10:16 rillig Exp $
#
# .for loops don't interpret variables in sh(1) mode, but split them at
# whitespace.

LIST_1=		1 2 "3     3"  '4 ' 5'5'5"5"5

all:
.for i in ${LIST_1}
	echo ${i:Q}
.endfor
