# $NetBSD: options.mk,v 1.2 2004/11/17 19:33:11 xtraeme Exp $
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
PKG_DEFAULT_OPTIONS+=	openldap
.endif

PKG_OPTIONS_VAR=	PKG_OPTIONS.apr
PKG_SUPPORTED_OPTIONS=	db4 openldap

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdb4)
APU_CONFIGURE_ARGS+=	\
	--with-berkeley-db=${BUILDLINK_PREFIX.db4}/include:${LOCALBASE}
.  include "../../databases/db4/buildlink3.mk"
.else
APU_CONFIGURE_ARGS+=	--with-dbm=sdbm
.endif

.if !empty(PKG_OPTIONS:Mopenldap)
APU_CONFIGURE_ARGS+=	--with-ldap
APR_CONFIGURE_ARGS+=	--with-ldap
.  include "../../databases/openldap/buildlink3.mk"
.endif
