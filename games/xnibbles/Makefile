# $NetBSD: Makefile,v 1.9 2004/01/20 12:15:42 agc Exp $
#

DISTNAME=		xnibbles-1.0BETA4
PKGNAME=		xnibbles-1.0b4
PKGREVISION=		1
CATEGORIES=		games x11
MASTER_SITES=		http://www.tjhsst.edu/xnibbles/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.tjhsst.edu/xnibbles/
COMMENT=		Winding snakes game for X11

WRKSRC=			${WRKDIR}/xnibbles
USE_BUILDLINK2=		YES
USE_X11=		YES
USE_GMAKE=		YES

ALL_TARGET=		netbsd

CC=			${CXX}
MAKE_FLAGS+=		INSTALL_PROGRAM="${INSTALL_PROGRAM}"
MAKE_FLAGS+=		INSTALL_DATA="${INSTALL_DATA}"
MAKE_FLAGS+=		INSTALL_MAN="${INSTALL_MAN}"
MAKE_FLAGS+=		INSTALL_DIR="${INSTALL_DATA_DIR}"

.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/ossaudio.buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
