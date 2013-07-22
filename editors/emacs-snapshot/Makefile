# $NetBSD: Makefile,v 1.43 2013/07/22 08:13:56 minskim Exp $

CONFLICTS+=	emacs${_EMACS_VERSION_MAJOR}-nox11-[0-9]*

.include "../../editors/emacs-snapshot/Makefile.common"

.include "options.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
