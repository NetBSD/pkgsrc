# $NetBSD: Makefile,v 1.28 2019/09/22 09:46:09 tm Exp $

MODNAME=		pdflib
PKGMODNAME=		pdf
PECL_VERSION=		4.1.3
CATEGORIES+=		print
COMMENT=		PHP extension for PDFlib on-the-fly PDF generation
LICENSE=		php

CONFLICTS=	php-pdf-[0-9]*

PHP_VERSIONS_ACCEPTED=	56
USE_LANGUAGES=         c c++

CONFIGURE_ARGS+=	--with-pdflib=shared,${BUILDLINK_PREFIX.pdflib-lite}

.include "../../lang/php/ext.mk"
.include "../../print/pdflib-lite/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
