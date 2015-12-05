# $NetBSD: Makefile,v 1.6 2015/12/05 06:07:32 taca Exp $

MODNAME=		opcache
CATEGORIES+=		devel
COMMENT=		PHP extension for opcode caching

PHP_ZEND_EXTENSION=	yes
CONFIGURE_ARGS+=	--enable-${MODNAME}=opcache
USE_PHP_EXT_PATCHES=	Yes

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
