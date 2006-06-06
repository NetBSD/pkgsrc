# $NetBSD: bsd.fetch-vars.mk,v 1.2 2006/06/06 15:28:52 jlam Exp $
#
# This Makefile fragment is included separately by bsd.pkg.mk and
# defines some variables which must be defined earlier than where
# bsd.fetch.mk is included.
#
# The following variables may be set by the user:
#
#    DISTDIR is the top-level directory into which all original
#	distribution files are fetched.
#
# The following variables may be set in a package Makefile:
#
#    DIST_SUBDIR is the subdirectory of ${DISTDIR} in which the original
#	distribution files for the package are fetched.
#
#    DISTFILES is the list of distribution files that are fetched.
#

# The default DISTDIR is currently set in bsd.prefs.mk.
#DISTDIR?=               ${PKGSRCDIR}/distfiles

_DISTDIR=		${DISTDIR}/${DIST_SUBDIR}
DISTFILES?=		${DISTNAME}${EXTRACT_SUFX}
