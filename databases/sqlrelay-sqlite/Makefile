# $NetBSD: Makefile,v 1.54 2024/05/16 06:14:43 wiz Exp $

PKGNAME=	${DISTNAME:S/sqlrelay/sqlrelay-sqlite/}
PKGREVISION=	4
COMMENT=	SQLite support for SQL Relay

.include "../../databases/sqlrelay/Makefile.common"

# Configure never does this correctly
CXXFLAGS+=		-DSQLITE3=1
CONFIGURE_ARGS+=	--disable-freetds
CONFIGURE_ARGS+=	--disable-mysql
CONFIGURE_ARGS+=	--disable-odbc
CONFIGURE_ARGS+=	--disable-perl
CONFIGURE_ARGS+=	--disable-postgresql
CONFIGURE_ARGS+=	--with-sqlite-prefix=${BUILDLINK_PREFIX.sqlite3}

BUILD_DIRS=		src/connections

INSTALLATION_DIRS+=	libexec/sqlrelay

do-install:
	${LIBTOOL} --mode=install ${INSTALL_LIB} \
		${WRKSRC}/${BUILD_DIRS}/sqlrconnection_sqlite.la \
		${DESTDIR}${PREFIX}/libexec/sqlrelay

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../databases/sqlrelay/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
