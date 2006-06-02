# $NetBSD: Makefile,v 1.7 2006/06/02 18:27:55 joerg Exp $

MODNAME=		posix
CATEGORIES+=		devel
COMMENT=		PHP extension for POSIX-like functions

CONFLICTS=	php-posix-[0-9]

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
