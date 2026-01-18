# $NetBSD: options.mk,v 1.1 2026/01/18 17:00:44 ryoon Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.opendmarc
PKG_OPTIONS_REQUIRED_GROUPS=	db
PKG_OPTIONS_GROUP.db=	mysql mariadb
PKG_SUGGESTED_OPTIONS=	mysql

.include "../../mk/bsd.options.mk"

###
### Backend database support
###
.if !empty(PKG_OPTIONS:Mmysql)
DEPENDS+=	p5-DBD-mysql-[0-9]*:../../databases/p5-DBD-mysql
CONFIGURE_ARGS+=	--with-sql-backend=mysql
.elif !empty(PKG_OPTIONS:Mmariadb)
DEPENDS+=	p5-DBD-MariaDB-[0-9]*:../../databases/p5-DBD-MariaDB
CONFIGURE_ARGS+=	--with-sql-backend=MariaDB
.endif
