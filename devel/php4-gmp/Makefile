# $NetBSD: Makefile,v 1.4 2002/02/28 06:17:29 jlam Exp $

MODNAME=		gmp
CATEGORIES+=		devel math
PKGREVISION=		# empty
COMMENT=		PHP4 extension for arbitrary precision math

USE_BUILDLINK_ONLY=	YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../devel/gmp/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
