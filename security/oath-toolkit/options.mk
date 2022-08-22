# $NetBSD: options.mk,v 1.1 2022/08/22 07:42:52 sborrill Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.oath-toolkit
PKG_SUPPORTED_OPTIONS+=	pam
PKG_SUGGESTED_OPTIONS=	pam

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	pam

.if !empty(PKG_OPTIONS:Mpam)
PLIST.pam=		yes
.  include "../../mk/pam.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-pam
.endif
