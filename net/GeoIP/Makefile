# $NetBSD: Makefile,v 1.22 2009/05/19 08:59:26 wiz Exp $

DISTNAME=	GeoIP-1.4.6
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.maxmind.com/download/geoip/api/c/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.maxmind.com/download/geoip/api/c/
COMMENT=	Find the country from any IP address
#LICENSE=	gnu-lgpl-v2.1
#LICENSE+=	gnu-gpl-v2	#  md5.c and types.h, from GNUPG

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

EGDIR=		${PREFIX}/share/examples/GeoIP
CONF_FILES=	${EGDIR}/GeoIP.conf.default ${PKG_SYSCONFDIR}/GeoIP.conf

TEST_TARGET=	check

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
