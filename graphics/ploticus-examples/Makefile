# $NetBSD: Makefile,v 1.11 2008/05/26 02:13:20 joerg Exp $
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

PKG_DESTDIR_SUPPORT=	user-destdir

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
