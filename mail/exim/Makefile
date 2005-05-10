# $NetBSD: Makefile,v 1.56 2005/05/10 22:52:06 abs Exp $

DISTNAME=	exim-${EXIM_VERSION}
PKGREVISION=	3
CATEGORIES=	mail net

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://www.exim.org/
COMMENT=	The Exim mail transfer agent, a replacement for sendmail

CONFLICTS+=	exim-exiscan-[0-9]*

.include "Makefile.common"

# Note: The distinfo in this directory includes the exiscan-acl-4.22-10.patch
# 'make mdi' or equivalent should be run from ../exim-exiscan-acl
