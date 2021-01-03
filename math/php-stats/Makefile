# $NetBSD: Makefile,v 1.7 2021/01/03 06:47:07 taca Exp $

MODNAME=	stats
PECL_VERSION=	2.0.3
CATEGORIES+=	math
COMMENT=	PHP extension for statistical computation

PHP_VERSIONS_INCOMPATIBLE=	56

CONFIGURE_ARGS+=	--enable-${MODNAME}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
