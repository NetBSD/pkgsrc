# $NetBSD: Makefile,v 1.5 2008/05/26 02:13:20 joerg Exp $
#

DISTNAME=	VTKData-4.2
PKGNAME=	vtk-data-4.2
PKGREVISION=	1
COMMENT=	Example data for VTK

PKG_DESTDIR_SUPPORT=	user-destdir

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
