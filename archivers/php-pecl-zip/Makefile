# $NetBSD: Makefile,v 1.32 2026/01/07 08:45:47 wiz Exp $
#

MODNAME=	zip
PECL_VERSION=	1.22.7
PKGNAME=	${PHP_PKG_PREFIX}-pecl-${MODNAME}-${PECL_VERSION}
PKGREVISION=	1
CATEGORIES=	archivers

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pecl.php.net/package/zip
COMMENT=	Zip management extension with libzip
LICENSE=	php

CONFLICTS=		php${PHP_VER}-zip-[0-9]*

CONFIGURE_ARGS+=	--enable-zip
CONFIGURE_ARGS+=	--with-libzip=${PREFIX}

PHP_VERSIONS_INCOMPATIBLE=	56

.include "../../archivers/libzip/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
