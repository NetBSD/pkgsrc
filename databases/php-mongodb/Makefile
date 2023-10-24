# $NetBSD: Makefile,v 1.20 2023/10/24 22:08:32 wiz Exp $

MODNAME=	mongodb
PECL_VERSION=	1.9.1
CATEGORIES+=	databases

MAINTAINER=	bartosz.kuzma@gmail.com
HOMEPAGE=	http://docs.mongodb.org/ecosystem/drivers/php/
COMMENT=	MongoDB database driver
PKGREVISION=	5
LICENSE=	apache-2.0

# newer versions support 8.1+
PHP_VERSIONS_INCOMPATIBLE=	56 81 82

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
