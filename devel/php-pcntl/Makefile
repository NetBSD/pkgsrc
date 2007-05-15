# $NetBSD: Makefile,v 1.5.8.1 2007/05/15 23:44:30 salo Exp $

MODNAME=		pcntl
CATEGORIES+=		devel
COMMENT=		PHP extension for Process Control functions

CONFLICTS=	php-pcntl-[0-9]*

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
