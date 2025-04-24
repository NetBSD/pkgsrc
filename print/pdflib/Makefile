# $NetBSD: Makefile,v 1.51 2025/04/24 14:15:35 wiz Exp $

.include "Makefile.common"

PKGNAME=		pdflib-${PDFLIB_BASE_VERS}
PKGREVISION=		29
COMMENT=		C library to produce PDF files

BUILD_TARGET=		pdflib
DOCDIR=			${PREFIX}/share/doc/pdflib

INSTALLATION_DIRS+=	${DOCDIR}

post-install:
	cd ${WRKSRC}/doc; for file in					\
		PDFlib-license.pdf					\
		PDFlib-manual.pdf					\
		aladdin-license.pdf;					\
	do								\
		${INSTALL_DATA} $${file} ${DESTDIR}${DOCDIR};		\
	done

.include "../../mk/bsd.pkg.mk"
