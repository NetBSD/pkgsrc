# $NetBSD: Makefile,v 1.9 2012/10/06 14:10:42 asau Exp $

DISTNAME=	BlenderManual.html
PKGNAME=	blender-doc-20030922
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://download.blender.org/documentation/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://download.blender.org/documentation/
COMMENT=	Documentation for Blender

CONFLICTS=	blender<=2.31

WRKSRC=		${WRKDIR}/doc
NO_CONFIGURE=	yes
NO_BUILD=	yes
USE_TOOLS+=	pax

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/blender
	cd ${WRKDIR}/html && pax -s,.*/CVS.*,, -s,.*/.xvpics.*,, \
		-rw . ${DESTDIR}${PREFIX}/share/doc/blender
	cd ${DESTDIR}${PREFIX}/share/doc/blender && \
		${LN} -s book1.html index.html

.include "../../mk/bsd.pkg.mk"
