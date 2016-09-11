# $NetBSD: Makefile,v 1.5 2016/09/11 17:03:27 taca Exp $
#

MODNAME=		geoip
PECL_VERSION=		1.1.1
CATEGORIES=		net geography

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://pecl.php.net/package/geoip/
COMMENT=		PHP module to map IP address to geographic places
LICENSE=		php

PHP_VERSIONS_ACCEPTED=	56 70

USE_LANGUAGES=		c c++

CONFIGURE_ARGS+=	--with-${MODNAME}
CONFIGURE_ARGS+=	--with-${PKGMODNAME}=shared,${BUILDLINK_DIR}

.include "../../lang/php/ext.mk"
.include "../../net/GeoIP/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
