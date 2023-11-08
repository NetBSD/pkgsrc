# $NetBSD: Makefile,v 1.29 2023/11/08 13:19:02 wiz Exp $

CONFLICTS+=	emacs27-nox11-[0-9]*

PKGREVISION= 23
.include "../../editors/emacs27/Makefile.common"

.include "options.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
