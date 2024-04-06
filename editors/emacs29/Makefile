# $NetBSD: Makefile,v 1.12 2024/04/06 09:32:56 wiz Exp $

CONFLICTS+=	emacs29-nox11-[0-9]*

PKGREVISION= 2
.include "../../editors/emacs29/Makefile.common"

.include "options.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
