# $NetBSD: bsd.depends-vars.mk,v 1.4 2006/07/13 14:02:34 jlam Exp $
#
# This Makefile fragment is included separately by bsd.pkg.mk and
# defines some variables which must be defined earlier than where
# bsd.depends.mk is included.
#
# The following variables may be set in a package Makefile:
#
#    BOOTSTRAP_DEPENDS is a list of dependencies of the form "pattern:dir"
#	for packages that should be installed before any other stage is
#	invoked.
#
BOOTSTRAP_DEPENDS?=	# empty

_COOKIE.depends=	${WRKDIR}/.depends_done
