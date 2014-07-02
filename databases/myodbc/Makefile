# $NetBSD: Makefile,v 1.38 2014/07/02 03:41:51 jnemeth Exp $

DISTNAME=	mysql-connector-odbc-5.3.2-src
PKGNAME=	${DISTNAME:S/mysql-connector-odbc/myodbc/:S/-src$//}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_MYSQL:=Connector-ODBC/5.3/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mysql.com/
COMMENT=	ODBC driver (server side) for MySQL
LICENSE=	gnu-gpl-v2

USE_CMAKE=		yes
CMAKE_ARGS=		-Wno-dev
#CMAKE_ARGS+=		-DMYSQL_DIR=${BUILDLINK_PREFIX.mysql-client}
CMAKE_ARGS+=		-DMYSQL_INCLUDE_DIR=${BUILDLINK_PREFIX.mysql-client}/include/mysql
USE_LANGUAGES=		c c++

INSTALLATION_DIRS=	share/doc/mysql-connector-odbc
INSTALLATION_DIRS+=	share/mysql-connector-odbc/test

.include "options.mk"

MYSQL_VERSIONS_ACCEPTED=	56 55 51

.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
