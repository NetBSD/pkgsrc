# $NetBSD: Makefile,v 1.2 2002/03/13 17:37:38 fredb Exp $

MODNAME=		pdf
CATEGORIES+=		print
PKGREVISION=		2
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
