# $NetBSD: Makefile,v 1.22 2024/05/29 16:31:17 adam Exp $
#

MODNAME=	zip
PECL_VERSION=	1.22.3
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
