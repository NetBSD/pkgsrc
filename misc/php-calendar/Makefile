# $NetBSD: Makefile,v 1.8 2006/06/04 16:26:54 joerg Exp $

MODNAME=		calendar
CATEGORIES+=		misc
COMMENT=		PHP extension for calendar conversion support

CONFLICTS=	php-calendar-[0-9]*

CONFIGURE_ARGS+=	--enable-${MODNAME}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
