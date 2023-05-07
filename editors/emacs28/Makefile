# $NetBSD: Makefile,v 1.13 2023/05/07 12:33:44 wiz Exp $

CONFLICTS+=	emacs28-nox11-[0-9]*

PKGREVISION= 7
.include "../../editors/emacs28/Makefile.common"

.include "options.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
