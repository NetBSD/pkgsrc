# $NetBSD: Makefile,v 1.39 2023/03/01 08:08:09 fcambus Exp $

DISTNAME=	dbip-city-lite-2023-03.mmdb
PKGNAME=	dbip-city-lite-2023.03
CATEGORIES=	net
MASTER_SITES=	https://download.db-ip.com/free/
EXTRACT_SUFX=	.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://db-ip.com/db/download/ip-to-city-lite
COMMENT=	DB-IP IP to City Lite: IPv4/v6 address to city
LICENSE=	cc-by-v4.0

NO_BUILD=	yes

INSTALLATION_DIRS+=	share/dbip

do-install:
	${RUN}${INSTALL_DATA} ${WRKDIR}/${DISTNAME} \
		${DESTDIR}${PREFIX}/share/dbip/dbip-city-lite.mmdb

.include "../../mk/bsd.pkg.mk"
