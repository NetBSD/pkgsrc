# $NetBSD: Makefile,v 1.36 2023/11/08 13:18:38 wiz Exp $

PKGNAME=	${DISTNAME:S/sqlrelay/sqlrelay-pgsql/}
PKGREVISION=	3
COMMENT=	PostgreSQL support for SQL Relay

.include "../../databases/sqlrelay/Makefile.common"

LICENSE=	postgresql-license

CONFIGURE_ARGS+=	--disable-freetds
CONFIGURE_ARGS+=	--disable-mysql
CONFIGURE_ARGS+=	--disable-odbc
CONFIGURE_ARGS+=	--disable-perl
CONFIGURE_ARGS+=	--disable-sqlite
CONFIGURE_ARGS+=	--with-postgresql-prefix=${PGSQL_PREFIX}

BUILD_DIRS=		src/connections

INSTALLATION_DIRS+=	libexec/sqlrelay

do-install:
	${LIBTOOL} --mode=install ${INSTALL_LIB} \
		${WRKSRC}/${BUILD_DIRS}/sqlrconnection_postgresql.la \
		${DESTDIR}${PREFIX}/libexec/sqlrelay

.include "../../databases/sqlrelay/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
