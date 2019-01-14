# $NetBSD: Makefile,v 1.4 2019/01/14 13:06:11 taca Exp $

MODNAME=		stats
PECL_VERSION=	2.0.3
CATEGORIES+=	math
COMMENT=		PHP extension for statistical computation

PHP_VERSIONS_ACCEPTED=	71 72

CONFIGURE_ARGS+=	--enable-${MODNAME}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
