# $NetBSD: Makefile,v 1.5 2001/12/05 04:29:32 jlam Exp $
#

DISTNAME=		xnibbles-1.0BETA4
PKGNAME=		xnibbles-1.0b4
CATEGORIES=		games x11
MASTER_SITES=		http://www.tjhsst.edu/xnibbles/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.tjhsst.edu/xnibbles/
COMMENT=		Winding snakes game for X11

USE_BUILDLINK_ONLY=	YES
USE_X11BASE=		YES
USE_GMAKE=		YES

WRKSRC=			${WRKDIR}/xnibbles
ALL_TARGET=		netbsd

MAKE_ENV+=		CC="${CXX}"
MAKE_FLAGS+=		INSTALL_PROGRAM="${INSTALL_PROGRAM}"
MAKE_FLAGS+=		INSTALL_DATA="${INSTALL_DATA}"
MAKE_FLAGS+=		INSTALL_MAN="${INSTALL_MAN}"
MAKE_FLAGS+=		INSTALL_DIR="${INSTALL_DATA_DIR}"

.include "../../graphics/xpm/buildlink.mk"
.include "../../mk/ossaudio.buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
