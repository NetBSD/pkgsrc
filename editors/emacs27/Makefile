# $NetBSD: Makefile,v 1.44 2024/11/14 22:19:38 wiz Exp $

CONFLICTS+=	emacs27-nox11-[0-9]*

PKGREVISION= 38
.include "../../editors/emacs27/Makefile.common"

.include "options.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
