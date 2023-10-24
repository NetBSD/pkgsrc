# $NetBSD: Makefile,v 1.8 2023/10/24 22:08:32 wiz Exp $

MODNAME=		mongo
PECL_VERSION=		1.6.14
CATEGORIES+=		databases

MAINTAINER=		bartosz.kuzma@gmail.com
HOMEPAGE=		https://pecl.php.net/package/mongo
COMMENT=		MongoDB database driver
PKGREVISION=		1
LICENSE=		apache-2.0

PHP_VERSIONS_ACCEPTED=	56

.include "options.mk"

.include "../../lang/php/ext.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
