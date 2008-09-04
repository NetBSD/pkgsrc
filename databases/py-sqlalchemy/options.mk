# $NetBSD: options.mk,v 1.1.1.1 2008/09/04 20:42:28 tonnerre Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.py-sqlalchemy
PKG_SUPPORTED_OPTIONS=	mysql sqlite pgsql

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmysql)
DEPENDS+=	${PYPKGPREFIX}-mysqldb-[0-9]*:../../databases/py-mysqldb
.endif

.if !empty(PKG_OPTIONS:Msqlite)
DEPENDS+=	${PYPKGPREFIX}-sqlite2-[0-9]*:../../databases/py-sqlite2
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
DEPENDS+=	${PYPKGPREFIX}-psycopg2-[0-9]*:../../databases/py-psycopg2
.endif
