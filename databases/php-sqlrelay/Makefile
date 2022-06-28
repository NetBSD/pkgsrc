# $NetBSD: Makefile,v 1.35 2022/06/28 11:31:32 wiz Exp $

PKGNAME=	${PHP_PKG_PREFIX}-${DISTNAME}
PKGREVISION=	5
COMMENT=	PHP extension for SQL Relay
EXTRACT_SUFX=	.tar.gz

.include "../../databases/sqlrelay/Makefile.common"

LICENSE=	gnu-gpl-v2 AND php

PHP_VERSIONS_ACCEPTED=	56 74

TOOLS_BROKEN+=		perl
CONFIGURE_ARGS+=	--with-php-prefix=${BUILDLINK_PREFIX.php}
MAKE_FLAGS+=		PHPCONFSTYLE="bogus"  # do not install .ini

BUILD_DIRS=		src/api/php
BUILD_DIRS+=		src/api/phppdo

.include "../../databases/php-pdo/buildlink3.mk"
.include "../../databases/sqlrelay/buildlink3.mk"
.include "../../lang/php/phpversion.mk"
.include "${PHPPKGSRCDIR}/Makefile.common"
.include "${PHPPKGSRCDIR}/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
