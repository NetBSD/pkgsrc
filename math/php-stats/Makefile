# $NetBSD: Makefile,v 1.8 2022/05/22 13:40:42 taca Exp $

MODNAME=	stats
PECL_VERSION=	2.0.3
CATEGORIES+=	math
COMMENT=	PHP extension for statistical computation

PHP_VERSIONS_ACCEPTED=	56 74

CONFIGURE_ARGS+=	--enable-${MODNAME}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
