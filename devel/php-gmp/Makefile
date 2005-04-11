# $NetBSD: Makefile,v 1.4 2005/04/11 21:45:36 tv Exp $

MODNAME=		gmp
CATEGORIES+=		devel math
PKGREVISION=		# empty
COMMENT=		PHP extension for arbitrary precision math


CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.gmp}

.include "../../lang/php/ext.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
