# $NetBSD: Makefile,v 1.1.1.1 2004/01/10 19:45:39 jschauma Exp $

DISTNAME=	BlenderManual.html
PKGNAME=	blender-doc-20030922
WRKSRC=		${WRKDIR}/doc
CATEGORIES=	graphics
MASTER_SITES=	http://download.blender.org/documentation/

MAINTAINER=	jschauma@NetBSD.org
HOMEPAGE=	http://download.blender.org/documentation/
COMMENT=	Documentation for Blender

CONFLICTS=	blender<=2.31

NO_CONFIGURE=	# defined
NO_BUILD=	# defined

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/blender
	cd ${WRKDIR}/html && ${PAX} -s,.*/CVS.*,, -s,.*/.xvpics.*,, \
		-rw . ${PREFIX}/share/doc/html/blender
	cd ${PREFIX}/share/doc/html/blender && ${LN} -s book1.html index.html

.include "../../mk/bsd.pkg.mk"
