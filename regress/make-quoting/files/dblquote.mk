# $NetBSD: dblquote.mk,v 1.1.1.1 2005/05/15 21:10:16 rillig Exp $
#
# This file demonstrates that quoted strings are interpreted when appying
# the ``modifiers'', not when creating strings by assignment.
#

DBLQUOTE=	"
DBLQUOTE+=	"a   b"
DBLQUOTE+=	"

all:
	echo ${DBLQUOTE:Q}
	echo ${DBLQUOTE:M*:Q}
