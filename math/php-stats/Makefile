# $NetBSD: Makefile,v 1.10 2025/02/08 03:46:08 taca Exp $

MODNAME=	stats
PECL_VERSION=	2.0.3
PKGREVISION=	1
CATEGORIES+=	math
COMMENT=	PHP extension for statistical computation

PHP_VERSIONS_ACCEPTED=	74

CONFIGURE_ARGS+=	--enable-${MODNAME}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
