# $NetBSD: Makefile,v 1.8 2006/06/04 16:26:53 joerg Exp $

MODNAME=		gmp
CATEGORIES+=		devel math
COMMENT=		PHP extension for arbitrary precision math

CONFLICTS=	php-gmp-[0-9]*

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.gmp}

.include "../../lang/php/ext.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
