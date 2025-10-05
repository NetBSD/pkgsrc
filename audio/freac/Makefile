# $NetBSD: Makefile,v 1.3 2025/10/05 19:25:40 js Exp $

DISTNAME=	freac-1.1.7
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=enzo1982/}
GITHUB_PROJECT=	freac
GITHUB_RELEASE=	v1.1.7

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/enzo1982/freac/
COMMENT=	The fre:ac audio converter
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

MAKE_FLAGS+=	prefix=${PREFIX}

.include "../../audio/boca/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
