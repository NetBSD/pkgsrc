# $NetBSD: Makefile,v 1.14 2005/05/23 09:17:45 rillig Exp $
#

.include "Makefile.common"

COMMENT+=		, tty version

PKG_INSTALLATION_TYPES=	overwrite pkgviews

BUILD_TARGET=		ce
INSTALL_TARGET=		install man-install

INSTALLATION_DIRS=	bin man/man1

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
