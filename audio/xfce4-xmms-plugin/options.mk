# $NetBSD: options.mk,v 1.1 2007/04/12 09:55:09 martti Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.xfce4-xmms-plugin
PKG_SUPPORTED_OPTIONS=
PKG_OPTIONS_REQUIRED_GROUPS+=	xfce4-xmms-plugin-player
PKG_OPTIONS_GROUP.xfce4-xmms-plugin-player=	xmms bmp
PKG_SUGGESTED_OPTIONS=		xmms

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mbmp)
.include "../../audio/bmp/buildlink3.mk"
.else
.include "../../audio/xmms/buildlink3.mk"
.endif
