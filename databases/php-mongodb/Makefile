# $NetBSD: Makefile,v 1.3 2018/01/07 20:56:44 joerg Exp $

MODNAME=		mongodb
PECL_VERSION=		1.3.4
CATEGORIES+=		databases

MAINTAINER=		bartosz.kuzma@gmail.com
HOMEPAGE=		http://docs.mongodb.org/ecosystem/drivers/php/
COMMENT=		MongoDB database driver
LICENSE=		apache-2.0

CONFIGURE_ARGS+=	--with-libbson
CONFIGURE_ARGS+=	--with-libmongoc
CONFIGURE_ARGS+=	--with-openssl-dir=${BUILDLINK_PREFIX.openssl}
USE_TOOLS+=		pkg-config

DEPENDS+=		${PHP_PKG_PREFIX}-json>=5.3.0:../../textproc/php-json

.include "../../security/openssl/buildlink3.mk"
.include "../../databases/mongo-c-driver/buildlink3.mk"
.include "../../devel/libbson/buildlink3.mk"
.include "../../devel/snappy/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
