# $NetBSD: Makefile,v 1.10 2010/03/03 07:32:26 taca Exp $

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
