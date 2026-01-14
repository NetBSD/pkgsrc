# $NetBSD: Makefile,v 1.8 2026/01/14 12:57:31 wiz Exp $

DISTNAME=	libilbc-3.0.4
PKGREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=TimothyGu/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/TimothyGu/libilbc
COMMENT=	The iLBC codec from the WebRTC project
LICENSE=	modified-bsd

USE_CXX_FEATURES=	c++17
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config
FORCE_CXX_STD=		c++17

PKGCONFIG_OVERRIDE+=	libilbc.pc.in

.include "../../devel/abseil/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
