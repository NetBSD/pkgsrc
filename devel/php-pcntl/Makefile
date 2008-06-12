# $NetBSD: Makefile,v 1.7 2008/06/12 02:14:27 joerg Exp $

MODNAME=		pcntl
CATEGORIES+=		devel
COMMENT=		PHP extension for Process Control functions

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	php-pcntl-[0-9]*

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
