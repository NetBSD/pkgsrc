# $NetBSD: Makefile,v 1.14 2001/12/03 08:14:20 jlam Exp $

.include "Makefile.common"

PKGNAME=		pdflib-${PDFLIB_BASE_VERS}
COMMENT=		C library to produce PDF files

USE_BUILDLINK_ONLY=	YES

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
