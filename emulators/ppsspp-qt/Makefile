# $NetBSD: Makefile,v 1.8 2026/03/11 08:13:43 adam Exp $

.include "../../emulators/ppsspp/Makefile.common"

PKGNAME=	${DISTNAME:S,ppsspp,ppsspp-qt,1}

HOMEPAGE=	https://www.ppsspp.org/
COMMENT=	Fast and portable PSP emulator (GUI frontend)

CONFLICTS+=	ppsspp-[0-9]*
CONFLICTS+=	libretro-ppsspp-[0-9]*

CMAKE_CONFIGURE_ARGS+=	-DUSING_QT_UI=ON

NOT_PAX_MPROTECT_SAFE+=	bin/PPSSPPQt

.include "../../devel/SDL2/buildlink3.mk"
.include "../../fonts/SDL2_ttf/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtmultimedia/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
