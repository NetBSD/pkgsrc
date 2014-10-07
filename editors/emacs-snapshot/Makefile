# $NetBSD: Makefile,v 1.55 2014/10/07 16:47:24 adam Exp $

PKGREVISION=	8
CONFLICTS+=	emacs${_EMACS_VERSION_MAJOR}-nox11-[0-9]*

.include "../../editors/emacs-snapshot/Makefile.common"

.include "options.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
