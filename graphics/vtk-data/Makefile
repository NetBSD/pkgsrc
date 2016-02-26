# $NetBSD: Makefile,v 1.7 2016/02/26 14:05:48 jperkin Exp $
#

DISTNAME=	VTKData-4.2
PKGNAME=	vtk-data-4.2
PKGREVISION=	1
COMMENT=	Example data for VTK

WRKSRC=		${WRKDIR}/VTKData-release-4-2
NO_BUILD=	yes

USE_TOOLS+=	pax

EXAMPLES_DIR=	share/vtk

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/${EXAMPLES_DIR}
	cd ${WRKSRC} && ${PAX} -rw -pm -s '|.*/CVS/.*||' . \
		${DESTDIR}${PREFIX}/${EXAMPLES_DIR}

.include "../../graphics/vtk/Makefile.common"

.include "../../mk/bsd.pkg.mk"
