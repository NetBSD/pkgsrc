# $NetBSD: Makefile,v 1.7 2022/05/22 14:11:05 taca Exp $
#

MODNAME=		geoip
PECL_VERSION=		1.1.1
CATEGORIES=		net geography

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://pecl.php.net/package/geoip/
COMMENT=		PHP module to map IP address to geographic places
LICENSE=		php

PHP_VERSIONS_ACCEPTED=	56 74

USE_LANGUAGES=		c c++

CONFIGURE_ARGS+=	--with-${MODNAME}
CONFIGURE_ARGS+=	--with-${PKGMODNAME}=shared,${BUILDLINK_DIR}

.include "../../lang/php/ext.mk"
.include "../../net/GeoIP/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
