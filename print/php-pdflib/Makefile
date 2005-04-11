# $NetBSD: Makefile,v 1.3 2005/04/11 21:47:08 tv Exp $

MODNAME=		pdflib
PKGMODNAME=		pdf
PECL_VERSION=		2.0.3
CATEGORIES+=		print
PKGREVISION=		# empty
COMMENT=		PHP extension for PDFlib on-the-fly PDF generation


CONFIGURE_ARGS+=	--with-pdflib=shared,${BUILDLINK_PREFIX.pdflib}

.include "../../lang/php/ext.mk"
.include "../../print/pdflib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
