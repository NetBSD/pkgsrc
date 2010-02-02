# $NetBSD: options.mk,v 1.1 2010/02/02 19:17:30 sno Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.p5-DBIx-Class-Schema-Loader

PKG_SUPPORTED_OPTIONS=	sqlite mysql pgsql oracle sybase odbc
PKG_SUGGESTED_OPTIONS=	# empty - only for CPAN Authors

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msqlite)
DEPENDS+=	p5-DBD-SQLite>=1.12:../../databases/p5-DBD-SQLite
BUILDLINK_DEPMETHOD.p5-DBI?=	full
.endif

.if !empty(PKG_OPTIONS:Mmysql)
DEPENDS+=	p5-DBD-mysql>=4.004:../../databases/p5-DBD-mysql
BUILDLINK_DEPMETHOD.p5-DBI?=	full
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
DEPENDS+=	p5-DBD-postgresql>=1.49:../../databases/p5-DBD-postgresql
BUILDLINK_DEPMETHOD.p5-DBI?=	full
.endif

.if !empty(PKG_OPTIONS:Moracle)
DEPENDS+=	p5-DBD-Oracle>=0.19:../../databases/p5-DBD-Oracle
BUILDLINK_DEPMETHOD.p5-DBI?=	full
.endif

.if !empty(PKG_OPTIONS:Msybase)
DEPENDS+=	p5-DBD-Sybase>=1.09:../../databases/p5-DBD-Sybase
BUILDLINK_DEPMETHOD.p5-DBI?=	full
.endif

.if !empty(PKG_OPTIONS:Modbc)
DEPENDS+=	p5-DBD-ODBC>=1.22:../../databases/p5-DBD-ODBC
BUILDLINK_DEPMETHOD.p5-DBI?=	full
.endif
