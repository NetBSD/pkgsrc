# $NetBSD: Makefile,v 1.19 2020/01/26 05:26:21 rillig Exp $
#

DISTNAME=	SDLmm-0.1.8
PKGREVISION=	7
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sdlmm/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sdlmm.sourceforge.net/
COMMENT=	C++ Wrapper for the Simple DirectMedia Layer

GNU_CONFIGURE=	YES
USE_LANGUAGES=	c c++
USE_LIBTOOL=	YES

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
