# $NetBSD: Makefile,v 1.22 2013/01/26 21:38:43 adam Exp $

MODNAME=		pdflib
PKGMODNAME=		pdf
PECL_VERSION=		2.1.8
PKGREVISION=		3
PECL_LEGACY_VERSION_SCHEME=	yes
CATEGORIES+=		print
COMMENT=		PHP extension for PDFlib on-the-fly PDF generation

CONFLICTS=	php-pdf-[0-9]*

CONFIGURE_ARGS+=	--with-pdflib=shared,${BUILDLINK_PREFIX.pdflib}

.include "../../lang/php/ext.mk"
.include "../../print/pdflib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
