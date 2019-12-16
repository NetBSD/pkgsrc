# $NetBSD: Makefile,v 1.6 2019/12/16 16:30:13 taca Exp $

MODNAME=	stats
PECL_VERSION=	2.0.3
CATEGORIES+=	math
COMMENT=	PHP extension for statistical computation

PHP_VERSIONS_ACCEPTED=	72

CONFIGURE_ARGS+=	--enable-${MODNAME}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
