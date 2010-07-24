# $NetBSD: Makefile,v 1.2 2010/07/24 22:24:21 tron Exp $

MODNAME=		mbstring
CATEGORIES+=		converters
COMMENT=		PHP extension for multibyte characters support

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=		php-mbstring-[0-9]*

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
