# $NetBSD: Makefile,v 1.1.1.1 2004/08/02 13:20:02 drochner Exp $
#

DISTNAME=	VTKData-4.2
PKGNAME=	vtk-data-4.2
COMMENT=	Example data for VTK

WRKSRC=		${WRKDIR}/VTKData-release-4-2
NO_BUILD=	# defined

EXAMPLES_DIR=	share/vtk

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${EXAMPLES_DIR}
	cd ${WRKSRC} && ${PAX} -rw -pe * ${PREFIX}/${EXAMPLES_DIR}

.include "../../graphics/vtk/Makefile.common"

.include "../../mk/bsd.pkg.mk"
