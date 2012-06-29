# $NetBSD: Makefile,v 1.3 2012/06/29 06:31:35 wiz Exp $

CONFLICTS+=	emacs-nox11-[0-9]*

.include "../../editors/emacs24/Makefile.common"
PKGREVISION=	1

.include "options.mk"

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_VARS.prefix=	PREFIX
SUBST_FILES.prefix=	src/s/netbsd.h

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
