# $NetBSD: Makefile,v 1.23 2024/02/28 16:22:25 taca Exp $

MODNAME=	mongodb
PECL_VERSION=	1.17.2
CATEGORIES+=	databases

MAINTAINER=	bartosz.kuzma@gmail.com
HOMEPAGE=	http://docs.mongodb.org/ecosystem/drivers/php/
COMMENT=	MongoDB database driver
LICENSE=	apache-2.0

PHP_VERSIONS_SUPPORTED=	74 80 81 82

USE_TOOLS+=		pkg-config gmake
# To use system mongodb library, we require libmongocrypt package.
# So, currently bundled libraries.
CONFIGURE_ARGS+=	--with-mongodb-system-libs=no
CONFIGURE_ARGS+=	--with-openssl-dir=${BUILDLINK_PREFIX.openssl}
CPPFLAGS.NetBSD+=	-D_POSIX_C_SOURCE=200809L -D_NETBSD_SOURCE

.include "../../security/openssl/buildlink3.mk"
#.include "../../databases/mongo-c-driver/buildlink3.mk"
.include "../../devel/snappy/buildlink3.mk"
.include "../../lang/php/json.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
