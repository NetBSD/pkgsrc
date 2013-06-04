# $NetBSD: Makefile,v 1.41 2013/06/04 22:15:57 tron Exp $

CONFLICTS+=	emacs${_EMACS_VERSION_MAJOR}-nox11-[0-9]*
PKGREVISION=	2

.include "../../editors/emacs-snapshot/Makefile.common"

.include "options.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
