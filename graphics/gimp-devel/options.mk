# $NetBSD: options.mk,v 1.2 2024/11/07 07:58:57 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gimp
PKG_SUPPORTED_OPTIONS=	aalib mng xpm
PKG_SUGGESTED_OPTIONS=	mng xpm

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		aalib mng xpm

.if !empty(PKG_OPTIONS:Maalib)
.include "../../graphics/aalib/buildlink3.mk"
PRINT_PLIST_AWK+=       { if (/file-aa/) $$0 = "$${PLIST.aalib}" $$0 }
PLIST.aalib=		yes
.endif

.if !empty(PKG_OPTIONS:Mmng)
.include "../../graphics/mng/buildlink3.mk"
PRINT_PLIST_AWK+=       { if (/file-mng/) $$0 = "$${PLIST.mng}" $$0 }
PLIST.mng=		yes
.endif

.if !empty(PKG_OPTIONS:Mxpm)
.include "../../x11/libXpm/buildlink3.mk"
PRINT_PLIST_AWK+=       { if (/file-xpm/) $$0 = "$${PLIST.xpm}" $$0 }
PLIST.xpm=		yes
.endif
