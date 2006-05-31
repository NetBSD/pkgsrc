# $NetBSD: options.mk,v 1.5 2006/05/31 18:22:23 ghen Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.apr
PKG_SUPPORTED_OPTIONS=	db4 ldap

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdb4)
APU_CONFIGURE_ARGS+=	\
	--with-berkeley-db=${BUILDLINK_PREFIX.db4}/include:${LOCALBASE}
.  include "../../databases/db4/buildlink3.mk"
.else
APU_CONFIGURE_ARGS+=	--with-dbm=sdbm
.endif

.if !empty(PKG_OPTIONS:Mldap)
APU_CONFIGURE_ARGS+=	--with-ldap
APR_CONFIGURE_ARGS+=	--with-ldap
.  include "../../databases/openldap-client/buildlink3.mk"
.endif
