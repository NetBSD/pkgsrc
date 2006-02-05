# $NetBSD: Makefile,v 1.6 2006/02/05 23:09:37 joerg Exp $
#

DISTNAME=	plnode141
PKGNAME=	ploticus-examples-1.41
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.sgpr.net/download/ \
		http://gd.tuwien.ac.at/visual/ploticus/download/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.sgpr.net/
COMMENT=	Examples for the ploticus data plotting suite

NO_CONFIGURE=	YES
NO_BUILD=	YES

DIST_SUBDIR=	${PKGNAME_NOREV:S/-examples//}
EXDIR=		${PREFIX}/share/examples/ploticus

.include "../../mk/x11.buildlink3.mk"

do-install:
	${INSTALL_DATA_DIR} ${EXDIR}
.for dir in doc gallery tabgallery thumbnails thumbpng
	${INSTALL_DATA_DIR} ${EXDIR}/${dir}
	${CP} -R ${WRKSRC}/${dir} ${EXDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
