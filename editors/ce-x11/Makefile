# $NetBSD: Makefile,v 1.10 2004/12/03 15:14:55 wiz Exp $
#

.include "../ce/Makefile.common"

PKGNAME=		ce-x11-${VERSION}
PKGREVISION=		2
COMMENT+=		, X11 version

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
USE_X11=		# defined

BUILD_TARGET=		xce
INSTALL_TARGET=		install-x11 man-install-x11

INSTALLATION_DIRS=	bin man/man1

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
