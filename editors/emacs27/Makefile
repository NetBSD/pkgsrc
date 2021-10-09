# $NetBSD: Makefile,v 1.13 2021/10/09 15:35:04 nia Exp $

CONFLICTS+=	emacs27-nox11-[0-9]*

PKGREVISION= 7
.include "../../editors/emacs27/Makefile.common"

.include "options.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
