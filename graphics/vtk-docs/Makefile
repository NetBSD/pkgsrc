# $NetBSD: Makefile,v 1.4 2006/01/29 03:32:17 rillig Exp $
#

DISTNAME=	VTKDocHtml-4.2
PKGNAME=	vtk-docs-4.2
COMMENT=	Documentation for VTK (HTML)

WRKSRC=		${WRKDIR}/html
NO_BUILD=	yes

HTML_DIR=	share/doc/${PKGNAME}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX:Q}/${HTML_DIR:Q}
	${FIND} ${WRKSRC:Q} -type f -exec ${INSTALL_DATA} {} ${PREFIX:Q}/${HTML_DIR:Q} \;

.include "../../graphics/vtk/Makefile.common"

.include "../../mk/bsd.pkg.mk"
