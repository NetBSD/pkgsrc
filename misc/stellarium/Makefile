# $NetBSD: Makefile,v 1.130 2021/12/30 20:22:08 adam Exp $

DISTNAME=	stellarium-0.21.3
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=Stellarium/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://stellarium.org/
COMMENT=	Generate photorealistic skies with OpenGL
LICENSE=	gnu-gpl-v2

USE_CMAKE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		msgfmt perl pod2man

CMAKE_ARGS+=	-DENABLE_GPS=OFF

LDFLAGS.SunOS+=	-lnsl -lsocket

PLIST_VARS+=		desktop

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Darwin"
PLIST.desktop=		yes
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qtscript/buildlink3.mk"
.include "../../x11/qt5-qtserialport/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
