# $NetBSD: Makefile,v 1.4 2004/01/03 18:49:52 reed Exp $

MODNAME=		pdf
CATEGORIES+=		print
PKGREVISION=		3
COMMENT=		PHP3 extension for PDFlib on-the-fly PDF generation

USE_BUILDLINK2=		yes

.include "../../www/php3/Makefile.module"

PKGNAME=		php-pdflib-${BASE_VERS}

CONFIGURE_ARGS+=	--with-pdflib=${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-jpeg-dir=${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-tiff-dir==${BUILDLINK_DIR}
LIBS+=			-lpng -lz

MOD_LIBS+=		-lpdf -lm -ltiff -ljpeg -lpng -lz

.include "../../print/pdflib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
