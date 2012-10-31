# $NetBSD: Makefile,v 1.8 2012/10/31 11:19:24 asau Exp $

MODNAME=		pcntl
CATEGORIES+=		devel
COMMENT=		PHP extension for Process Control functions

CONFLICTS=	php-pcntl-[0-9]*

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
