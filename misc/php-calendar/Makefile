# $NetBSD: Makefile,v 1.9 2008/06/12 02:14:37 joerg Exp $

MODNAME=		calendar
CATEGORIES+=		misc
COMMENT=		PHP extension for calendar conversion support

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	php-calendar-[0-9]*

CONFIGURE_ARGS+=	--enable-${MODNAME}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
