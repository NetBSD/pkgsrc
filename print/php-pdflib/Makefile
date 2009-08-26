# $NetBSD: Makefile,v 1.11 2009/08/26 19:58:14 sno Exp $

MODNAME=		pdflib
PKGMODNAME=		pdf
PKGREVISION=		1
PECL_VERSION=		2.0.3
CATEGORIES+=		print
COMMENT=		PHP extension for PDFlib on-the-fly PDF generation

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	php-pdf-[0-9]*

CONFIGURE_ARGS+=	--with-pdflib=shared,${BUILDLINK_PREFIX.pdflib}

.include "../../lang/php/ext.mk"
.include "../../print/pdflib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
