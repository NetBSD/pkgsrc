# $NetBSD: Makefile,v 1.3 2001/10/16 06:58:33 jlam Exp $

.include "../../www/php4/Makefile.module"

MODNAME=		pdf
PKGNAME=		php-pdflib-${PHP_VERS}
CATEGORIES+=		print
PHP_PKG_VERS=		# empty
COMMENT=		PHP4 extension for PDFlib on-the-fly PDF generation

USE_BUILDLINK_ONLY=	YES
CONFIGURE_ARGS+=	--with-pdflib=shared,${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-jpeg-dir=shared,${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-png-dir=shared,${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-tiff-dir=shared,${BUILDLINK_DIR}
CONFIGURE_ENV+=		PHP_ZLIB_DIR=${BUILDLINK_DIR}

.include "../../print/pdflib/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
