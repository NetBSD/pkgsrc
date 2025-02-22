# $NetBSD: options.mk,v 1.1 2025/02/22 14:40:25 gdt Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ufraw
PKG_SUPPORTED_OPTIONS=	gimp lensfun
PKG_SUGGESTED_OPTIONS=	lensfun

.include "../../mk/bsd.options.mk"

# gimp support only works with gimp2.  gimp3 is imminent (and 1 of 1
# known users have switched to gimp3).
PLIST_VARS+=	gimp
.if !empty(PKG_OPTIONS:Mgimp)
.include "../../graphics/gimp/buildlink3.mk"
PLIST.gimp=	yes
.endif

.include "../../mk/bsd.options.mk"
.if !empty(PKG_OPTIONS:Mlensfun)
.include "../../graphics/lensfun/buildlink3.mk"
.endif
