# $NetBSD: options.mk,v 1.7 2005/01/14 05:15:40 jlam Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.sudo
PKG_SUPPORTED_OPTIONS=	PAM kerberos ldap skey
.if ${OPSYS} == "NetBSD"
PKG_DEFAULT_OPTIONS+=	skey
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:MPAM)
.  include "../../mk/pam.buildlink3.mk"
DL_AUTO_VARS=		yes
CONFIGURE_ARGS+=	--with-pam
.endif

.if !empty(PKG_OPTIONS:Mkerberos)
.  include "../../mk/krb5.buildlink3.mk"
CONFIGURE_ARGS+=	--without-kerb4
CONFIGURE_ARGS+=	--with-kerb5
.else
CONFIGURE_ARGS+=	--without-kerb5
.endif

.if !empty(PKG_OPTIONS:Mldap)
.  include "../../databases/openldap/buildlink3.mk"
DL_AUTO_VARS=		yes
CONFIGURE_ARGS+=	--with-ldap=${BUILDLINK_PREFIX.openldap}
CONFIGURE_ARGS+=	--with-ldap-conf-file=${PKG_SYSCONFDIR}/ldap.conf
.endif

.if !empty(PKG_OPTIONS:Mskey)
CONFIGURE_ARGS+=	--with-skey
.else
CONFIGURE_ARGS+=	--without-skey
.endif
