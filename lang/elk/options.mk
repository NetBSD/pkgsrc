# $NetBSD: options.mk,v 1.3 2008/04/12 22:43:02 jlam Exp $

# Global and legacy options

PKG_OPTIONS_VAR=	PKG_OPTIONS.elk
PKG_SUPPORTED_OPTIONS= xaw motif
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		x11 xaw motif

###
### x11 support
###
.if !empty(PKG_OPTIONS:Mxaw) || !empty(PKG_OPTIONS:Mmotif)
PLIST.x11=		yes
.  if !empty(PKG_OPTIONS:Mxaw)
PLIST.xaw=		yes
CONFIGURE_ENV+=		WITH_XAW="yes"
.    include "../../mk/xaw.buildlink3.mk"
.  else
CONFIGURE_ENV+=		WITH_XAW="no"
.  endif
.  if !empty(PKG_OPTIONS:Mmotif)
.  include "../../mk/motif.buildlink3.mk"
PLIST.motif=		yes
.  endif
.else
CONFIGURE_ARGS+=	--without-x
.endif
