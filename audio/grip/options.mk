# $NetBSD: options.mk,v 1.1 2017/08/18 12:21:29 triaxx Exp $
#

PKG_OPTIONS_VAR=		PKG_OPTIONS.grip
PKG_SUPPORTED_OPTIONS=		cdparanoia id3
PKG_SUGGESTED_OPTIONS=		cdparanoia id3

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

###
### Cdparanoia support
###
.if !empty(PKG_OPTIONS:Mcdparanoia)
.  include "../../audio/cdparanoia/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-cdpar
.endif

###
### ID3v2 support
###
.if !empty(PKG_OPTIONS:Mid3)
.  include "../../audio/id3lib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-id3
.endif
