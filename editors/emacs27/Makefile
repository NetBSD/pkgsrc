# $NetBSD: Makefile,v 1.46 2024/11/24 06:59:05 adam Exp $

CONFLICTS+=	emacs27-nox11-[0-9]*

PKGREVISION= 40
.include "../../editors/emacs27/Makefile.common"

.include "options.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
