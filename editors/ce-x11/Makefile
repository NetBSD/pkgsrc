# $NetBSD: Makefile,v 1.3 2002/09/21 11:09:43 jlam Exp $
#

.include "../ce/Makefile.common"

PKGNAME=		ce-x11-${VERSION}
COMMENT+=		, X11 version

USE_BUILDLINK2=		# defined
USE_X11=		# defined

ALL_TARGET=		xce
INSTALL_TARGET=		install-x11 man-install-x11

.include "../../devel/ncurses/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
