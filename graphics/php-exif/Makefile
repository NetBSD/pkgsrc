# $NetBSD: Makefile,v 1.1.1.1 2004/10/31 19:30:30 jdolecek Exp $

MODNAME=		exif
CATEGORIES+=		graphics
PKGREVISION=		# empty
COMMENT=		PHP extension to extract information from EXIF headers

USE_BUILDLINK3=		YES

CONFIGURE_ARGS+=	--with-${MODNAME}=shared

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
