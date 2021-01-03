# $NetBSD: Makefile,v 1.30 2021/01/03 07:31:35 taca Exp $

MODNAME=		pdflib
PKGMODNAME=		pdf
PECL_VERSION=		4.1.4
CATEGORIES+=		print
COMMENT=		PHP extension for PDFlib on-the-fly PDF generation
LICENSE=		php

CONFLICTS=	php-pdf-[0-9]*

USE_LANGUAGES=		c c++

CONFIGURE_ARGS+=	--with-pdflib=shared,${BUILDLINK_PREFIX.pdflib-lite}

.include "../../lang/php/ext.mk"
.include "../../print/pdflib-lite/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
