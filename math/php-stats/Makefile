# $NetBSD: Makefile,v 1.5 2019/11/02 16:16:21 rillig Exp $

MODNAME=	stats
PECL_VERSION=	2.0.3
CATEGORIES+=	math
COMMENT=	PHP extension for statistical computation

PHP_VERSIONS_ACCEPTED=	71 72

CONFIGURE_ARGS+=	--enable-${MODNAME}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
