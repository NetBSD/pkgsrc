# $NetBSD: Makefile,v 1.3 2001/12/03 08:31:00 jlam Exp $

.include "../../www/php4/Makefile.module"

MODNAME=		gmp
CATEGORIES+=		devel math
PKGREVISION=		# empty
COMMENT=		PHP4 extension for arbitrary precision math

USE_BUILDLINK_ONLY=	YES
CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_DIR}

.include "../../devel/gmp/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
