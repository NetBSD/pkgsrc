# $NetBSD: Makefile,v 1.7 2022/10/26 10:31:23 wiz Exp $

CONFLICTS+=	emacs28-nox11-[0-9]*

PKGREVISION= 1
.include "../../editors/emacs28/Makefile.common"

.include "options.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
