# $NetBSD: Makefile,v 1.3 2003/08/28 20:05:16 xtraeme Exp $
#

DISTNAME=	SDLmm-0.1.8
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sdlmm/}

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://sdlmm.sourceforge.net/
COMMENT=	C++ Wrapper for the Simple DirectMedia Layer

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool

.include "../../devel/SDL/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
