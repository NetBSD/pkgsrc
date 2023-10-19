# $NetBSD: Makefile,v 1.4 2023/10/19 15:08:31 wiz Exp $

CONFLICTS+=	emacs29-nox11-[0-9]*

PKGREVISION=	3

.include "../../editors/emacs29/Makefile.common"

.include "options.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
