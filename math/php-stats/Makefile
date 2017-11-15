# $NetBSD: Makefile,v 1.3 2017/11/15 09:15:50 jdolecek Exp $

MODNAME=		stats
PECL_VERSION=	2.0.3
CATEGORIES+=	math
COMMENT=		PHP extension for statistical computation

PHP_VERSIONS_ACCEPTED=	70 71 72

CONFIGURE_ARGS+=	--enable-${MODNAME}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
