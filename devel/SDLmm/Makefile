# $NetBSD: Makefile,v 1.4 2004/02/14 17:21:36 jlam Exp $
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

.include "../../devel/SDL/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
