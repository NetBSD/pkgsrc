# $NetBSD: Makefile,v 1.7 2012/10/06 14:11:24 asau Exp $
#

DISTNAME=	VTKDocHtml-4.2
PKGNAME=	vtk-docs-4.2
COMMENT=	Documentation for VTK (HTML)

WRKSRC=		${WRKDIR}/html
NO_BUILD=	yes

HTML_DIR=	share/doc/${PKGNAME}

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX:Q}/${HTML_DIR:Q}
	${FIND} ${WRKSRC:Q} -type f -print | \
	while read f; do \
		${INSTALL_DATA} $$f ${DESTDIR}${PREFIX:Q}/${HTML_DIR:Q}; \
	done

.include "../../graphics/vtk/Makefile.common"

.include "../../mk/bsd.pkg.mk"
