# $NetBSD: options.mk,v 1.5 2018/06/23 20:27:38 youri Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.xfce4-thunar
PKG_SUPPORTED_OPTIONS=	gvfs introspection
PKG_SUGGESTED_OPTIONS=	gvfs introspection

PLIST_VARS+=	introspection

.include "../../mk/bsd.options.mk"

# for trash support, and remote filesystems
.if !empty(PKG_OPTIONS:Mgvfs)
DEPENDS+=	gvfs-[0-9]*:../../sysutils/gvfs
.endif

# for GObject introspection support in thunarx
.if !empty(PKG_OPTIONS:Mintrospection)
PLIST.introspection=	yes
.include "../../devel/gobject-introspection/buildlink3.mk"
.endif
