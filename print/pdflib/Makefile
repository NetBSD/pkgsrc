# $NetBSD: Makefile,v 1.31 2012/10/03 21:57:20 wiz Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "Makefile.common"

PKGNAME=		pdflib-${PDFLIB_BASE_VERS}
PKGREVISION=		13
COMMENT=		C library to produce PDF files

PKG_INSTALLATION_TYPES=	overwrite pkgviews

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
