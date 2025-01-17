# $NetBSD: Makefile,v 1.7 2025/01/17 16:28:09 vins Exp $

DISTNAME=	fastfetch-2.34.1
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=fastfetch-cli/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://github.com/fastfetch-cli/fastfetch/
COMMENT=	Fast and feature-rich tool displaying system information
LICENSE=	mit

USE_TOOLS+=	pkg-config

USE_LANGUAGES=	c c++

DEPENDS+=	hwdata-[0-9]*:../../misc/hwdata

.include "../../mk/bsd.prefs.mk"

SUBST_CLASSES+=		db
SUBST_STAGE.db=		pre-configure
SUBST_MESSAGE.db=	Setting pkgsrc database dir.
SUBST_FILES.ds+=	src/detection/packages/packages_obsd.c
SUBST_SED.db+=		-e "s:/usr/pkg/pkgdb:${PKG_DBDIR}:g"

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE=Release \
			-DCMAKE_INSTALL_PREFIX='${PREFIX}' \
			-DTARGET_DIR_USR='${PREFIX}' \
			-DTARGET_DIR_ETC='${PKG_SYSCONFDIR}' \
			-DCUSTOM_PCI_IDS_PATH=${PREFIX}/share/hwdata/pci.ids \
			-DCUSTOM_AMDGPU_IDS_PATH=${BUILDLINK_PREFIX.libdrm}/share/libdrm/amdgpu.ids \
			-DENABLE_SYSTEM_YYJSON=ON \
			-DBUILD_FLASHFETCH=OFF \
			-DBUILD_TESTS=ON

.include "options.mk"



.include "../../sysutils/libpciaccess/buildlink3.mk"
.include "../../devel/yyjson/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
