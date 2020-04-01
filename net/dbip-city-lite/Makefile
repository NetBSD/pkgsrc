# $NetBSD: Makefile,v 1.2 2020/04/01 09:19:24 fcambus Exp $

DISTNAME=	dbip-city-lite-2020-04.mmdb
PKGNAME=	dbip-city-lite-2020.04
CATEGORIES=	net
MASTER_SITES=	https://download.db-ip.com/free/
EXTRACT_SUFX=	.gz

MAINTAINER=	fcambus@NetBSD.org
HOMEPAGE=	https://db-ip.com/db/lite.php
COMMENT=	DB-IP IP to City Lite: IPv4/v6 address to city
LICENSE=	cc-by-v4.0

NO_BUILD=	yes

INSTALLATION_DIRS+=	share/dbip

do-install:
	${RUN}${INSTALL_DATA} ${WRKDIR}/${DISTNAME} \
		${DESTDIR}${PREFIX}/share/dbip/dbip-city-lite.mmdb

.include "../../mk/bsd.pkg.mk"
