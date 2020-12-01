# $NetBSD: Makefile,v 1.2 2020/12/01 12:37:29 nia Exp $

MODNAME=		mailparse
PECL_VERSION=		3.1.0
CATEGORIES+=		mail
COMMENT=		PHP extension for email message manipulation
LICENSE=		php

PHP_VERSIONS_INCOMPATIBLE=	56

.include "../../lang/php/ext.mk"
.include "../../converters/php-mbstring/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
