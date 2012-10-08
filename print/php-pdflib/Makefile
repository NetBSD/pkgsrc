# $NetBSD: Makefile,v 1.21 2012/10/08 13:45:44 asau Exp $

MODNAME=		pdflib
PKGMODNAME=		pdf
PECL_VERSION=		2.1.8
PKGREVISION=		2
PECL_LEGACY_VERSION_SCHEME=	yes
CATEGORIES+=		print
COMMENT=		PHP extension for PDFlib on-the-fly PDF generation

CONFLICTS=	php-pdf-[0-9]*

CONFIGURE_ARGS+=	--with-pdflib=shared,${BUILDLINK_PREFIX.pdflib}

.include "../../lang/php/ext.mk"
.include "../../print/pdflib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
