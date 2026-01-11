# $NetBSD: Makefile,v 1.52 2026/01/11 07:52:14 wiz Exp $

PKGNAME=	${PHP_PKG_PREFIX}-${DISTNAME}
PKGREVISION=	13
COMMENT=	PHP extension for SQL Relay
EXTRACT_SUFX=	.tar.gz

PHP_VERSIONS_INCOMPATIBLE=	85

.include "../../databases/sqlrelay/Makefile.common"

LICENSE=	gnu-gpl-v2 AND php

TOOLS_BROKEN+=		perl
MAKE_FLAGS+=		PHPCONFSTYLE="bogus"  # do not install .ini

BUILD_DIRS=		src/api/php
BUILD_DIRS+=		src/api/phppdo

.include "../../lang/php/phpversion.mk"

CONFIGURE_ARGS+=	--with-php-prefix=${BUILDLINK_PREFIX.php${PHP_VER}}
CONFIGURE_ENV+=		PHP_VER=${PHP_VER}

.include "../../databases/php-pdo/buildlink3.mk"
.include "../../databases/sqlrelay/buildlink3.mk"
.include "${PHPPKGSRCDIR}/Makefile.common"
.include "${PHPPKGSRCDIR}/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
