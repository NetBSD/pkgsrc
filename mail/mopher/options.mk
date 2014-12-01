# $NetBSD: options.mk,v 1.1 2014/12/01 13:58:15 gdt Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mopher
PKG_SUPPORTED_OPTIONS=	mysql spf
PKG_SUGGESTED_OPTIONS=	spf

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		${PKG_SUPPORTED_OPTIONS}

# The use of db method is selected by config file; multiple methods
# can be compiled as modules.  Non-optional modules are memdb (a memory
# hash-table; not persistent) and bdb, which either uses dbopen(3) from
# libc or the legacy Berkeley DB API from one of the db packages.

# mysql
.if !empty(PKG_OPTIONS:Mmysql)
CONFIGURE_ARGS+=	--with-mysql
PLIST.mysql=		yes
.include "../../mk/mysql.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-mysql
.endif

# spf
.if !empty(PKG_OPTIONS:Mspf)
CONFIGURE_ARGS+=	--with-spf2
PLIST.spf=		yes
.include "../../mail/libspf2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-spf2
.endif
