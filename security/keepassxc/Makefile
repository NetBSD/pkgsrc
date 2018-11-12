# $NetBSD: Makefile,v 1.7 2018/11/12 03:52:51 ryoon Exp $

DISTNAME=	keepassxc-2.3.3
PKGREVISION=	3
CATEGORIES=	security x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=keepassxreboot/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://keepassxc.org/
COMMENT=	Password generator and manager
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2 AND gnu-lgpl-v2 AND gnu-lgpl-v3 AND mit AND cc0-1.0-universal

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
CMAKE_ARG_PATH=	..
CMAKE_ARGS+=	-DKEEPASSXC_BUILD_TYPE=Release
CONFIGURE_DIRS=	build

.PHONY: qmake-bin-add
pre-configure: qmake-bin-add

qmake-bin-add:
	${LN} -sf ${QTDIR}/bin/qmake ${BUILDLINK_DIR}/bin/

pre-configure:
	${MKDIR} ${WRKSRC}/build

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/argon2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
