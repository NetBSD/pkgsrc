# $NetBSD: Makefile,v 1.10 2025/01/26 09:14:05 vins Exp $

DISTNAME=	fastfetch-2.34.1
PKGREVISION=	4
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

REPLACE_TOOL_PYTHON+=	scripts/gen-pciids.py scripts/gen-man.py

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_MESSAGE.paths=	Replacing hard-coded paths.
SUBST_FILES.paths+=	src/detection/packages/packages_obsd.c
SUBST_FILES.paths+=	doc/fastfetch.1.in scripts/gen-man.py
SUBST_SED.paths+=	-e "s:/usr/pkg/pkgdb:${PKG_DBDIR}:g"
SUBST_SED.paths+=	-e "s:/usr/share:${PREFIX}/share:g"

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE=Release \
			-DCMAKE_INSTALL_PREFIX='${PREFIX}' \
			-DBINARY_LINK_TYPE=dlopen \
			-DTARGET_DIR_USR='${PREFIX}' \
			-DTARGET_DIR_ETC='${PKG_SYSCONFDIR}' \
			-DCUSTOM_PCI_IDS_PATH=${PREFIX}/share/hwdata/pci.ids \
			-DCUSTOM_AMDGPU_IDS_PATH=${BUILDLINK_PREFIX.libdrm}/share/libdrm/amdgpu.ids \
			-DENABLE_SYSTEM_YYJSON=ON \
			-DENABLE_PCIACCES=ON \
			-DBUILD_FLASHFETCH=OFF \
			-DBUILD_TESTS=ON \
			-DINSTALL_LICENSE=OFF

.include "options.mk"

post-install:
	${INSTALL_DATA} ${FILESDIR}/minimal.jsonc	\
		${DESTDIR}${PREFIX}/share/fastfetch/presets

# Whether Python is required strictly as a build tool or also at runtime is
# determined in options.mk, and PYTHON_FOR_BUILD_ONLY is set there, if needed.
.include "../../lang/python/tool.mk"
.include "../../lang/python/application.mk"
PYTHON_VERSIONS_INCOMPATIBLE=   27

.include "../../sysutils/libpciaccess/buildlink3.mk"
.include "../../devel/yyjson/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
