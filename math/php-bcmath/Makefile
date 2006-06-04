# $NetBSD: Makefile,v 1.6 2006/06/04 16:26:54 joerg Exp $

MODNAME=		bcmath
CATEGORIES+=		math
COMMENT=		PHP extension for bc-style arbitrary precision math

CONFLICTS=	php-bcmath-[0-9]*

CONFIGURE_ARGS+=	--enable-${MODNAME}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
