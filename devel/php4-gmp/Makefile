# $NetBSD: Makefile,v 1.5 2002/10/09 19:41:23 wiz Exp $

MODNAME=		gmp
CATEGORIES+=		devel math
PKGREVISION=		# empty
COMMENT=		PHP4 extension for arbitrary precision math

USE_BUILDLINK2=		YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.gmp}

.include "../../devel/gmp/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
