# $NetBSD: Makefile,v 1.5 2025/02/08 03:44:47 taca Exp $

MODNAME=		mailparse
PECL_VERSION=		3.1.3
PKGREVISION=		1
CATEGORIES+=		mail
COMMENT=		PHP extension for email message manipulation
LICENSE=		php

PHP_VERSIONS_INCOMPATIBLE=	56

.include "../../lang/php/ext.mk"
.include "../../converters/php-mbstring/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
