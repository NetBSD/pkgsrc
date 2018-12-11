# $NetBSD: Makefile,v 1.27 2018/12/11 14:15:14 tm Exp $

MODNAME=		pdflib
PKGMODNAME=		pdf
PECL_VERSION=		4.1.2
PECL_LEGACY_VERSION_SCHEME=	yes
CATEGORIES+=		print
COMMENT=		PHP extension for PDFlib on-the-fly PDF generation

CONFLICTS=	php-pdf-[0-9]*

PHP_VERSIONS_ACCEPTED=	56

CONFIGURE_ARGS+=	--with-pdflib=shared,${BUILDLINK_PREFIX.pdflib-lite}

.include "../../lang/php/ext.mk"
.include "../../print/pdflib-lite/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
