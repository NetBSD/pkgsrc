# $NetBSD: Makefile,v 1.2 2004/11/25 20:23:40 jdolecek Exp $

MODNAME=		pdflib
PKGMODNAME=		pdf
PECL_VERSION=		2.0.3
CATEGORIES+=		print
PKGREVISION=		# empty
COMMENT=		PHP extension for PDFlib on-the-fly PDF generation

USE_BUILDLINK3=		YES

CONFIGURE_ARGS+=	--with-pdflib=shared,${BUILDLINK_PREFIX.pdflib}

.include "../../lang/php/ext.mk"
.include "../../print/pdflib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
