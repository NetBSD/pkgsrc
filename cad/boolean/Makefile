# $NetBSD: Makefile,v 1.12 2004/01/03 18:49:34 reed Exp $
#

DISTNAME=	boolean
PKGNAME=	boolean-${REL}
PKGREVISION=	2
CATEGORIES=	cad graphics
MASTER_SITES=	http://www.xs4all.nl/~kholwerd/download/boolzip/
EXTRACT_SUFX=	.zip

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://www.xs4all.nl/~kholwerd/bool.html
COMMENT=	GDSII viewer/editor + (boolean) operations on sets of 2d polygons

DIST_SUBDIR=	${PKGNAME_NOREV}
REL=		6.4

BUILD_DEPENDS+=	cmake>=1.6.6:../../devel/cmake

USE_BUILDLINK2=	YES
USE_GMAKE=	YES

# the zip archive messes up the case of these files which breaks
# cmake.
post-patch:
	for f in `${FIND} ${WRKSRC} -name cmakelists.txt -print`; do \
		d=`${DIRNAME} $$f` ; \
		n="$$d/CMakeLists.txt" ; \
		${ECHO} "$$f -> $$n" ; \
		${MV} $$f $$n ; done
	${MV} -f ${WRKSRC}/bin/boolean ${WRKSRC}/bin/boolean.bak
	${SED} 's;@prefix@;${PREFIX};g' ${WRKSRC}/bin/boolean.bak > \
		${WRKSRC}/bin/boolean

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${LOCALBASE}/bin/cmake

do-install:
	${INSTALL_DATA_DIR}  ${PREFIX}/share/boolean
	cd ${WRKSRC}/apps/edit && \
		tar cf - default gdsuser | tar -xvf - -C ${PREFIX}/share/boolean
	cd ${WRKSRC}/docs && \
		tar cf - html | tar -xvf - -C ${PREFIX}/share/boolean
	${CHOWN} -R ${BINOWN}.${BINGRP} ${PREFIX}/share/boolean
	${INSTALL_SCRIPT} ${WRKSRC}/bin/boolean  ${PREFIX}/bin/boolean
	${INSTALL_PROGRAM} ${WRKSRC}/apps/edit/edit  ${PREFIX}/bin/edit

.include "../../x11/wxGTK/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
