# $NetBSD: Makefile,v 1.3 2023/11/08 13:19:05 wiz Exp $

PKGREVISION= 2
.include "Makefile.common"

MAINTAINER=	nia@NetBSD.org
COMMENT=	Sega Dreamcast/Naomi/Atomiswave emulator

NOT_PAX_MPROTECT_SAFE+=	bin/flycast

.include "options.mk"
.include "../../mk/bsd.fast.prefs.mk"
.if ${OPSYS} != "Darwin"
.  include "../../www/curl/buildlink3.mk"
.endif
.include "../../audio/libao/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
