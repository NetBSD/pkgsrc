# $NetBSD: options.mk,v 1.3 2004/11/21 07:57:38 jlam Exp $
#
# XXX Support for the following variables will be removed after the
# XXX pkgsrc-2004Q4 branch is released:
# XXX
# XXX APR_USE_DB4
# XXX APR_USE_OPENLDAP

.if defined(APR_USE_DB4) && !empty(APR_USE_DB4:M[Yy][Ee][Ss])
PKG_DEFAULT_OPTIONS+=	db4
.endif

.if defined(APR_USE_OPENLDAP) && !empty(APR_USE_OPENLDAP:M[Yy][Ee][Ss])
PKG_DEFAULT_OPTIONS+=	ldap
.endif

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
.  include "../../databases/openldap/buildlink3.mk"
.endif
