# $NetBSD: Makefile,v 1.12 2021/09/29 19:00:34 adam Exp $

CONFLICTS+=	emacs27-nox11-[0-9]*

PKGREVISION= 6
.include "../../editors/emacs27/Makefile.common"

.include "options.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
