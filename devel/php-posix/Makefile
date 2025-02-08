# $NetBSD: Makefile,v 1.11 2025/02/08 03:15:21 taca Exp $

MODNAME=		posix
PKGREVISION=		1
CATEGORIES+=		devel
COMMENT=		PHP extension for POSIX-like functions

CONFLICTS=	php-posix-[0-9]*

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
