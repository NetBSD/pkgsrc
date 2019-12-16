# $NetBSD: Makefile,v 1.6 2019/12/16 16:30:14 taca Exp $
#

MODNAME=	mcrypt
PECL_VERSION=	1.0.3
PKGNAME=	${PHP_PKG_PREFIX}-pecl-${MODNAME}-${PECL_VERSION}
CATEGORIES=	security

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pecl.php.net/package/mcrypt
COMMENT=	Bindings for the libmcrypt library
LICENSE=	php

PHP_VERSIONS_ACCEPTED=	72 73 74

CONFIGURE_ARGS+=	--with-mcrypt=${PREFIX}

.include "../../security/libmcrypt/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
