# $NetBSD: Makefile,v 1.44 2020/06/02 08:24:39 adam Exp $

PKGNAME=	${DISTNAME:S/cyrus-sasl/cy2-sql/}
PKGREVISION=	5
COMMENT=	Cyrus SASL SQL authentication plugin
SASL_PLUGIN=	yes

.include "../../security/cyrus-sasl/Makefile.common"

PKG_OPTIONS_VAR=	PKG_OPTIONS.cy2-sql
PKG_SUPPORTED_OPTIONS=	mysql pgsql sqlite sqlite3
PKG_SUGGESTED_OPTIONS=	mysql

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmysql)
.  include "../../mk/mysql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-mysql=${BUILDLINK_PREFIX.mysql-client}
.else
CONFIGURE_ARGS+=	--without-mysql
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
.  include "../../mk/pgsql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-pgsql=${PGSQL_PREFIX:Q}
.else
CONFIGURE_ARGS+=	--without-pgsql
.endif

.if !empty(PKG_OPTIONS:Msqlite)
.  include "../../databases/sqlite/buildlink3.mk"
CONFIGURE_ARGS+=	--with-sqlite=${BUILDLINK_PREFIX.sqlite}
.else
CONFIGURE_ARGS+=	--without-sqlite
.endif

.if !empty(PKG_OPTIONS:Msqlite3)
.  include "../../databases/sqlite3/buildlink3.mk"
CONFIGURE_ARGS+=	--with-sqlite3=${BUILDLINK_PREFIX.sqlite3}
.else
CONFIGURE_ARGS+=	--without-sqlite3
.endif

CONFIGURE_ARGS+=	--enable-sql

BUILD_DIRS=	plugins
BUILD_TARGET=	libsql.la

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PLUGINDIR}
	cd ${WRKSRC}/plugins && ${SHLIBTOOL} --mode=install \
		${INSTALL_PROGRAM} libsql.la ${DESTDIR}${PLUGINDIR}

.include "../../mk/bsd.pkg.mk"
