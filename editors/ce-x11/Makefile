# $NetBSD: Makefile,v 1.8 2004/07/28 16:37:15 schmonz Exp $
#

.include "../ce/Makefile.common"

PKGNAME=		ce-x11-${VERSION}
PKGREVISION=		1
COMMENT+=		, X11 version

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
USE_X11=		# defined

ALL_TARGET=		xce
INSTALL_TARGET=		install-x11 man-install-x11

INSTALLATION_DIRS=	bin man/man1

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
