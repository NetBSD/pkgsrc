# $NetBSD: Makefile,v 1.1 2016/08/04 16:03:53 jdolecek Exp $

MODNAME=		mongodb
PECL_VERSION=		1.1.8
CATEGORIES+=		databases

MAINTAINER=		bartosz.kuzma@gmail.com
HOMEPAGE=		http://docs.mongodb.org/ecosystem/drivers/php/
COMMENT=		MongoDB database driver
LICENSE=		apache-2.0

.include "../../security/openssl/buildlink3.mk"
.include "../../databases/libmongo-client/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
