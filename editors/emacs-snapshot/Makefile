# $NetBSD: Makefile,v 1.40 2013/06/03 10:04:51 wiz Exp $

CONFLICTS+=	emacs${_EMACS_VERSION_MAJOR}-nox11-[0-9]*
PKGREVISION=	1

.include "../../editors/emacs-snapshot/Makefile.common"

.include "options.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
