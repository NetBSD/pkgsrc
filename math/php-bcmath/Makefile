# $NetBSD: Makefile,v 1.11 2026/10/09 10:53:00 jperkin Exp $

MODNAME=		bcmath
PKGREVISION=		1
CATEGORIES+=		math
COMMENT=		PHP extension for bc-style arbitrary precision math

CONFLICTS=	php-bcmath-[0-9]*

FORCE_C_STD=	c99

CONFIGURE_ARGS+=	--enable-${MODNAME}

USE_PHP_EXT_PATCHES=	yes

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
