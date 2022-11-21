# $NetBSD: options.mk,v 1.10 2022/11/21 22:28:41 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.geeqie
PKG_SUPPORTED_OPTIONS=		libchamplain
PKG_SUGGESTED_OPTIONS=		# none

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlibchamplain)
# While clutter is optional, the map requires it.
.include "../../graphics/clutter/buildlink3.mk"
.include "../../geography/libchamplain012/buildlink3.mk"
.endif
