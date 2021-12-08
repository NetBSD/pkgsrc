# $NetBSD: Makefile,v 1.14 2021/12/08 16:04:09 adam Exp $

CONFLICTS+=	emacs27-nox11-[0-9]*

PKGREVISION= 8
.include "../../editors/emacs27/Makefile.common"

.include "options.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
