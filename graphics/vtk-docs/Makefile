# $NetBSD: Makefile,v 1.6 2008/03/04 15:39:11 jlam Exp $
#

DISTNAME=	VTKDocHtml-4.2
PKGNAME=	vtk-docs-4.2
COMMENT=	Documentation for VTK (HTML)

PKG_DESTDIR_SUPPORT=	user-destdir

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
