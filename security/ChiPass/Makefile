# $NetBSD: Makefile,v 1.1 2026/10/19 08:39:42 wiz Exp $

DISTNAME=	ChiPass
VERSION=	2026.09.0
PKGNAME=	${DISTNAME}-${VERSION}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_CODEBERG:=ChiPass/}
CODEBERG_TAG=	v${VERSION}
DIST_SUBDIR=	chipass-${PKGVERSION_NOREV}

MAINTAINER=	gourd753+netbsd@xenos5.net
HOMEPAGE=	https://codeberg.org/ChiPass/ChiPass
COMMENT=	Password generator and manager
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2 AND gnu-lgpl-v2 AND gnu-lgpl-v3 AND mit AND cc0-1.0-universal

TOOL_DEPENDS+=	qt6-qttranslations>=0:../../x11/qt6-qttranslations

USE_TOOLS+=		pkg-config

# botan3
GCC_REQD+=	11

WRKSRC=		${WRKDIR}/chipass

USE_LANGUAGES=		c c++
CMAKE_CONFIGURE_ARGS+=	-DCHIPASS_BUILD_TYPE=Release
CMAKE_CONFIGURE_ARGS+=	-DCHIPASS_ENABLE_MANUAL=OFF

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	src/CMakeLists.txt
SUBST_VARS.prefix=	PREFIX

#NOT_PAX_MPROTECT_SAFE+=	bin/ChiPass

.PHONY: qmake-bin-add
pre-configure: qmake-bin-add

qmake-bin-add:
	${LN} -sf ${QTDIR}/bin/qmake ${BUILDLINK_DIR}/bin/

.include "options.mk"

.include "../../archivers/minizip/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../converters/qrencode/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../security/argon2/buildlink3.mk"
.include "../../security/botan3/buildlink3.mk"
.include "../../security/zxcvbn-c/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../graphics/qt6-qtsvg/buildlink3.mk"
.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../devel/qt6-qt5compat/buildlink3.mk"
.include "../../devel/libusb1/buildlink3.mk"
.include "../../devel/appstream/buildlink3.mk"
# does not support editline
.include "../../devel/readline/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
