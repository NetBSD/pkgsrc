# $NetBSD: Makefile,v 1.12 2005/01/08 07:51:22 schmonz Exp $
#

.include "../ce/Makefile.common"

PKGNAME=		ce-x11-${VERSION}
COMMENT+=		, X11 version

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
USE_X11=		# defined

BUILD_TARGET=		xce
INSTALL_TARGET=		install-x11 man-install-x11

INSTALLATION_DIRS=	bin man/man1

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
