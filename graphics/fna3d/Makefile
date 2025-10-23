# $NetBSD: Makefile,v 1.13 2025/10/23 20:37:27 wiz Exp $

DISTNAME=	FNA3D-22.05
PKGNAME=	${DISTNAME:tl}
PKGREVISION=	7
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=FNA-XNA/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://fna-xna.github.io/
COMMENT=	3D graphics library for FNA
LICENSE=	zlib

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

# No upstream install target
INSTALLATION_DIRS=      lib include
do-install:
	${INSTALL_DATA} ${WRKSRC}/include/*.h ${DESTDIR}${PREFIX}/include/
	${INSTALL_DATA} ${WRKSRC}/${CMAKE_BUILD_DIR}/libFNA3D.so* ${DESTDIR}${PREFIX}/lib/

.include "../../devel/cmake/build.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/vulkan-headers/buildlink3.mk"
.include "../../graphics/mojoshader/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
