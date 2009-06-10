# $NetBSD: options.mk,v 1.4 2009/06/10 15:58:29 seb Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.apr-util
PKG_SUPPORTED_OPTIONS=	db4 ldap mysql pgsql sqlite3

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		ldap mysql pgsql sqlite3 db4

.if !empty(PKG_OPTIONS:Mdb4)
CONFIGURE_ARGS+=	\
	--with-berkeley-db=${BUILDLINK_PREFIX.db4}/include:${LOCALBASE}
PLIST.db4=	yes
.  include "../../databases/db4/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--with-dbm=sdbm
.endif

.if !empty(PKG_OPTIONS:Mldap)
PLIST.ldap=		yes
CONFIGURE_ARGS+=	--with-ldap
.  include "../../databases/openldap-client/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mmysql)
PLIST.mysql=		yes
CONFIGURE_ARGS+=	--with-mysql
.  include "../../mk/mysql.buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
PLIST.pgsql=		yes
CONFIGURE_ARGS+=	--with-pgsql
.  include "../../mk/pgsql.buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Msqlite3)
PLIST.sqlite3=		yes
CONFIGURE_ARGS+=	--with-sqlite3
.  include "../../databases/sqlite3/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-sqlite3
.endif
