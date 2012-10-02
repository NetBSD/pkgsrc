# $NetBSD: Makefile,v 1.2 2012/10/02 21:25:16 asau Exp $

DISTNAME=	mysql-connector-net-6.3.5-noinstall
PKGNAME=	csharp-mysql-6.3.5
CATEGORIES=	databases devel
MASTER_SITES=	${MASTER_SITE_MYSQL:=Connector-Net/}
EXTRACT_SUFX=	.zip

MAINTAINER=	kefren@NetBSD.org
HOMEPAGE=	http://dev.mysql.com/downloads/connector/net/
COMMENT=	Fully managed ADO.NET driver for MySQL
LICENSE=	gnu-gpl-v2

DEPENDS+=	mono>=2.0:../../lang/mono

EXTRACT_DIR=	${WRKDIR}/${PKGNAME}
WRKSRC=		${EXTRACT_DIR}

do-build:

do-install:
	${MV} ${WRKSRC}/v2/mysql.data.dll ${WRKSRC}/v2/MySql.Data.dll
	${PREFIX}/bin/gacutil -i ${WRKSRC}/v2/MySql.Data.dll \
		-root ${DESTDIR}${PREFIX}/lib

.include "../../mk/bsd.pkg.mk"
