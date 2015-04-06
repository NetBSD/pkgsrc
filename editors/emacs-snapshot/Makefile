# $NetBSD: Makefile,v 1.56 2015/04/06 08:17:27 adam Exp $

PKGREVISION=	9
CONFLICTS+=	emacs${_EMACS_VERSION_MAJOR}-nox11-[0-9]*

.include "../../editors/emacs-snapshot/Makefile.common"

.include "options.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
