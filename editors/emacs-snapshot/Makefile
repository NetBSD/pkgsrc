# $NetBSD: Makefile,v 1.42 2013/06/06 12:54:15 wiz Exp $

CONFLICTS+=	emacs${_EMACS_VERSION_MAJOR}-nox11-[0-9]*
PKGREVISION=	3

.include "../../editors/emacs-snapshot/Makefile.common"

.include "options.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
