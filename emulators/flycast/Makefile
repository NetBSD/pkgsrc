# $NetBSD: Makefile,v 1.5 2024/01/30 14:21:46 ryoon Exp $

PKGREVISION= 1
.include "Makefile.common"

MAINTAINER=	nia@NetBSD.org
COMMENT=	Sega Dreamcast/Naomi/Atomiswave emulator

NOT_PAX_MPROTECT_SAFE+=	bin/flycast

.include "options.mk"
.include "../../audio/libao/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.fast.prefs.mk"
.if ${OPSYS} != "Darwin"
.  include "../../lang/lua52/buildlink3.mk"
.  include "../../www/curl/buildlink3.mk"
.endif
.include "../../mk/bsd.pkg.mk"
