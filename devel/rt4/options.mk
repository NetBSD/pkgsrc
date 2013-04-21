# $NetBSD: options.mk,v 1.1 2013/04/21 13:59:34 ryoon Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.rt4
PKG_OPTIONS_REQUIRED_GROUPS=	backend frontend
PKG_OPTIONS_GROUP.backend=	mysql oracle pgsql sqlite
PKG_OPTIONS_GROUP.frontend=	fastcgi modperl1 modperl2
PKG_SUGGESTED_OPTIONS=		mysql fastcgi

.include "../../mk/bsd.options.mk"

# Frontend dependencies
.if !empty(PKG_OPTIONS:Mfastcgi)
DEPENDS+=	p5-FCGI>=0.74:../../www/p5-FCGI
DEPENDS+=	p5-FCGI-ProcManager-[0-9]*:../../www/p5-FCGI-ProcManager
.elif !empty(PKG_OPTIONS:Mmodperl1)
DEPENDS+=	p5-libapreq-[0-9]*:../../www/p5-libapreq
DEPENDS+=	p5-Apache-DBI>=0.92:../../databases/p5-Apache-DBI
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
