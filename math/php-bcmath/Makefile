# $NetBSD: Makefile,v 1.8 2009/07/10 20:00:00 jdolecek Exp $

MODNAME=		bcmath
CATEGORIES+=		math
COMMENT=		PHP extension for bc-style arbitrary precision math

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	php-bcmath-[0-9]*

CONFIGURE_ARGS+=	--enable-${MODNAME}

USE_PHP_EXT_PATCHES=	yes

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
