# $NetBSD: Makefile,v 1.15 2005/12/05 20:50:09 rillig Exp $
#

.include "../../editors/ce/Makefile.common"

PKGNAME=		ce-x11-${VERSION}
COMMENT+=		, X11 version

PKG_INSTALLATION_TYPES=	overwrite pkgviews


BUILD_TARGET=		xce
INSTALL_TARGET=		install-x11 man-install-x11

INSTALLATION_DIRS=	bin man/man1

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
