# $NetBSD: Makefile,v 1.43 2023/11/06 21:42:52 fcambus Exp $

DISTNAME=	dbip-asn-lite-2023-11.mmdb
PKGNAME=	dbip-asn-lite-2023.11
CATEGORIES=	net
MASTER_SITES=	https://download.db-ip.com/free/
EXTRACT_SUFX=	.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://db-ip.com/db/download/ip-to-asn-lite
COMMENT=	DB-IP IP to ASN Lite: IPv4/v6 address to ASN
LICENSE=	cc-by-v4.0

NO_BUILD=	yes

INSTALLATION_DIRS+=	share/dbip

do-install:
	${RUN}${INSTALL_DATA} ${WRKDIR}/${DISTNAME} \
		${DESTDIR}${PREFIX}/share/dbip/dbip-asn-lite.mmdb

.include "../../mk/bsd.pkg.mk"
