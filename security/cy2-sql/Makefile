# $NetBSD: Makefile,v 1.4 2004/10/03 00:18:08 tv Exp $

PKGNAME=	${DISTNAME:S/cyrus-sasl/cy2-sql/}
PKGREVISION=	1
COMMENT=	Cyrus SASL SQL authentication plugin
SASL_PLUGIN=	yes

.include "../cyrus-sasl2/Makefile.common"

PKG_OPTIONS_VAR=	PKG_OPTIONS.cy2-sql
PKG_SUPPORTED_OPTIONS=	mysql pgsql sqlite

.if !defined(PKG_OPTIONS.cy2-sql)
PKG_DEFAULT_OPTIONS+=	mysql
.endif

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

CONFIGURE_ARGS+=	--enable-sql		# LOGIN

BUILD_DIRS=	${WRKSRC}/plugins
ALL_TARGET=	libsql.la

do-install:
	${INSTALL_DATA_DIR} ${PLUGINDIR}
	cd ${WRKSRC}/plugins && ${SHLIBTOOL} --mode=install \
		${INSTALL_PROGRAM} libsql.la ${PLUGINDIR}

.include "../../mk/bsd.pkg.mk"
