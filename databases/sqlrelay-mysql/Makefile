# $NetBSD: Makefile,v 1.20 2020/03/08 16:49:08 wiz Exp $

PKGNAME=		${DISTNAME:S/sqlrelay/sqlrelay-mysql/}
PKGREVISION=		12
COMMENT=		MySQL support for SQL Relay

.include "../../databases/sqlrelay/Makefile.common"

LICENSE=		gnu-gpl-v2

CONFIGURE_ARGS+=	--with-mysql-prefix=${BUILDLINK_PREFIX.mysql-client}
CONFIGURE_ARGS+=	--disable-postgresql
CONFIGURE_ARGS+=	--disable-sqlite
CONFIGURE_ARGS+=	--disable-freetds
CONFIGURE_ARGS+=	--disable-odbc

BUILD_DIRS=		src/connections

INSTALLATION_DIRS+=	libexec/sqlrelay

do-install:
	${LIBTOOL} --mode=install ${INSTALL_LIB} \
		${WRKSRC}/${BUILD_DIRS}/sqlrconnection_mysql.la \
		${DESTDIR}${PREFIX}/libexec/sqlrelay

.include "../../databases/sqlrelay/buildlink3.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
