# $NetBSD: Makefile,v 1.10 2026/07/13 04:35:46 wiz Exp $

DISTNAME=	einstein-puzzle-2.5
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=0-wiz-0/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	https://github.com/0-wiz-0/einstein-puzzle/
COMMENT=	Computer implementation of a puzzle invented by Albert Einstein
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c++
USE_CXX_FEATURES+=	c++11

.include "../../devel/cmake/build.mk"
.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../fonts/SDL2_ttf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
