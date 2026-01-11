# $NetBSD: Makefile,v 1.35 2026/01/11 07:51:29 wiz Exp $

MODNAME=	rrd
PECL_VERSION=	2.0.3
PKGREVISION=	8
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pecl.php.net/package/rrd/
COMMENT=	PHP extension provides bindings to the RRDtool C library
LICENSE=	php

PHP_VERSIONS_INCOMPATIBLE=	85 56

CONFIGURE_ARGS+=	--with-rrd=${BUILDLINK_PREFIX.rrdtool}

.include "../../databases/rrdtool/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
