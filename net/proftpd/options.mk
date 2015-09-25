# $NetBSD: options.mk,v 1.13 2015/09/25 10:01:37 wiedi Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.proftpd
PKG_SUPPORTED_OPTIONS=	pam inet6
PKG_SUGGESTED_OPTIONS=	pam inet6

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	pam

MODULES=	# empty

.if !empty(PKG_OPTIONS:Mpam)
CONFIGURE_ARGS+=	--enable-auth-pam
.include "../../mk/pam.buildlink3.mk"
MODULES+=	mod_sftp_pam
PLIST.pam=	yes
.else
CONFIGURE_ARGS+=	--disable-auth-pam
.endif

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif
