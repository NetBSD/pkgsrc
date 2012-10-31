# $NetBSD: Makefile,v 1.13 2012/10/31 11:19:23 asau Exp $

MODNAME=		gmp
CATEGORIES+=		devel math
COMMENT=		PHP extension for arbitrary precision math

USE_PHP_EXT_PATCHES=	yes

CONFLICTS=	php-gmp-[0-9]*

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.gmp}

.include "../../lang/php/ext.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
