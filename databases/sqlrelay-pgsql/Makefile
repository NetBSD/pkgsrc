# $NetBSD: Makefile,v 1.14 2018/08/16 18:54:39 adam Exp $

PKGNAME=		${DISTNAME:S/sqlrelay/sqlrelay-pgsql/}
PKGREVISION=		5
COMMENT=		PostgreSQL support for SQL Relay

.include "../../databases/sqlrelay/Makefile.common"

LICENSE=		postgresql-license

CONFIGURE_ARGS+=	--with-postgresql-prefix=${PGSQL_PREFIX}
CONFIGURE_ARGS+=	--disable-mysql
CONFIGURE_ARGS+=	--disable-sqlite
CONFIGURE_ARGS+=	--disable-freetds
CONFIGURE_ARGS+=	--disable-odbc

BUILD_DIRS=		src/connections

INSTALLATION_DIRS+=	libexec/sqlrelay

do-install:
	${LIBTOOL} --mode=install ${INSTALL_LIB} \
		${WRKSRC}/${BUILD_DIRS}/sqlrconnection_postgresql.la \
		${DESTDIR}${PREFIX}/libexec/sqlrelay

.include "../../databases/sqlrelay/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
