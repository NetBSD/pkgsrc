# $NetBSD: options.mk,v 1.3 2014/01/25 10:29:59 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.py-sqlalchemy
PKG_SUPPORTED_OPTIONS=	mysql sqlite pgsql mssql

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmysql)
DEPENDS+=	${PYPKGPREFIX}-mysqldb-[0-9]*:../../databases/py-mysqldb
PYTHON_VERSIONS_INCOMPATIBLE=	33 # py-mysqldb
.endif

.if !empty(PKG_OPTIONS:Msqlite)
DEPENDS+=	${PYPKGPREFIX}-sqlite2-[0-9]*:../../databases/py-sqlite2
PYTHON_VERSIONS_INCOMPATIBLE=	33 # py-sqlite2
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
DEPENDS+=	${PYPKGPREFIX}-psycopg2-[0-9]*:../../databases/py-psycopg2
.endif

.if !empty(PKG_OPTIONS:Mmssql)
DEPENDS+=	${PYPKGPREFIX}-mssql-[0-9]*:../../databases/py-mssql
PYTHON_VERSIONS_INCOMPATIBLE=	33 # py-mssql
.endif
