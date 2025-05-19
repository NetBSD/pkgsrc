# $NetBSD: Makefile,v 1.30 2025/05/19 15:17:06 taca Exp $
#

MODNAME=	zip
PECL_VERSION=	1.22.6
PKGNAME=	${PHP_PKG_PREFIX}-pecl-${MODNAME}-${PECL_VERSION}
CATEGORIES=	archivers

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pecl.php.net/package/zip
COMMENT=	Zip management extension with libzip
LICENSE=	php

CONFLICTS=		php${PHP_VER}-zip

CONFIGURE_ARGS+=	--enable-zip
CONFIGURE_ARGS+=	--with-libzip=${PREFIX}

PHP_VERSIONS_INCOMPATIBLE=	56

.include "../../archivers/libzip/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
