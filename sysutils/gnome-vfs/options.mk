# $NetBSD: options.mk,v 1.1 2008/12/01 14:41:52 wiz Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.gnome-vfs
PKG_SUPPORTED_OPTIONS=	gssapi hal inet6
PKG_SUGGESTED_OPTIONS=	hal

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == NetBSD
# Kerberos is built in - no additional dependency
PKG_SUGGESTED_OPTIONS+= gssapi
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgssapi)
.include "../../mk/krb5.buildlink3.mk"
CONFIGURE_ENV+=		KRB5_CONFIG=${SH_KRB5_CONFIG}
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
