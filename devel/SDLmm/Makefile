# $NetBSD: Makefile,v 1.8 2005/03/27 15:43:33 wiz Exp $
#

DISTNAME=	SDLmm-0.1.8
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sdlmm/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://sdlmm.sourceforge.net/
COMMENT=	C++ Wrapper for the Simple DirectMedia Layer

GNU_CONFIGURE=	YES
USE_BUILDLINK3=	YES
USE_LIBTOOL=	YES

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
