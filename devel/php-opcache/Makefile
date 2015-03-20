# $NetBSD: Makefile,v 1.5 2015/03/20 16:33:28 taca Exp $

MODNAME=		opcache
CATEGORIES+=		devel
COMMENT=		PHP extension for opcode caching

PHP_VERSIONS_ACCEPTED=	55 56
PHP_ZEND_EXTENSION=	yes
CONFIGURE_ARGS+=	--enable-${MODNAME}=opcache
USE_PHP_EXT_PATCHES=	Yes

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
