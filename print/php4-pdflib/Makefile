# $NetBSD: Makefile,v 1.5 2002/02/28 06:18:38 jlam Exp $

MODNAME=		pdf
PKGNAME=		php-pdflib-${PHP_BASE_VERS}
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
