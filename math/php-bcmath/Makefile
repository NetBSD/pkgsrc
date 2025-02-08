# $NetBSD: Makefile,v 1.10 2025/02/08 03:17:43 taca Exp $

MODNAME=		bcmath
PKGREVISION=		1
CATEGORIES+=		math
COMMENT=		PHP extension for bc-style arbitrary precision math

CONFLICTS=	php-bcmath-[0-9]*

CONFIGURE_ARGS+=	--enable-${MODNAME}

USE_PHP_EXT_PATCHES=	yes

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
