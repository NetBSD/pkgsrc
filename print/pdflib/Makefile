# $NetBSD: Makefile,v 1.11 2001/07/29 05:38:40 jlam Exp $

DISTNAME=		pdflib-4.0.1
CATEGORIES=		print
MASTER_SITES=		http://www.pdflib.com/pdflib/download/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.pdflib.com/pdflib/index.html
COMMENT=		C library to produce PDF files

USE_BUILDLINK_ONLY=	yes
REPLACE_BUILDLINK=	pdflib-config

USE_GMAKE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--with-tifflib
CONFIGURE_ARGS+=	--with-zlib
CONFIGURE_ARGS+=	--with-pnglib
CPPFLAGS+=		-Dunix

USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/config/ltconfig

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

.include "../../graphics/png/buildlink.mk"
.include "../../graphics/tiff/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
