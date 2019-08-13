# $NetBSD $

PKG_OPTIONS_VAR=	PKG_OPTIONS.xca
PKG_SUPPORTED_OPTIONS=	sqlite3 mysql pgsql
PKG_SUGGESTED_OPTIONS=	sqlite3

.include "../../mk/bsd.options.mk"

###
### Use SQLite3 for storing certificate data
###
.if !empty(PKG_OPTIONS:Msqlite3)
DEPENDS+=	qt4-sqlite3>=${QTVERSION}:../../x11/qt4-sqlite3
.endif

.if !empty(PKG_OPTIONS:Mmysql)
###
### Use MySQL for storing certificate data
###
DEPENDS+=	qt4-mysql>=${QTVERSION}:../../x11/qt4-mysql
.endif

###
### Use PostgreSQL for storing certificate data
###
.if !empty(PKG_OPTIONS:Mpgsql)
DEPENDS+=	qt4-pgsql>=${QTVERSION}:../../x11/qt4-pgsql
.endif
