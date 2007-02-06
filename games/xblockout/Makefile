# $NetBSD: Makefile,v 1.3 2007/02/06 17:08:19 joerg Exp $
#

DISTNAME=	xbl-1.1.5
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www710.univ-lyon1.fr/~exco/XBL/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www710.univ-lyon1.fr/ftp/xbl/xbl.html
COMMENT=	3D-tetris-like game

USE_TOOLS+=	imake
GNU_CONFIGURE=	yes
# libXext is not needed
BUILDLINK_TRANSFORM+=	rm:-lXext
INSTALLATION_DIRS=	bin lib/X11/app-defaults

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
