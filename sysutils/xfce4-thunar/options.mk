# $NetBSD: options.mk,v 1.2 2015/04/21 08:56:41 jperkin Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.xfce4-thunar
PKG_SUPPORTED_OPTIONS=	gvfs
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

# for trash support, and remote filesystems
.if !empty(PKG_OPTIONS:Mgvfs)
DEPENDS+=	gvfs-[0-9]*:../../sysutils/gvfs
.endif
