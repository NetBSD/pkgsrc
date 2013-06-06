# $NetBSD: Makefile,v 1.17 2013/06/06 12:54:15 wiz Exp $

CONFLICTS+=	emacs24-nox11-[0-9]*
PKGREVISION=	3

.include "../../editors/emacs24/Makefile.common"

.include "options.mk"

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_VARS.prefix=	PREFIX
SUBST_FILES.prefix=	src/s/netbsd.h

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
