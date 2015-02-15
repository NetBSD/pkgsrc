# $NetBSD: Makefile,v 1.4 2015/02/15 09:03:15 taca Exp $

MODNAME=		opcache
PKGREVISION=		1
CATEGORIES+=		devel
COMMENT=		PHP extension for opcode caching

PHP_VERSIONS_ACCEPTED=	55 56
PHP_ZEND_EXTENSION=	yes
CONFIGURE_ARGS+=	--enable-${MODNAME}=opcache
USE_PHP_EXT_PATCHES=	Yes

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
