# $NetBSD: Makefile,v 1.8 2005/12/05 20:50:55 rillig Exp $

PKGNAME=	${DISTNAME:S/cyrus-sasl/cy2-sql/}
COMMENT=	Cyrus SASL SQL authentication plugin
SASL_PLUGIN=	yes

.include "../../security/cyrus-sasl2/Makefile.common"

PKG_OPTIONS_VAR=	PKG_OPTIONS.cy2-sql
PKG_SUPPORTED_OPTIONS=	mysql pgsql sqlite
PKG_SUGGESTED_OPTIONS=	mysql

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmysql)
.  include "../../databases/mysql4-client/buildlink3.mk"
CONFIGURE_ARGS+=	--with-mysql=${BUILDLINK_PREFIX.mysql-client}
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
.  include "../../mk/pgsql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-pgsql=${PGSQL_PREFIX}
.endif

.if !empty(PKG_OPTIONS:Msqlite)
.  include "../../databases/sqlite/buildlink3.mk"
CONFIGURE_ARGS+=	--with-sqlite=${BUILDLINK_PREFIX.sqlite}
.endif

CONFIGURE_ARGS+=	--enable-sql

BUILD_DIRS=	${WRKSRC}/plugins
BUILD_TARGET=	libsql.la

do-install:
	${INSTALL_DATA_DIR} ${PLUGINDIR}
	cd ${WRKSRC}/plugins && ${SHLIBTOOL} --mode=install \
		${INSTALL_PROGRAM} libsql.la ${PLUGINDIR}

.include "../../mk/bsd.pkg.mk"
