# $NetBSD: Makefile,v 1.27 2023/10/19 15:08:31 wiz Exp $

CONFLICTS+=	emacs27-nox11-[0-9]*

PKGREVISION= 21
.include "../../editors/emacs27/Makefile.common"

.include "options.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
