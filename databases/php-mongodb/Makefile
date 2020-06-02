# $NetBSD: Makefile,v 1.8 2020/06/02 08:23:26 adam Exp $

MODNAME=	mongodb
PECL_VERSION=	1.5.3
CATEGORIES+=	databases

MAINTAINER=	bartosz.kuzma@gmail.com
HOMEPAGE=	http://docs.mongodb.org/ecosystem/drivers/php/
COMMENT=	MongoDB database driver
PKGREVISION=	4
LICENSE=	apache-2.0

DEPENDS+=	${PHP_PKG_PREFIX}-json>=5.3.0:../../textproc/php-json

USE_TOOLS+=		pkg-config
CONFIGURE_ARGS+=	--with-libbson
CONFIGURE_ARGS+=	--with-libmongoc
CONFIGURE_ARGS+=	--with-openssl-dir=${BUILDLINK_PREFIX.openssl}

.include "../../security/openssl/buildlink3.mk"
.include "../../databases/mongo-c-driver/buildlink3.mk"
.include "../../devel/snappy/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
