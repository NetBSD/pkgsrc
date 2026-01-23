# $NetBSD: Makefile,v 1.10 2026/01/23 05:45:02 wiz Exp $

MODNAME=	rrd
PECL_VERSION=	1.1.3
PKGREVISION=	30
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pecl.php.net/package/rrd
COMMENT=	PHP extension provides bindings to the RRDtool C library
LICENSE=	php

PHP_VERSIONS_ACCEPTED=	56

CONFIGURE_ARGS+=	--with-rrd=${BUILDLINK_PREFIX.rrdtool}

.include "../../databases/rrdtool/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
