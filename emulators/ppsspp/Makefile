# $NetBSD: Makefile,v 1.12 2026/09/27 11:36:03 tnn Exp $

PKGREVISION= 3
.include "Makefile.common"

HOMEPAGE=	https://www.ppsspp.org/
COMMENT=	Fast and portable PSP emulator

CONFLICTS+=	ppsspp-qt-[0-9]*
CONFLICTS+=	libretro-ppsspp-[0-9]*

NOT_PAX_MPROTECT_SAFE+=	bin/PPSSPPSDL

.include "../../devel/SDL2/buildlink3.mk"
.include "../../fonts/SDL2_ttf/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
