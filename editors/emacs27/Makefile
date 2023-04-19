# $NetBSD: Makefile,v 1.23 2023/04/19 08:09:49 adam Exp $

CONFLICTS+=	emacs27-nox11-[0-9]*

PKGREVISION= 17
.include "../../editors/emacs27/Makefile.common"

.include "options.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
