# $NetBSD: Makefile,v 1.13 2004/11/05 21:44:44 jdolecek Exp $

MODNAME=		pdf
PKGNAME=		php-pdflib-${PHP_BASE_VERS}
CATEGORIES+=		print
PKGREVISION=		# empty
COMMENT=		PHP4 extension for PDFlib on-the-fly PDF generation

USE_BUILDLINK3=		YES

CONFIGURE_ARGS+=	--with-pdflib=shared,${BUILDLINK_PREFIX.pdflib}
CONFIGURE_ARGS+=	--with-jpeg-dir=shared,${BUILDLINK_PREFIX.jpeg}
CONFIGURE_ARGS+=	--with-png-dir=shared,${BUILDLINK_PREFIX.png}
CONFIGURE_ARGS+=	--with-tiff-dir=shared,${BUILDLINK_PREFIX.tiff}
CONFIGURE_ENV+=		PHP_ZLIB_DIR=${BUILDLINK_PREFIX.zlib}

PHP_VERSION_REQD=	4
.include "../../lang/php/ext.mk"
.include "../../print/pdflib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
