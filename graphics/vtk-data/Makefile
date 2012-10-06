# $NetBSD: Makefile,v 1.6 2012/10/06 14:11:24 asau Exp $
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
	cd ${WRKSRC} && pax -rw -pe -s '|.*/CVS/.*||' . \
		${DESTDIR}${PREFIX}/${EXAMPLES_DIR}

.include "../../graphics/vtk/Makefile.common"

.include "../../mk/bsd.pkg.mk"
