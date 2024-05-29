# $NetBSD: Makefile,v 1.37 2024/05/29 16:32:22 adam Exp $

CONFLICTS+=	emacs27-nox11-[0-9]*

PKGREVISION= 31
.include "../../editors/emacs27/Makefile.common"

.include "options.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
