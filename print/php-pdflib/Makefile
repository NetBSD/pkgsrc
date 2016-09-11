# $NetBSD: Makefile,v 1.26 2016/09/11 17:03:27 taca Exp $

MODNAME=		pdflib
PKGMODNAME=		pdf
PECL_VERSION=		2.1.10
PECL_LEGACY_VERSION_SCHEME=	yes
CATEGORIES+=		print
COMMENT=		PHP extension for PDFlib on-the-fly PDF generation

CONFLICTS=	php-pdf-[0-9]*

PHP_VERSIONS_ACCEPTED=	56

CONFIGURE_ARGS+=	--with-pdflib=shared,${BUILDLINK_PREFIX.pdflib}

.include "../../lang/php/ext.mk"
.include "../../print/pdflib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
