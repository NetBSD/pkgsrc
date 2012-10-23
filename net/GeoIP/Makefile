# $NetBSD: Makefile,v 1.29 2012/10/23 17:18:07 asau Exp $

DISTNAME=	GeoIP-1.4.8
CATEGORIES=	net
MASTER_SITES=	http://geolite.maxmind.com/download/geoip/api/c/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.maxmind.com/app/c
COMMENT=	Find the country from any IP address
LICENSE=	gnu-lgpl-v2.1 AND gnu-gpl-v2 #  md5.c and types.h, from GNUPG

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

EGDIR=		${PREFIX}/share/examples/GeoIP
CONF_FILES=	${EGDIR}/GeoIP.conf.default ${PKG_SYSCONFDIR}/GeoIP.conf

TEST_TARGET=	check

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
