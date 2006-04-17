# $NetBSD: Makefile,v 1.7 2006/04/17 13:46:46 wiz Exp $

MODNAME=		pdflib
PKGMODNAME=		pdf
PECL_VERSION=		2.0.3
PKGREVISION=		3
CATEGORIES+=		print
COMMENT=		PHP extension for PDFlib on-the-fly PDF generation


CONFIGURE_ARGS+=	--with-pdflib=shared,${BUILDLINK_PREFIX.pdflib}

.include "../../lang/php/ext.mk"
.include "../../print/pdflib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
