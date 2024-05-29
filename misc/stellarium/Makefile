# $NetBSD: Makefile,v 1.161 2024/05/29 16:33:39 adam Exp $

DISTNAME=	stellarium-24.1
PKGREVISION=	3
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=Stellarium/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://stellarium.org/
COMMENT=	Generate photorealistic skies with OpenGL
LICENSE=	gnu-gpl-v2

USE_CXX_FEATURES=	c++17
USE_LANGUAGES=		c c++
USE_TOOLS+=		msgfmt perl pod2man
GCC_REQD+=		12 # std::from_chars

CMAKE_ARGS+=	-DENABLE_GPS=OFF
CMAKE_ARGS+=	-DENABLE_SHOWMYSKY=OFF

LDFLAGS.SunOS+=	-lnsl -lsocket

PLIST_VARS+=		desktop

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Darwin"
PLIST.desktop=		yes
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../graphics/exiv2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/qt6-qtcharts/buildlink3.mk"
.include "../../math/QXlsx/buildlink3.mk"
.include "../../math/nlopt/buildlink3.mk"
.include "../../misc/indi/buildlink3.mk"
.include "../../multimedia/qt6-qtmultimedia/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt6-qtserialport/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
