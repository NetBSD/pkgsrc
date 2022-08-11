# $NetBSD: Makefile,v 1.17 2022/08/11 05:08:15 gutteridge Exp $

CONFLICTS+=	emacs27-nox11-[0-9]*

PKGREVISION= 11
.include "../../editors/emacs27/Makefile.common"

.include "options.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
