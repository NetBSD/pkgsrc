# $NetBSD: Makefile,v 1.18 2007/01/30 22:52:07 joerg Exp $
#

.include "../../editors/ce/Makefile.common"

PKGNAME=		ce-x11-${VERSION}
PKGREVISION=		1
COMMENT+=		, X11 version

PKG_INSTALLATION_TYPES=	overwrite pkgviews


BUILD_TARGET=		xce
INSTALL_TARGET=		install-x11 man-install-x11

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../mk/curses.buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
