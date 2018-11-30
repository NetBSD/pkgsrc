# $NetBSD: for.mk,v 1.2 2018/11/30 19:06:33 rillig Exp $
#
# Up to 2015, .for loops didn't interpret variables in sh(1) mode, but
# split them at whitespace.
#
# Since 2015-05-20, the .for loops behave like the rest of Make,
# splitting at the quoting.

LIST_1=		1 2 "3     3"  '4 ' 5'5'5"5"5

all:
.for i in ${LIST_1}
	echo ${i:Q}
.endfor
