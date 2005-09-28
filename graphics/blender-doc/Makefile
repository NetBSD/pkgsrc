# $NetBSD: Makefile,v 1.3 2005/09/28 20:52:22 rillig Exp $

DISTNAME=	BlenderManual.html
PKGNAME=	blender-doc-20030922
CATEGORIES=	graphics
MASTER_SITES=	http://download.blender.org/documentation/

MAINTAINER=	jschauma@NetBSD.org
HOMEPAGE=	http://download.blender.org/documentation/
COMMENT=	Documentation for Blender

CONFLICTS=	blender<=2.31

WRKSRC=		${WRKDIR}/doc
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/blender
	cd ${WRKDIR}/html && ${PAX} -s,.*/CVS.*,, -s,.*/.xvpics.*,, \
		-rw . ${PREFIX}/share/doc/html/blender
	cd ${PREFIX}/share/doc/html/blender && ${LN} -s book1.html index.html

.include "../../mk/bsd.pkg.mk"
