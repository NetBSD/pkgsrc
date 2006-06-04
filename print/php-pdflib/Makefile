# $NetBSD: Makefile,v 1.9 2006/06/04 16:26:55 joerg Exp $

MODNAME=		pdflib
PKGMODNAME=		pdf
PECL_VERSION=		2.0.3
CATEGORIES+=		print
COMMENT=		PHP extension for PDFlib on-the-fly PDF generation

CONFLICTS=	php-pdf-[0-9]*

CONFIGURE_ARGS+=	--with-pdflib=shared,${BUILDLINK_PREFIX.pdflib}

.include "../../lang/php/ext.mk"
.include "../../print/pdflib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
