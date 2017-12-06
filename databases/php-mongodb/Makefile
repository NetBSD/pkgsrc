# $NetBSD: Makefile,v 1.2 2017/12/06 21:18:00 jdolecek Exp $

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

DEPENDS+=		${PHP_PKG_PREFIX}-json>=5.3.0:../../textproc/php-json

.include "../../security/openssl/buildlink3.mk"
.include "../../databases/mongo-c-driver/buildlink3.mk"
.include "../../devel/libbson/buildlink3.mk"
.include "../../devel/snappy/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
