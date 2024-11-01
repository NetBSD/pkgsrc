# $NetBSD: Makefile,v 1.25 2024/11/01 12:51:23 wiz Exp $
#

MODNAME=	zip
PECL_VERSION=	1.22.4
PKGNAME=	${PHP_PKG_PREFIX}-pecl-${MODNAME}-${PECL_VERSION}
PKGREVISION=	2
CATEGORIES=	archivers

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pecl.php.net/package/zip
COMMENT=	Zip management extension with libzip
LICENSE=	php

#PHP_VERSIONS_INCOMPATIBLE=	56

CONFIGURE_ARGS+=	--enable-zip
CONFIGURE_ARGS+=	--with-libzip=${PREFIX}

.include "../../archivers/libzip/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
