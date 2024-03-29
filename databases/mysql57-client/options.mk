# $NetBSD: options.mk,v 1.5 2023/05/25 09:06:57 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mysql5

PKG_SUPPORTED_OPTIONS+=	dtrace embedded-server ldap memcached
PKG_SUGGESTED_OPTIONS+=	embedded-server

.include "../../mk/bsd.options.mk"

# Enable DTrace support
.if !empty(PKG_OPTIONS:Mdtrace)
CMAKE_ARGS+=	-DENABLE_DTRACE=ON
.else
CMAKE_ARGS+=	-DENABLE_DTRACE=OFF
.endif

# LDAP support
.if !empty(PKG_OPTIONS:Mldap)
.include "../../databases/openldap-client/buildlink3.mk"
CMAKE_ARGS+=	-DWITH_AUTHENTICATION_LDAP=ON
.endif

# Enable InnoDB Memcached support
PLIST_VARS+=	memcached
.if !empty(PKG_OPTIONS:Mmemcached)
PLIST.memcached=	yes
CMAKE_ARGS+=	-DWITH_INNODB_MEMCACHED=ON
CMAKE_ARGS+=	-DWITH_BUNDLED_MEMCACHED=ON
.else
CMAKE_ARGS+=	-DWITH_INNODB_MEMCACHED=OFF
.endif
