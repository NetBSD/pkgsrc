# $NetBSD: Makefile,v 1.7 2026/03/11 08:13:42 adam Exp $

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
