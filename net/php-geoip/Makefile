# $NetBSD: Makefile,v 1.3 2015/12/19 14:27:14 taca Exp $
#

MODNAME=		geoip
PECL_VERSION=		1.0.8
CATEGORIES=		net geography

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://pecl.php.net/package/geoip/
COMMENT=		PHP module to map IP address to geographic places
LICENSE=		php

PHP_VERSIONS_ACCEPTED=	55 56

CONFIGURE_ARGS+=	--with-${MODNAME}
CONFIGURE_ARGS+=	--with-${PKGMODNAME}=shared,${BUILDLINK_DIR}

.include "../../lang/php/ext.mk"
.include "../../net/GeoIP/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
