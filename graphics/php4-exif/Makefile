# $NetBSD: Makefile,v 1.2 2004/04/25 00:28:21 xtraeme Exp $

MODNAME=		exif
CATEGORIES+=		graphics
PKGREVISION=		# empty
COMMENT=		PHP4 extension to extract information from EXIF headers

USE_BUILDLINK3=		YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--with-${MODNAME}=shared

.include "../../mk/bsd.pkg.mk"
