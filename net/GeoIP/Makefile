# $NetBSD: Makefile,v 1.16 2006/06/05 16:38:40 tv Exp $
#

DISTNAME=	GeoIP-1.3.17
CATEGORIES=	net
MASTER_SITES=	http://www.maxmind.com/download/geoip/api/c/

MAINTAINER=	tv@NetBSD.org
HOMEPAGE=	http://www.maxmind.com/download/geoip/api/c/
COMMENT=	Find the country from any IP address

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

EGDIR=		${PREFIX}/share/examples/GeoIP
CONF_FILES=	${EGDIR}/GeoIP.conf.default ${PKG_SYSCONFDIR}/GeoIP.conf

TEST_TARGET=	check

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
