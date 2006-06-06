# $NetBSD: bsd.depends-vars.mk,v 1.2 2006/06/06 15:28:52 jlam Exp $
#
# This Makefile fragment is included separately by bsd.pkg.mk and
# defines some variables which must be defined earlier than where
# bsd.depends.mk is included.
#

_DEPENDS_COOKIE=	${WRKDIR}/.depends_done
