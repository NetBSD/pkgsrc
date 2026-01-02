# $NetBSD: Makefile,v 1.10 2026/01/02 06:16:02 taca Exp $

MODNAME=		pcntl
PKGREVISION=		1
CATEGORIES+=		devel
COMMENT=		PHP extension for Process Control functions

CONFLICTS=	php-pcntl-[0-9]*

USE_PHP_EXT_PATCHES=	yes
CONFIGURE_ARGS+=	--enable-${MODNAME}=shared

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
