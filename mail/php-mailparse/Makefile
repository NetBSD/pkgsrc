# $NetBSD: Makefile,v 1.7 2025/10/22 16:25:34 taca Exp $

MODNAME=		mailparse
PECL_VERSION=		3.1.9
CATEGORIES+=		mail
COMMENT=		PHP extension for email message manipulation
LICENSE=		php

PHP_VERSIONS_INCOMPATIBLE=	56

.include "../../lang/php/ext.mk"
.include "../../converters/php-mbstring/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
