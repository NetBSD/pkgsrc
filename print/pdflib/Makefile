# $NetBSD: Makefile,v 1.22 2005/02/23 04:09:51 minskim Exp $

.include "Makefile.common"

PKGNAME=		pdflib-${PDFLIB_BASE_VERS}
PKGREVISION=		5
COMMENT=		C library to produce PDF files

PKG_INSTALLATION_TYPES=	overwrite pkgviews

BUILD_TARGET=		pdflib
DOCDIR=			${PREFIX}/share/doc/pdflib

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC}/doc; for file in					\
		PDFlib-license.pdf					\
		PDFlib-manual.pdf					\
		aladdin-license.pdf;					\
	do								\
		${INSTALL_DATA} $${file} ${DOCDIR};			\
	done

.include "../../mk/bsd.pkg.mk"
