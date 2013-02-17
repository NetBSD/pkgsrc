# $NetBSD: Makefile,v 1.38 2013/02/17 06:18:01 dholland Exp $

CONFLICTS+=	emacs${_EMACS_VERSION_MAJOR}-nox11-[0-9]*

.include "../../editors/emacs-snapshot/Makefile.common"

PKGREVISION=		1

.include "options.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
