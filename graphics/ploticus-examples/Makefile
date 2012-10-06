# $NetBSD: Makefile,v 1.12 2012/10/06 14:11:14 asau Exp $
#

DISTNAME=	plnode141
PKGNAME=	ploticus-examples-1.41
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://gd.tuwien.ac.at/visual/ploticus/download/

MAINTAINER=	rh@NetBSD.org
# HOMEPAGE=	http://www.sgpr.net/
# domain squatted
COMMENT=	Examples for the ploticus data plotting suite

USE_TOOLS+=	pax

NO_CONFIGURE=	YES
NO_BUILD=	YES

DIST_SUBDIR=	${PKGNAME_NOREV:S/-examples//}
EXDIR=		${PREFIX}/share/examples/ploticus

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EXDIR}
	cd ${WRKSRC} && pax -rw -pp doc gallery tabgallery thumbnails thumbpng ${DESTDIR}${EXDIR}

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
