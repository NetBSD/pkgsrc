# $NetBSD: Makefile,v 1.1.1.1 2004/08/02 13:17:27 drochner Exp $
#

DISTNAME=	VTKDocHtml-4.2
PKGNAME=	vtk-docs-4.2
COMMENT=	Documentation for VTK (HTML)

WRKSRC=		${WRKDIR}/html
NO_BUILD=	# defined

HTML_DIR=	share/doc/${PKGNAME}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${HTML_DIR}
	cd ${WRKSRC} && ${PAX} -rw -pe * ${PREFIX}/${HTML_DIR}

.include "../../graphics/vtk/Makefile.common"

.include "../../mk/bsd.pkg.mk"
