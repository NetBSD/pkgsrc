# $NetBSD: Makefile,v 1.12 2001/10/01 20:51:45 jlam Exp $

.include "Makefile.common"

PKGNAME=		pdflib-${PDFLIB_VERS}
PDFLIB_PKG_VERS=	# empty
COMMENT=		C library to produce PDF files

USE_BUILDLINK_ONLY=	YES
REPLACE_BUILDLINK+=	pdflib-config

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
