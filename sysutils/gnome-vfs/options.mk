# $NetBSD: options.mk,v 1.10 2023/11/04 12:26:51 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gnome-vfs
PKG_SUPPORTED_OPTIONS=	fam gssapi inet6 avahi
PKG_SUGGESTED_OPTIONS=	fam inet6

# Kerberos is built in - no additional dependency
PKG_SUGGESTED_OPTIONS.NetBSD+=	gssapi

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mfam)
.include "../../mk/fam.buildlink3.mk"
CONFIGURE_ARGS+=	--enable-fam
.else
CONFIGURE_ARGS+=	--disable-fam
.endif

.if !empty(PKG_OPTIONS:Mgssapi)
.include "../../mk/krb5.buildlink3.mk"
.  if ${USE_BUILTIN.${KRB5_TYPE}:tl} == yes
CONFIGURE_ENV+=		KRB5_CONFIG=${SH_KRB5_CONFIG}
.  endif
.else
CONFIGURE_ENV+=		ac_cv_path_KRB5_CONFIG=none
.endif

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if !empty(PKG_OPTIONS:Mavahi)
CONFIGURE_ARGS+=	--enable-avahi
.include "../../net/avahi/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-avahi
.endif
