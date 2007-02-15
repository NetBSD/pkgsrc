# $NetBSD: Makefile,v 1.9 2007/02/15 14:58:22 joerg Exp $
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

NO_CONFIGURE=	YES
NO_BUILD=	YES

DIST_SUBDIR=	${PKGNAME_NOREV:S/-examples//}
EXDIR=		${PREFIX}/share/examples/ploticus

do-install:
	${INSTALL_DATA_DIR} ${EXDIR}
	cd ${WRKSRC} && ${PAX} -rw -pp doc gallery tabgallery thumbnails thumbpng ${EXDIR}

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
