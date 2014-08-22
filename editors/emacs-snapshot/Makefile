# $NetBSD: Makefile,v 1.54 2014/08/22 11:24:30 wiz Exp $

PKGREVISION=	7
CONFLICTS+=	emacs${_EMACS_VERSION_MAJOR}-nox11-[0-9]*

.include "../../editors/emacs-snapshot/Makefile.common"

.include "options.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
