# $NetBSD: Makefile,v 1.5 2008/03/04 15:39:09 jlam Exp $

DISTNAME=	BlenderManual.html
PKGNAME=	blender-doc-20030922
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://download.blender.org/documentation/

MAINTAINER=	jschauma@NetBSD.org
HOMEPAGE=	http://download.blender.org/documentation/
COMMENT=	Documentation for Blender

CONFLICTS=	blender<=2.31

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/doc
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/blender
	cd ${WRKDIR}/html && ${PAX} -s,.*/CVS.*,, -s,.*/.xvpics.*,, \
		-rw . ${DESTDIR}${PREFIX}/share/doc/blender
	cd ${DESTDIR}${PREFIX}/share/doc/blender && \
		${LN} -s book1.html index.html

.include "../../mk/bsd.pkg.mk"
