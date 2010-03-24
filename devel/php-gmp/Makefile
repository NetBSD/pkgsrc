# $NetBSD: Makefile,v 1.11 2010/03/24 19:43:23 asau Exp $

MODNAME=		gmp
PKGREVISION=		1
CATEGORIES+=		devel math
COMMENT=		PHP extension for arbitrary precision math

PKG_DESTDIR_SUPPORT=	user-destdir
USE_PHP_EXT_PATCHES=	yes

CONFLICTS=	php-gmp-[0-9]*

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.gmp}

.include "../../lang/php/ext.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
