# $NetBSD: Makefile,v 1.1.1.1 2002/01/10 13:10:26 jlam Exp $

MODNAME=		pdf
CATEGORIES+=		print
PKGREVISION=		1
COMMENT=		PHP3 extension for PDFlib on-the-fly PDF generation

USE_BUILDLINK_ONLY=	yes

.include "../../www/php3/Makefile.module"

PKGNAME=		php-pdflib-${BASE_VERS}

CONFIGURE_ARGS+=	--with-pdflib=${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-jpeg-dir=${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-tiff-dir==${BUILDLINK_DIR}
LIBS+=			-lpng -lz

MOD_LIBS+=		-lpdf -lm -ltiff -ljpeg -lpng -lz

.include "../../print/pdflib/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
