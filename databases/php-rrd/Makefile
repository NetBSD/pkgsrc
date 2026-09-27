# $NetBSD: Makefile,v 1.39 2026/09/27 11:35:22 tnn Exp $

MODNAME=	rrd
PECL_VERSION=	2.0.3
PKGREVISION=	11
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pecl.php.net/package/rrd
COMMENT=	PHP extension provides bindings to the RRDtool C library
LICENSE=	php

PHP_VERSIONS_INCOMPATIBLE=	85 56

CONFIGURE_ARGS+=	--with-rrd=${BUILDLINK_PREFIX.rrdtool}

.include "../../databases/rrdtool/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
