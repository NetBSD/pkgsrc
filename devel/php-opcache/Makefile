# $NetBSD: Makefile,v 1.1 2013/07/29 16:43:17 taca Exp $

MODNAME=		opcache
CATEGORIES+=		devel
COMMENT=		PHP extension for opcode caching

PHP_VERSIONS_ACCEPTED=	55
PHP_CHECK_INSTALLED=	Yes
CONFIGURE_ARGS+=	--enable-${MODNAME}=opcache

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
