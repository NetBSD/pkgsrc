# $NetBSD: Makefile,v 1.2 2012/06/26 17:02:31 asau Exp $

CONFLICTS+=	emacs-nox11-[0-9]*

.include "../../editors/emacs24/Makefile.common"
PKGREVISON=	1

.include "options.mk"

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_VARS.prefix=	PREFIX
SUBST_FILES.prefix=	src/s/netbsd.h

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
