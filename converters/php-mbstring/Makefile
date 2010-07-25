# $NetBSD: Makefile,v 1.1.1.1.4.1 2010/07/25 11:56:16 spz Exp $

MODNAME=		mbstring
CATEGORIES+=		converters
COMMENT=		PHP extension for multibyte characters support

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=		php-mbstring-[0-9]*

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
