# $NetBSD: Makefile,v 1.11.4.1 2010/07/25 11:56:16 spz Exp $

MODNAME=		gmp
CATEGORIES+=		devel math
COMMENT=		PHP extension for arbitrary precision math

PKG_DESTDIR_SUPPORT=	user-destdir
USE_PHP_EXT_PATCHES=	yes

CONFLICTS=	php-gmp-[0-9]*

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.gmp}

.include "../../lang/php/ext.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
