# $NetBSD: Makefile,v 1.10 2021/01/03 08:07:51 taca Exp $

MODNAME=	mongodb
PECL_VERSION=	1.9.0
CATEGORIES+=	databases

MAINTAINER=	bartosz.kuzma@gmail.com
HOMEPAGE=	http://docs.mongodb.org/ecosystem/drivers/php/
COMMENT=	MongoDB database driver
LICENSE=	apache-2.0

DEPENDS+=	${PHP_PKG_PREFIX}-json>=5.3.0:../../textproc/php-json

PHP_VERSIONS_INCOMPATIBLE=	56

USE_TOOLS+=		pkg-config
CONFIGURE_ARGS+=	--with-libbson
CONFIGURE_ARGS+=	--with-libmongoc
CONFIGURE_ARGS+=	--with-openssl-dir=${BUILDLINK_PREFIX.openssl}

.include "../../security/openssl/buildlink3.mk"
.include "../../databases/mongo-c-driver/buildlink3.mk"
.include "../../devel/snappy/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
