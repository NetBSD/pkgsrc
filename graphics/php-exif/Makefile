# $NetBSD: Makefile,v 1.7 2008/06/12 02:14:32 joerg Exp $

MODNAME=		exif
PKGREVISION=		1
CATEGORIES+=		graphics
COMMENT=		PHP extension to extract information from EXIF headers

PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ARGS+=	--with-${MODNAME}=shared

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
