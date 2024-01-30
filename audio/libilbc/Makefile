# $NetBSD: Makefile,v 1.2 2024/01/30 18:29:16 adam Exp $

DISTNAME=	libilbc-3.0.4
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=TimothyGu/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/TimothyGu/libilbc
COMMENT=	The iLBC codec from the WebRTC project
LICENSE=	modified-bsd

USE_CXX_FEATURES=	c++14
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config

PKGCONFIG_OVERRIDE+=	libilbc.pc.in

.include "../../devel/abseil/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
