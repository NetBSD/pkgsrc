# $NetBSD: Makefile,v 1.39 2024/09/16 07:20:13 adam Exp $

CONFLICTS+=	emacs27-nox11-[0-9]*

PKGREVISION= 33
.include "../../editors/emacs27/Makefile.common"

.include "options.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
