# $NetBSD: Makefile,v 1.138 2011/11/01 06:11:53 sbd Exp $

PKGREVISION=	1

CONFLICTS+=	emacs-nox11-[0-9]*

.include "../../editors/emacs/Makefile.common"

.include "options.mk"

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_VARS.prefix=	PREFIX
SUBST_FILES.prefix=	src/s/netbsd.h

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
