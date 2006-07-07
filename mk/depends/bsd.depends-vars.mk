# $NetBSD: bsd.depends-vars.mk,v 1.3 2006/07/07 21:24:28 jlam Exp $
#
# This Makefile fragment is included separately by bsd.pkg.mk and
# defines some variables which must be defined earlier than where
# bsd.depends.mk is included.
#

_COOKIE.depends=	${WRKDIR}/.depends_done
