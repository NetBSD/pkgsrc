# $NetBSD: Makefile,v 1.1.1.1 2001/07/08 08:26:30 rh Exp $
#

DISTNAME=	plnode141
PKGNAME=	ploticus-examples-1.41
CATEGORIES=	graphics
MASTER_SITES=	http://www.sgpr.net/download/ \
		http://gd.tuwien.ac.at/visual/ploticus/download/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.sgpr.net/
COMMENT=	examples for the ploticus data plotting suite

NO_CONFIGURE=	YES
NO_BUILD=	YES

USE_X11=	YES
DIST_SUBDIR=	${PKGNAME:S/-examples//}
EXDIR=		${PREFIX}/share/examples/ploticus

do-install:
	${INSTALL_DATA_DIR} ${EXDIR}
.for dir in doc gallery tabgallery thumbnails thumbpng
	${INSTALL_DATA_DIR} ${EXDIR}/${dir}
	${CP} -R ${WRKSRC}/${dir} ${EXDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
