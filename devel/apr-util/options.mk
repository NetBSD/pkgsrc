# $NetBSD: options.mk,v 1.1.1.1 2007/01/24 19:37:20 epg Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.apr-util
PKG_SUPPORTED_OPTIONS=	db4 ldap

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdb4)
CONFIGURE_ARGS+=	\
	--with-berkeley-db=${BUILDLINK_PREFIX.db4}/include:${LOCALBASE}
.  include "../../databases/db4/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--with-dbm=sdbm
.endif

.if !empty(PKG_OPTIONS:Mldap)
CONFIGURE_ARGS+=	--with-ldap
CONFIGURE_ARGS+=	--with-ldap
.  include "../../databases/openldap-client/buildlink3.mk"
.endif
