# $NetBSD: Makefile,v 1.2 2013/10/18 15:50:45 taca Exp $

MODNAME=		opcache
CATEGORIES+=		devel
COMMENT=		PHP extension for opcode caching

PHP_VERSIONS_ACCEPTED=	55
CONFIGURE_ARGS+=	--enable-${MODNAME}=opcache
USE_PHP_EXT_PATCHES=	Yes

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
