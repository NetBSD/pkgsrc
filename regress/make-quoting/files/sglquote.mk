# $NetBSD: sglquote.mk,v 1.1.1.1 2005/05/15 21:10:16 rillig Exp $
#
# This file demonstrates the differences between single and double
# quotes.
#

STR_1=		'\''\''a   b' 'z'
STR_2=		"\""\""a   b" "z"

all:
	echo ${STR_1}
	echo ${STR_1:Q}
	echo ${STR_1:M*:Q}
	echo ${STR_2}
	echo ${STR_2:Q}
	echo ${STR_2:M*:Q}
