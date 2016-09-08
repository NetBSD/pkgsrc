# $NetBSD: Makefile,v 1.2 2016/09/08 03:26:09 taca Exp $

MODNAME=		stats
PECL_VERSION=	2.0.3
CATEGORIES+=	math
COMMENT=		PHP extension for statistical computation

PHP_VERSIONS_ACCEPTED=	70 71

CONFIGURE_ARGS+=	--enable-${MODNAME}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
