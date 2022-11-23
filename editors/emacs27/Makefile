# $NetBSD: Makefile,v 1.19 2022/11/23 16:19:55 adam Exp $

CONFLICTS+=	emacs27-nox11-[0-9]*

PKGREVISION= 13
.include "../../editors/emacs27/Makefile.common"

.include "options.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
