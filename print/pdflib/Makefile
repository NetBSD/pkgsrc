# $NetBSD: Makefile,v 1.18 2004/01/03 18:49:52 reed Exp $

.include "Makefile.common"

PKGNAME=		pdflib-${PDFLIB_BASE_VERS}
PKGREVISION=		2
COMMENT=		C library to produce PDF files

ALL_TARGET=		pdflib
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
