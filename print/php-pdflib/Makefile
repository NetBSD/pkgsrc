# $NetBSD: Makefile,v 1.6 2006/02/05 23:10:38 joerg Exp $

MODNAME=		pdflib
PKGMODNAME=		pdf
PECL_VERSION=		2.0.3
PKGREVISION=		2
CATEGORIES+=		print
COMMENT=		PHP extension for PDFlib on-the-fly PDF generation


CONFIGURE_ARGS+=	--with-pdflib=shared,${BUILDLINK_PREFIX.pdflib}

.include "../../lang/php/ext.mk"
.include "../../print/pdflib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
