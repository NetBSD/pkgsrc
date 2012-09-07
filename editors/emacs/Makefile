# $NetBSD: Makefile,v 1.148 2012/09/07 19:16:29 adam Exp $

CONFLICTS+=	emacs-nox11-[0-9]*

.include "../../editors/emacs/Makefile.common"
PKGREVISION=	6

.include "options.mk"

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_VARS.prefix=	PREFIX
SUBST_FILES.prefix=	src/s/netbsd.h

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
