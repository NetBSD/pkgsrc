# $NetBSD: Makefile,v 1.14 2023/11/08 13:18:23 wiz Exp $

DISTNAME=	mysql-connector-net-8.0.19-noinstall
PKGNAME=	csharp-mysql-8.0.19
PKGREVISION=	9
CATEGORIES=	databases devel
MASTER_SITES=	${MASTER_SITE_MYSQL:=Connector-Net/}
EXTRACT_SUFX=	.zip

MAINTAINER=	kefren@NetBSD.org
HOMEPAGE=	https://dev.mysql.com/downloads/connector/net/
COMMENT=	Fully managed ADO.NET driver for MySQL
LICENSE=	gnu-gpl-v2

EXTRACT_DIR=	${WRKDIR}/${PKGNAME}
WRKSRC=		${EXTRACT_DIR}

do-build:

do-install:
	${MV} ${WRKSRC}/v4.8/MySql.Data.dll ${WRKSRC}/v4.8/MySql.Data.dll
	${PREFIX}/bin/gacutil -i ${WRKSRC}/v4.8/MySql.Data.dll \
		-root ${DESTDIR}${PREFIX}/lib

.include "../../lang/mono/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
