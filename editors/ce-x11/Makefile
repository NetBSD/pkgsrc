# $NetBSD: Makefile,v 1.7 2004/04/11 08:41:04 snj Exp $
#

.include "../ce/Makefile.common"

PKGNAME=		ce-x11-${VERSION}
PKGREVISION=		1
COMMENT+=		, X11 version

USE_BUILDLINK3=		yes
USE_X11=		# defined

ALL_TARGET=		xce
INSTALL_TARGET=		install-x11 man-install-x11

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
