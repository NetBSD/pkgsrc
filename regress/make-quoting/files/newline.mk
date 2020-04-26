# $NetBSD: newline.mk,v 1.2 2020/04/26 13:11:17 rillig Exp $
#
# This file documents a bug from 2006 in the :Q operator, which did not
# handle the newline character correctly. It produced
# <backslash><newline> instead of the proper <quote><newline><quote>.
#
# Somewhere between 2006 and 2020 it has been fixed.
#

S=	foo ${.newline} bar

all:
	printf "%s\\n" ${S:Q}
