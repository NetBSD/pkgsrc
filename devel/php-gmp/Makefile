# $NetBSD: Makefile,v 1.6 2006/02/05 23:08:50 joerg Exp $

MODNAME=		gmp
PKGREVISION=		1
CATEGORIES+=		devel math
COMMENT=		PHP extension for arbitrary precision math


CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.gmp}

.include "../../lang/php/ext.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
