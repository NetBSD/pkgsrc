# $NetBSD: Makefile,v 1.9 2004/10/03 00:14:38 tv Exp $
#

.include "../ce/Makefile.common"

PKGNAME=		ce-x11-${VERSION}
PKGREVISION=		2
COMMENT+=		, X11 version

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
USE_X11=		# defined

ALL_TARGET=		xce
INSTALL_TARGET=		install-x11 man-install-x11

INSTALLATION_DIRS=	bin man/man1

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
