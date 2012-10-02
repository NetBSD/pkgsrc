# $NetBSD: Makefile,v 1.150 2012/10/02 17:10:53 tron Exp $

CONFLICTS+=	emacs-nox11-[0-9]*

.include "../../editors/emacs/Makefile.common"
PKGREVISION=	8

.include "options.mk"

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_VARS.prefix=	PREFIX
SUBST_FILES.prefix=	src/s/netbsd.h

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
