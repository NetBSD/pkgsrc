# $NetBSD: Makefile,v 1.16 2022/04/18 19:10:38 adam Exp $

MODNAME=	mongodb
PECL_VERSION=	1.9.1
CATEGORIES+=	databases

MAINTAINER=	bartosz.kuzma@gmail.com
HOMEPAGE=	http://docs.mongodb.org/ecosystem/drivers/php/
COMMENT=	MongoDB database driver
PKGREVISION=	2
LICENSE=	apache-2.0

PHP_VERSIONS_INCOMPATIBLE=	56

USE_TOOLS+=		pkg-config gmake
CONFIGURE_ARGS+=	--with-libbson
CONFIGURE_ARGS+=	--with-libmongoc
CONFIGURE_ARGS+=	--with-openssl-dir=${BUILDLINK_PREFIX.openssl}

.include "../../security/openssl/buildlink3.mk"
.include "../../databases/mongo-c-driver/buildlink3.mk"
.include "../../devel/snappy/buildlink3.mk"
.include "../../lang/php/json.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
