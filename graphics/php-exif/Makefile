# $NetBSD: Makefile,v 1.2 2004/10/31 21:07:14 jdolecek Exp $

MODNAME=		exif
CATEGORIES+=		graphics
PKGREVISION=		# empty
COMMENT=		PHP extension to extract information from EXIF headers

USE_BUILDLINK3=		YES

.include "../../lang/php/ext.mk"

CONFIGURE_ARGS+=	--with-${MODNAME}=shared

.include "../../mk/bsd.pkg.mk"
