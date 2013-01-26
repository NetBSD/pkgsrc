# $NetBSD: Makefile,v 1.11 2013/01/26 21:37:27 adam Exp $

PKGREVISION=	5

CONFLICTS+=	emacs-nox11-[0-9]*

.include "../../editors/emacs24/Makefile.common"

.include "options.mk"

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_VARS.prefix=	PREFIX
SUBST_FILES.prefix=	src/s/netbsd.h

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
