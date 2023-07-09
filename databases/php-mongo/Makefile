# $NetBSD: Makefile,v 1.7 2023/07/09 13:49:01 nia Exp $

MODNAME=		mongo
PECL_VERSION=		1.6.14
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
