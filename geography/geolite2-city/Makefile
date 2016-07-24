# $NetBSD: Makefile,v 1.1 2016/07/24 02:07:49 agc Exp $

DISTNAME=	GeoLite2-City-CSV
PKGNAME=	${DISTNAME}-20160705
CATEGORIES=	geography
MASTER_SITES=	http://geolite.maxmind.com/download/geoip/database/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://dev.maxmind.com/geoip/geoip2/geolite2/
COMMENT=	Free IP city geolocation databases
LICENSE=	cc-by-sa-v4.0

DIST_SUBDIR=	${PKGNAME_NOREV}
WRKSRC=		${WRKDIR}/GeoLite2-City-CSV_20160705

AUTO_MKDIRS=	yes

do-build:
	${DO_NADA}

do-install:
	mkdir -p ${DESTDIR}${PREFIX}/share/GeoLite2-City-CSV
	(cd ${WRKSRC} && ${INSTALL_DATA} *.csv *.txt ${DESTDIR}${PREFIX}/share/GeoLite2-City-CSV/)

.include "../../mk/bsd.pkg.mk"
