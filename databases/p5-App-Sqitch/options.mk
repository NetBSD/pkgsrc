# $NetBSD: options.mk,v 1.3 2025/10/09 17:12:00 schmonz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.sqitch

PKG_SUPPORTED_OPTIONS+=	mysql odbc oracle pgsql sqlite
PKG_SUGGESTED_OPTIONS=	sqlite

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmysql)
DEPENDS+=		p5-DBD-MariaDB>=1.0:../../databases/p5-DBD-MariaDB
# MySQL::Config: '0'
BUILD_PARAMS+=		--with mysql
.endif

.if !empty(PKG_OPTIONS:Modbc)
DEPENDS+=		p5-DBD-ODBC>=1.59:../../databases/p5-DBD-ODBC
BUILD_PARAMS+=		--with odbc
.endif

.if !empty(PKG_OPTIONS:Moracle)
DEPENDS+=		p5-DBD-Oracle>=1.23:../../databases/p5-DBD-Oracle
BUILD_PARAMS+=		--with oracle
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
DEPENDS+=		p5-DBD-postgresql>=2.0:../../databases/p5-DBD-postgresql
BUILD_PARAMS+=		--with postgres
.endif

.if !empty(PKG_OPTIONS:Msqlite)
DEPENDS+=		p5-DBD-SQLite>=1.37:../../databases/p5-DBD-SQLite
BUILD_PARAMS+=		--with sqlite
.endif
