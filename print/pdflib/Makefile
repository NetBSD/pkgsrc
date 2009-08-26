# $NetBSD: Makefile,v 1.26 2009/08/26 20:22:53 sno Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "Makefile.common"

PKGNAME=		pdflib-${PDFLIB_BASE_VERS}
PKGREVISION=		8
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
