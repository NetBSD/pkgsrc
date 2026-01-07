# $NetBSD: Makefile,v 1.5 2026/01/07 08:46:53 wiz Exp $

PKGREVISION= 4
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
