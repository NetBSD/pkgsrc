# $NetBSD: Makefile,v 1.9 2008/06/12 02:14:27 joerg Exp $

MODNAME=		posix
CATEGORIES+=		devel
COMMENT=		PHP extension for POSIX-like functions

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	php-posix-[0-9]*

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
