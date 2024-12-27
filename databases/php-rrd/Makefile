# $NetBSD: Makefile,v 1.30 2024/12/27 08:19:29 wiz Exp $

MODNAME=	rrd
PECL_VERSION=	2.0.3
PKGREVISION=	4
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pecl.php.net/package/rrd/
COMMENT=	PHP extension provides bindings to the RRDtool C library
LICENSE=	php

PHP_VERSIONS_INCOMPATIBLE=	56

CONFIGURE_ARGS+=	--with-rrd=${BUILDLINK_PREFIX.rrdtool}

.include "../../databases/rrdtool/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
