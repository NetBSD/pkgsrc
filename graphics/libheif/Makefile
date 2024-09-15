# $NetBSD: Makefile,v 1.32 2024/09/15 15:11:25 ryoon Exp $

DISTNAME=	libheif-1.18.2
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=strukturag/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/strukturag/libheif
COMMENT=	HEIF and AVIF file format decoder and encoder library
LICENSE=	gnu-lgpl-v3

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

CMAKE_CONFIGURE_ARGS+=	-DWITH_RAV1E=OFF
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_DISABLE_FIND_PACKAGE_TIFF=ON

PKGCONFIG_OVERRIDE+=	libheif.pc.in

BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../devel/cmake/build.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../multimedia/dav1d/buildlink3.mk"
.include "../../multimedia/libaom/buildlink3.mk"
.include "../../multimedia/libde265/buildlink3.mk"
.include "../../multimedia/svt-av1/buildlink3.mk"
.include "../../multimedia/x265/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
