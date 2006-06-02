# $NetBSD: Makefile,v 1.5 2006/06/02 18:27:56 joerg Exp $

MODNAME=		bcmath
CATEGORIES+=		math
COMMENT=		PHP extension for bc-style arbitrary precision math

CONFLICTS=	php-bcmath-[0-9]

CONFIGURE_ARGS+=	--enable-${MODNAME}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
