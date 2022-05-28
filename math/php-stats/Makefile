# $NetBSD: Makefile,v 1.9 2022/05/28 13:33:01 taca Exp $

MODNAME=	stats
PECL_VERSION=	2.0.3
CATEGORIES+=	math
COMMENT=	PHP extension for statistical computation

PHP_VERSIONS_ACCEPTED=	74

CONFIGURE_ARGS+=	--enable-${MODNAME}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
