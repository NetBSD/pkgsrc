# $NetBSD: Makefile,v 1.42 2024/11/01 00:51:36 wiz Exp $

CONFLICTS+=	emacs27-nox11-[0-9]*

PKGREVISION= 36
.include "../../editors/emacs27/Makefile.common"

.include "options.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
