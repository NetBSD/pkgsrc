# $NetBSD: Makefile,v 1.13 2001/10/03 22:36:40 jlam Exp $

.include "Makefile.common"

PKGNAME=		pdflib-${PDFLIB_VERS}
PDFLIB_PKG_VERS=	# empty
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
