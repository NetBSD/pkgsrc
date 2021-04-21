# $NetBSD: Makefile,v 1.6 2021/04/21 13:24:20 adam Exp $
#

MODNAME=	zip
PECL_VERSION=	1.19.2
PKGNAME=	${PHP_PKG_PREFIX}-pecl-${MODNAME}-${PECL_VERSION}
PKGREVISION=	1
CATEGORIES=	archivers

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pecl.php.net/package/zip
COMMENT=	Zip management extension with libzip
LICENSE=	php

PHP_VERSIONS_INCOMPATIBLE=	56

CONFIGURE_ARGS+=	--enable-zip
CONFIGURE_ARGS+=	--with-libzip=${PREFIX}

.include "../../archivers/libzip/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
