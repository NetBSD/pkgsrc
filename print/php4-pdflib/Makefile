# $NetBSD: Makefile,v 1.6 2002/03/13 17:37:38 fredb Exp $

MODNAME=		pdf
PKGNAME=		php-pdflib-${PHP_BASE_VERS}
PKGREVISION=		1
CATEGORIES+=		print
PKGREVISION=		# empty
COMMENT=		PHP4 extension for PDFlib on-the-fly PDF generation

USE_BUILDLINK_ONLY=	YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--with-pdflib=shared,${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-jpeg-dir=shared,${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-png-dir=shared,${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-tiff-dir=shared,${BUILDLINK_DIR}
CONFIGURE_ENV+=		PHP_ZLIB_DIR=${BUILDLINK_DIR}

.include "../../print/pdflib/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
