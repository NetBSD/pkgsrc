# $NetBSD: Makefile,v 1.8 2018/01/14 14:58:40 rillig Exp $
#

DISTNAME=	VTKDocHtml-4.2
PKGNAME=	vtk-docs-4.2
COMMENT=	Documentation for VTK (HTML)

WRKSRC=		${WRKDIR}/html
NO_BUILD=	yes

HTML_DIR=	share/doc/${PKGNAME}

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/${HTML_DIR}
	${FIND} ${WRKSRC} -type f -print | \
	while read f; do \
		${INSTALL_DATA} $$f ${DESTDIR}${PREFIX}/${HTML_DIR}; \
	done

.include "../../graphics/vtk/Makefile.common"

.include "../../mk/bsd.pkg.mk"
