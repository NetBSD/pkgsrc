# $NetBSD: Makefile,v 1.1 2025/01/06 19:34:59 vins Exp $

DISTNAME=	fastfetch-2.33.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=fastfetch-cli/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://github.com/fastfetch-cli/fastfetch/
COMMENT=	Fast and feature-rich tool displaying system information
LICENSE=	mit

USE_TOOLS+=	pkg-config

USE_LANGUAGES=	c c++

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE=Release \
			-DTARGET_DIR_ETC='${PKG_SYSCONFDIR}' \
			-DCMAKE_INSTALL_PREFIX='${PREFIX}' \
			-DBUILD_FLASHFETCH=OFF \
			-DBUILD_TESTS=ON

.include "options.mk"

.include "../../sysutils/libpciaccess/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
