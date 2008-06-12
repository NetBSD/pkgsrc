# $NetBSD: Makefile,v 1.7 2008/06/12 02:14:36 joerg Exp $

MODNAME=		bcmath
CATEGORIES+=		math
COMMENT=		PHP extension for bc-style arbitrary precision math

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	php-bcmath-[0-9]*

CONFIGURE_ARGS+=	--enable-${MODNAME}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
