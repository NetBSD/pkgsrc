# $NetBSD: distname.mk,v 1.1 2006/10/23 13:52:32 rillig Exp $
#
# DISTNAME
#	Every package definition should start with the definition of this
#	variable. It is used in three places:
#
#	1. It is the first part of the default value for DISTFILES.
#	2. It is the default value for PKGNAME, except for the trailing
#	   "nb" part.
#	3. The default value of WRKSRC is ${WRKDIR}/${DISTNAME}.
#
