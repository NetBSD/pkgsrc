# $NetBSD: Makefile,v 1.8 2006/06/04 16:26:53 joerg Exp $

MODNAME=		posix
CATEGORIES+=		devel
COMMENT=		PHP extension for POSIX-like functions

CONFLICTS=	php-posix-[0-9]*

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
