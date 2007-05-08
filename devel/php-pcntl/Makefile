# $NetBSD: Makefile,v 1.6 2007/05/08 11:30:50 adrianp Exp $

MODNAME=		pcntl
CATEGORIES+=		devel
COMMENT=		PHP extension for Process Control functions

CONFLICTS=	php-pcntl-[0-9]*

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
