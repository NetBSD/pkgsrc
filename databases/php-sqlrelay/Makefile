# $NetBSD: Makefile,v 1.1 2014/05/22 12:50:47 fhajny Exp $

PKGNAME=		${PHP_PKG_PREFIX}-${DISTNAME}
COMMENT=		PHP extension for SQL Relay
EXTRACT_SUFX=		.tar.gz

.include "../../databases/sqlrelay/Makefile.common"

LICENSE=		gnu-gpl-v2 AND php

CONFIGURE_ARGS+=	--with-php-prefix=${BUILDLINK_PREFIX.php}

BUILD_DIRS=		src/api/php
BUILD_DIRS+=		src/api/phppdo

.include "../../databases/php-pdo/buildlink3.mk"
.include "../../databases/sqlrelay/buildlink3.mk"
.include "../../lang/php/phpversion.mk"
.include "${PHPPKGSRCDIR}/Makefile.common"
.include "${PHPPKGSRCDIR}/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
