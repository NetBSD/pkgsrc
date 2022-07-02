# $NetBSD: Makefile,v 1.46 2022/07/02 16:53:33 ryoon Exp $

DISTNAME=	keepassxc-2.7.1-src
PKGNAME=	${DISTNAME:S/-src//}
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=keepassxreboot/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://keepassxc.org/
COMMENT=	Password generator and manager
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2 AND gnu-lgpl-v2 AND gnu-lgpl-v3 AND mit AND cc0-1.0-universal

SUPERSEDES+=	keepassx-[0-9]*
SUPERSEDES+=	keepassx0-[0-9]*

WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
CMAKE_ARG_PATH=	..
CMAKE_ARGS+=	-DKEEPASSXC_BUILD_TYPE=Release
CMAKE_ARGS+=	-DWITH_XC_DOCS=OFF
CMAKE_ARGS+=	-DWITH_XC_BROWSER=ON
CONFIGURE_DIRS=	build

NOT_PAX_MPROTECT_SAFE+=	bin/keepassxc

.PHONY: qmake-bin-add
pre-configure: qmake-bin-add

qmake-bin-add:
	${LN} -sf ${QTDIR}/bin/qmake ${BUILDLINK_DIR}/bin/

pre-configure:
	${MKDIR} ${WRKSRC}/build

.include "../../converters/qrencode/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../security/argon2/buildlink3.mk"
.include "../../security/botan2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
# does not support editline
.include "../../devel/readline/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
