# $NetBSD: Makefile,v 1.3 2005/12/30 23:47:48 joerg Exp $
#

DISTNAME=	VTKDocHtml-4.2
PKGNAME=	vtk-docs-4.2
COMMENT=	Documentation for VTK (HTML)

WRKSRC=		${WRKDIR}/html
NO_BUILD=	yes

HTML_DIR=	share/doc/${PKGNAME}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${HTML_DIR}
	${FIND} ${WRKSRC} -type f -exec ${INSTALL_DATA} {} ${PREFIX}/${HTML_DIR} \;

.include "../../graphics/vtk/Makefile.common"

.include "../../mk/bsd.pkg.mk"
