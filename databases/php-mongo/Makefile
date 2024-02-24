# $NetBSD: Makefile,v 1.9 2024/02/24 16:15:00 taca Exp $

MODNAME=		mongo
PECL_VERSION=		1.6.16
CATEGORIES+=		databases

MAINTAINER=		bartosz.kuzma@gmail.com
HOMEPAGE=		https://pecl.php.net/package/mongo
COMMENT=		MongoDB database driver
LICENSE=		apache-2.0

PHP_VERSIONS_ACCEPTED=	56

.include "options.mk"

.include "../../lang/php/ext.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
