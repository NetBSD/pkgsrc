# $NetBSD: Makefile,v 1.4 2003/12/28 12:31:42 jmmv Exp $
#

DISTNAME=	GeoIP-1.3.1
CATEGORIES=	net
MASTER_SITES=	http://www.maxmind.com/download/geoip/api/c/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.maxmind.com/download/geoip/api/c/
COMMENT=	Find the country from any IP address

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
USE_PKGINSTALL=		yes

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

EGDIR=			${PREFIX}/share/examples/GeoIP
CONF_FILES=		${EGDIR}/GeoIP.conf.default ${PKG_SYSCONFDIR}/GeoIP.conf

.include "../../mk/bsd.pkg.mk"
