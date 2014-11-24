# $NetBSD: Makefile,v 1.3 2014/11/24 15:40:57 taca Exp $

MODNAME=		opcache
CATEGORIES+=		devel
COMMENT=		PHP extension for opcode caching

PHP_VERSIONS_ACCEPTED=	55 56
CONFIGURE_ARGS+=	--enable-${MODNAME}=opcache
USE_PHP_EXT_PATCHES=	Yes

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
