# $NetBSD: Makefile,v 1.10 2012/10/31 11:19:24 asau Exp $

MODNAME=		posix
CATEGORIES+=		devel
COMMENT=		PHP extension for POSIX-like functions

CONFLICTS=	php-posix-[0-9]*

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
