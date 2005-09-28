# $NetBSD: Makefile,v 1.2 2005/09/28 20:52:23 rillig Exp $
#

DISTNAME=	VTKData-4.2
PKGNAME=	vtk-data-4.2
COMMENT=	Example data for VTK

WRKSRC=		${WRKDIR}/VTKData-release-4-2
NO_BUILD=	yes

EXAMPLES_DIR=	share/vtk

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${EXAMPLES_DIR}
	cd ${WRKSRC} && ${PAX} -rw -pe * ${PREFIX}/${EXAMPLES_DIR}

.include "../../graphics/vtk/Makefile.common"

.include "../../mk/bsd.pkg.mk"
