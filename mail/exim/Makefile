# $NetBSD: Makefile,v 1.54 2005/02/13 01:16:44 grant Exp $

DISTNAME=	exim-${EXIM_VERSION}
PKGREVISION=	1
CATEGORIES=	mail net

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://www.exim.org/
COMMENT=	The Exim mail transfer agent, a replacement for sendmail

CONFLICTS+=	exim-exiscan-[0-9]*

.include "Makefile.common"

# Note: The distinfo in this directory includes the exiscan-acl-4.22-10.patch
# 'make mdi' or equivalent should be run from ../exim-exiscan-acl
