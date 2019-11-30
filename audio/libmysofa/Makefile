# $NetBSD: Makefile,v 1.1 2019/11/30 13:35:42 nia Exp $

DISTNAME=	libmysofa-0.9
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=hoene/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/hoene/libmysofa
COMMENT=	Reader for AES SOFA HRTF files
LICENSE=	modified-bsd

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config

CMAKE_ARGS+=	-Wno-dev
CMAKE_ARGS+=	-DBUILD_TESTS=OFF

PKGCONFIG_OVERRIDE+=	libmysofa.pc.cmake

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
