# $NetBSD: Makefile,v 1.16 2010/06/13 22:45:16 wiz Exp $

MODNAME=		pdflib
PKGMODNAME=		pdf
PKGREVISION=		1
PECL_VERSION=		2.1.8
CATEGORIES+=		print
COMMENT=		PHP extension for PDFlib on-the-fly PDF generation

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	php-pdf-[0-9]*

CONFIGURE_ARGS+=	--with-pdflib=shared,${BUILDLINK_PREFIX.pdflib}

.include "../../lang/php/ext.mk"
.include "../../print/pdflib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
