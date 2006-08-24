# $NetBSD: Makefile,v 1.33 2006/08/24 00:01:27 dmcmahill Exp $
#

DISTNAME=	boolean_6_7
PKGNAME=	boolean-${REL}
PKGREVISION=	3
CATEGORIES=	cad graphics
MASTER_SITES=	http://www.xs4all.nl/~kholwerd/download/boolzip/
EXTRACT_SUFX=	.zip

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.xs4all.nl/~kholwerd/bool.html
COMMENT=	GDSII viewer/editor + (boolean) operations on sets of 2d polygons

DIST_SUBDIR=	${PKGNAME_NOREV}
REL=		6.7

BUILD_DEPENDS+=	cmake>=1.6.6:../../devel/cmake

WRKSRC=		${WRKDIR}/boolean

GCC_REQD+=	3.0

USE_TOOLS+=	gmake pkg-config tar
USE_LANGUAGES=	c c++

INSTALLATION_DIRS=	bin

# the zip archive messes up the case of these files which breaks
# cmake.
post-extract:
	set -e; \
	for f in `${FIND} ${WRKSRC} -name cmakelists.txt -print`; do \
		d=`${DIRNAME} "$$f"` ; \
		n="$$d/CMakeLists.txt" ; \
		${ECHO} "$$f -> $$n" ; \
		${MV} "$$f" "$$n"; done
		${MV} ${WRKSRC}/bin/checkmsvc.cmake ${WRKSRC}/bin/CheckMSVC.cmake
		${MV} ${WRKSRC}/bin/findpkgconfig.cmake ${WRKSRC}/bin/FindPkgConfig.cmake
		${MV} ${WRKSRC}/bin/findwxwin.cmake ${WRKSRC}/bin/FindwxWin.cmake
		${MV} ${WRKSRC}/bin/macros.cmake ${WRKSRC}/bin/Macros.cmake
	${MV} -f ${WRKSRC}/bin/boolean ${WRKSRC}/bin/boolean.bak
	${SED} 's;@prefix@;${PREFIX};g' ${WRKSRC}/bin/boolean.bak > \
		${WRKSRC}/bin/boolean
	${CP} -f ${WRKSRC}/apps/edit/include/valuesvc.h ${WRKSRC}/modules/kbool/include

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${LOCALBASE}/bin/cmake \
		-DWXWIDGET_GTK2=YES .

do-install:
	${INSTALL_DATA_DIR}  ${PREFIX}/share/boolean
	cd ${WRKSRC}/apps/edit						\
	&& ${PAX} -rw default gdsuser ${PREFIX}/share/boolean
	cd ${WRKSRC}/docs						\
	&& ${PAX} -rw html ${PREFIX}/share/boolean
	${CHOWN} -R ${BINOWN}:${BINGRP} ${PREFIX}/share/boolean
	${INSTALL_SCRIPT} ${WRKSRC}/bin/boolean  ${PREFIX}/bin/boolean
	${INSTALL_PROGRAM} ${WRKSRC}/apps/edit/edit  ${PREFIX}/bin/edit

.include "../../x11/wxGTK/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
