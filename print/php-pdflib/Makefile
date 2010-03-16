# $NetBSD: Makefile,v 1.14 2010/03/16 13:53:58 taca Exp $

MODNAME=		pdflib
PKGMODNAME=		pdf
PECL_VERSION=		2.1.7
CATEGORIES+=		print
COMMENT=		PHP extension for PDFlib on-the-fly PDF generation

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	php-pdf-[0-9]*

CONFIGURE_ARGS+=	--with-pdflib=shared,${BUILDLINK_PREFIX.pdflib}

.include "../../lang/php/ext.mk"
.include "../../print/pdflib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
