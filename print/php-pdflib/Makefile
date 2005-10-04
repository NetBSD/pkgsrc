# $NetBSD: Makefile,v 1.4 2005/10/04 16:50:50 tv Exp $

MODNAME=		pdflib
PKGMODNAME=		pdf
PECL_VERSION=		2.0.3
PKGREVISION=		1
CATEGORIES+=		print
PKGREVISION=		# empty
COMMENT=		PHP extension for PDFlib on-the-fly PDF generation


CONFIGURE_ARGS+=	--with-pdflib=shared,${BUILDLINK_PREFIX.pdflib}

.include "../../lang/php/ext.mk"
.include "../../print/pdflib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
