# $NetBSD: Makefile,v 1.3 2002/02/28 06:18:08 jlam Exp $

MODNAME=		bcmath
CATEGORIES+=		math
PKGREVISION=		# empty
COMMENT=		PHP4 extension for bc-style arbitrary precision math

USE_BUILDLINK_ONLY=	YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--enable-${MODNAME}

.include "../../mk/bsd.pkg.mk"
