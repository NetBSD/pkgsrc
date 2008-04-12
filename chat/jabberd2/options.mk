# $NetBSD: options.mk,v 1.20 2008/04/12 22:42:58 jlam Exp $
#

PKG_OPTIONS_VAR=		PKG_OPTIONS.jabberd2
PKG_OPTIONS_REQUIRED_GROUPS=	auth storage
# Authentication backend
PKG_OPTIONS_GROUP.auth=		auth-mysql auth-pgsql auth-sqlite
PKG_OPTIONS_GROUP.auth+=	auth-db auth-ldap auth-pam
# Storage backend
PKG_OPTIONS_GROUP.storage=	storage-mysql storage-pgsql
PKG_OPTIONS_GROUP.storage+=	storage-sqlite storage-db
PKG_SUPPORTED_OPTIONS+=		debug
PKG_SUGGESTED_OPTIONS=		auth-sqlite storage-sqlite

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		db ldap mysql pam pgsql sqlite

.if !empty(PKG_OPTIONS:Mauth-db) || !empty(PKG_OPTIONS:Mstorage-db)
SUBST_CLASSES+=		fixdb
SUBST_STAGE.fixdb=	post-configure
SUBST_FILES.fixdb=	storage/Makefile.in
SUBST_SED.fixdb=	-e "s|@DB_LIBS@||g"
BUILDLINK_TRANSFORM+=	rm:-ldb
BDB_ACCEPTED=		db4
PLIST.db=		yes
CONFIGURE_ARGS+=	--enable-db
.  include "../../mk/bdb.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-db
.endif

.if !empty(PKG_OPTIONS:Mauth-mysql) || !empty(PKG_OPTIONS:Mstorage-mysql)
PLIST.mysql=		yes
CONFIGURE_ARGS+=	--enable-mysql
CPPFLAGS+=		-I${BUILDLINK_PREFIX.mysql-client}/include/mysql
.  include "../../mk/mysql.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-mysql
.endif

.if !empty(PKG_OPTIONS:Mauth-pgsql) || !empty(PKG_OPTIONS:Mstorage-pgsql)
PLIST.pgsql=		yes
CONFIGURE_ARGS+=	--enable-pgsql
.  include "../../mk/pgsql.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-pgsql
.endif

.if !empty(PKG_OPTIONS:Mauth-sqlite) || !empty(PKG_OPTIONS:Mstorage-sqlite)
PLIST.sqlite=		yes
CONFIGURE_ARGS+=	--enable-sqlite
.  include "../../databases/sqlite3/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-sqlite
.endif

.if !empty(PKG_OPTIONS:Mauth-ldap)
PLIST.ldap=		yes
CONFIGURE_ARGS+=	--enable-ldap
.  include "../../databases/openldap-client/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-ldap
.endif

.if !empty(PKG_OPTIONS:Mauth-pam)
PLIST.pam=		yes
CONFIGURE_ARGS+=	--enable-pam
.  include "../../mk/pam.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-pam
.endif

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
.endif
