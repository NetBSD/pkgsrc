# $NetBSD: options.mk,v 1.7 2016/02/26 10:24:12 jperkin Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.gnome-vfs
PKG_SUPPORTED_OPTIONS=	fam gssapi hal inet6 avahi
PKG_SUGGESTED_OPTIONS=	fam hal inet6

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
.	if !empty(USE_BUILTIN.${KRB5_TYPE}:M[yY][eE][sS])
CONFIGURE_ENV+=		KRB5_CONFIG=${SH_KRB5_CONFIG}
.	endif
.else
CONFIGURE_ENV+=		ac_cv_path_KRB5_CONFIG=none
.endif

.if !empty(PKG_OPTIONS:Mhal)
MESSAGE_SRC+=	${.CURDIR}/MESSAGE.hal
.include "../../sysutils/hal/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-hal
.else
CONFIGURE_ARGS+=	--disable-hal
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
