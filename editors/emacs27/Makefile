# $NetBSD: Makefile,v 1.16 2022/07/14 23:46:19 dholland Exp $

CONFLICTS+=	emacs27-nox11-[0-9]*

PKGREVISION= 10
.include "../../editors/emacs27/Makefile.common"

.include "options.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
