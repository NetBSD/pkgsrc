# $NetBSD: Makefile,v 1.4 2003/07/13 13:51:29 wiz Exp $
#

.include "../ce/Makefile.common"

PKGNAME=		ce-x11-${VERSION}
PKGREVISION=		1
COMMENT+=		, X11 version

USE_BUILDLINK2=		# defined
USE_X11=		# defined

ALL_TARGET=		xce
INSTALL_TARGET=		install-x11 man-install-x11

.include "../../devel/ncurses/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
