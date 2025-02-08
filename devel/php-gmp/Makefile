# $NetBSD: Makefile,v 1.14 2025/02/08 03:15:21 taca Exp $

MODNAME=		gmp
PKGREVISION=		1
CATEGORIES+=		devel math
COMMENT=		PHP extension for arbitrary precision math

USE_PHP_EXT_PATCHES=	yes

CONFLICTS=	php-gmp-[0-9]*

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.gmp}

.include "../../lang/php/ext.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
