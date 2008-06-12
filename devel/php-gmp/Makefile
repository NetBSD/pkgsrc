# $NetBSD: Makefile,v 1.9 2008/06/12 02:14:27 joerg Exp $

MODNAME=		gmp
CATEGORIES+=		devel math
COMMENT=		PHP extension for arbitrary precision math

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	php-gmp-[0-9]*

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.gmp}

.include "../../lang/php/ext.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
