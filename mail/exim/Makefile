# $NetBSD: Makefile,v 1.46 2004/05/07 17:47:32 abs Exp $

DISTNAME=	exim-${EXIM_VERSION}
PKGREVISION=	1
CATEGORIES=	mail net

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.exim.org/
COMMENT=	The Exim mail transfer agent, a replacement for sendmail

CONFLICTS+=	exim-exiscan-[0-9]*

.include "Makefile.common"

# Note: The distinfo in this directory includes the exiscan-acl-4.22-10.patch
# 'make mdi' or equivalent should be run from ../exim-exiscan-acl
