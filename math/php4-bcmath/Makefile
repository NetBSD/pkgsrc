# $NetBSD: Makefile,v 1.1.1.1 2001/10/16 07:00:05 jlam Exp $

.include "../../www/php4/Makefile.module"

MODNAME=		bcmath
CATEGORIES+=		math
PHP_PKG_VERS=		# empty
COMMENT=		PHP4 extension for bc-style arbitrary precision math

USE_BUILDLINK_ONLY=	YES
CONFIGURE_ARGS+=	--enable-${MODNAME}

.include "../../mk/bsd.pkg.mk"
