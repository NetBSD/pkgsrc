# $NetBSD: Makefile,v 1.4 2008/03/04 15:39:11 jlam Exp $
#

DISTNAME=	VTKData-4.2
PKGNAME=	vtk-data-4.2
PKGREVISION=	1
COMMENT=	Example data for VTK

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/VTKData-release-4-2
NO_BUILD=	yes

EXAMPLES_DIR=	share/vtk

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/${EXAMPLES_DIR}
	cd ${WRKSRC} && ${PAX} -rw -pe -s '|.*/CVS/.*||' . \
		${DESTDIR}${PREFIX}/${EXAMPLES_DIR}

.include "../../graphics/vtk/Makefile.common"

.include "../../mk/bsd.pkg.mk"
