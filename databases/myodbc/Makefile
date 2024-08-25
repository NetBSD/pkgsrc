# $NetBSD: Makefile,v 1.47 2024/08/25 06:18:30 wiz Exp $

DISTNAME=	mysql-connector-odbc-8.0.31
PKGNAME=	${DISTNAME:S/mysql-connector-odbc/myodbc/}
CATEGORIES=	databases
#MASTER_SITES=	${MASTER_SITE_MYSQL:=Connector-ODBC/5.3/}
MASTER_SITES=	${MASTER_SITE_GITHUB:=mysql/}
GITHUB_PROJECT=	mysql-connector-odbc
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.mysql.com/
COMMENT=	ODBC driver (server side) for MySQL
LICENSE=	gnu-gpl-v2

USE_CMAKE=		yes
CMAKE_CONFIGURE_ARGS=		-Wno-dev
#CMAKE_CONFIGURE_ARGS+=		-DMYSQL_DIR=${BUILDLINK_PREFIX.mysql-client}
CMAKE_CONFIGURE_ARGS+=		-DMYSQL_INCLUDE_DIR=${BUILDLINK_PREFIX.mysql-client}/include/mysql
USE_LANGUAGES=		c c++

INSTALLATION_DIRS=	share/doc/mysql-connector-odbc
INSTALLATION_DIRS+=	share/mysql-connector-odbc/test

.include "options.mk"

MYSQL_VERSIONS_ACCEPTED=	80

.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
