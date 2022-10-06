# $NetBSD: options.mk,v 1.1 2022/10/06 02:18:16 markd Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.rt5
PKG_OPTIONS_REQUIRED_GROUPS=	backend frontend
PKG_OPTIONS_GROUP.backend=	mysql oracle pgsql sqlite
PKG_OPTIONS_GROUP.frontend=	fastcgi modperl2
PKG_SUGGESTED_OPTIONS=		mysql fastcgi

.include "../../mk/bsd.options.mk"

# Frontend dependencies
.if !empty(PKG_OPTIONS:Mfastcgi)
DEPENDS+=	p5-FCGI>=0.74:../../www/p5-FCGI
DEPENDS+=	p5-FCGI-ProcManager-[0-9]*:../../www/p5-FCGI-ProcManager
.elif !empty(PKG_OPTIONS:Mmodperl2)
DEPENDS+=	p5-Apache-DBI>=0.92:../../databases/p5-Apache-DBI
DEPENDS+=	p5-HTML-Mason>=1.36:../../www/p5-HTML-Mason
.endif


# Backend database dependencies
.if !empty(PKG_OPTIONS:Mmysql)
DEPENDS+=	p5-DBD-mysql>=2.1018:../../databases/p5-DBD-mysql
RT_DB_TYPE=	mysql
.elif !empty(PKG_OPTIONS:Mpgsql)
DEPENDS+=	p5-DBD-postgresql>=1.43:../../databases/p5-DBD-postgresql
RT_DB_TYPE=	Pg
.elif !empty(PKG_OPTIONS:Moracle)
DEPENDS+=	p5-DBD-Oracle-[0-9]*:../../databases/p5-DBD-Oracle
RT_DB_TYPE=	Oracle
.elif !empty(PKG_OPTIONS:Msqlite)
DEPENDS+=	p5-DBD-SQLite>=1.00:../../databases/p5-DBD-SQLite
RT_DB_TYPE=	SQLite
.endif
