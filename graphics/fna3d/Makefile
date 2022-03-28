# $NetBSD: Makefile,v 1.4 2022/03/28 10:44:21 tnn Exp $

GITHUB_PROJECT=	FNA3D
GITHUB_TAG=	21.01
DISTNAME=	21.01
PKGNAME=	${GITHUB_PROJECT:tl}-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=FNA-XNA/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://fna-xna.github.io/
COMMENT=	3D graphics library for FNA
LICENSE=	zlib

WRKSRC=		${WRKDIR}/FNA3D-21.01
USE_CMAKE=	yes

# No upstream install target
INSTALLATION_DIRS=      lib include
do-install:
	${INSTALL_DATA} ${WRKSRC}/include/*.h ${DESTDIR}${PREFIX}/include/
	${INSTALL_DATA} ${WRKSRC}/libFNA3D.so* ${DESTDIR}${PREFIX}/lib/

.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/vulkan-headers/buildlink3.mk"
.include "../../graphics/mojoshader/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
