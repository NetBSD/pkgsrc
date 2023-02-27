# $NetBSD: options.mk,v 1.7 2023/02/27 20:08:37 vins Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.alpine

PKG_SUPPORTED_OPTIONS+=	aspell kerberos inet6 ldap pam threads
PKG_SUGGESTED_OPTIONS=	kerberos pam

CHECK_BUILTIN.pthread:= yes
.include "../../mk/pthread.builtin.mk"
CHECK_BUILTIN.pthread:= no
.if ${BUILTIN_LIB_FOUND.pthread:U:tl} == yes
PKG_SUGGESTED_OPTIONS+=	threads
.endif

.if ${IPV6_READY:tl} == "yes"
PKG_SUGGESTED_OPTIONS+=	inet6
.endif

.include "../../mk/bsd.options.mk"

###
### Aspell spell-check support
###
.if !empty(PKG_OPTIONS:Maspell)
.  include "../../textproc/aspell/buildlink3.mk"
CONFIGURE_ARGS+=	--with-simple-spellcheck=aspell
CONFIGURE_ARGS+=	--with-interactive-spellcheck=aspell
CONFIGURE_ENV+=		ac_cv_path_alpine_simple_spellcheck=${PREFIX}/bin/aspell
CONFIGURE_ENV+=		ac_cv_path_alpine_interactive_spellcheck=${PREFIX}/bin/aspell
.endif

###
### IPv6 support
###
.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--with-ipv6
.else
CONFIGURE_ARGS+=	--without-ipv6
.endif

###
### Support POSIX threads
###
.if !empty(PKG_OPTIONS:Mthreads)
.  include "../../mk/pthread.buildlink3.mk"
CONFIGURE_ARGS+=	--with-pthread
.else
CONFIGURE_ARGS+=	--without-pthread
.endif

###
### Support GSSAPI authentication via Kerberos 5.
###
.if !empty(PKG_OPTIONS:Mkerberos)
.  include "../../mk/krb5.buildlink3.mk"
CONFIGURE_ARGS+=	--with-krb5-dir=${KRB5BASE:Q}
CONFIGURE_ENV+=	alpine_GSSTYPE=${KRB5_TYPE}
.else
CONFIGURE_ARGS+=	 --without-krb5
.endif

###
### LDAP server support
###
.if !empty(PKG_OPTIONS:Mldap)
.  include "../../databases/openldap-client/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ldap-dir=${BUILDLINK_PREFIX.openldap-client}
.else
CONFIGURE_ARGS+=    	--without-ldap
.endif

###
### PAM support
###
.if !empty(PKG_OPTIONS:Mpam)
.  include "../../mk/pam.buildlink3.mk"
CONFIGURE_ENV+=		ac_cv_lib_pam_pam_start=yes
.else
CONFIGURE_ENV+=		ac_cv_lib_pam_pam_start=no
.endif
