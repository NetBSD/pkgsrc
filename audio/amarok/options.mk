# $NetBSD: options.mk,v 1.7 2010/02/16 09:01:46 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.amarok
PKG_SUPPORTED_OPTIONS=	libgpod libmp4v2 libmtp libvisual mp3tunes
PKG_SUGGESTED_OPTIONS=	libgpod libmp4v2 libmtp libvisual mp3tunes

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlibgpod)
BUILDLINK_API_DEPENDS.libgpod+=	libgpod>=0.6.0nb1
.include "../../audio/libgpod/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif

# libifp is currently not supported
#.if !empty(PKG_OPTIONS:Mlibifp)
#.include "../../audio/libifp/buildlink3.mk"
#.endif

.if !empty(PKG_OPTIONS:Mlibmp4v2)
.include "../../multimedia/libmp4v2/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mlibmtp)
.include "../../devel/libmtp/buildlink3.mk"
.endif

# libnjb is currently not supported
#.if !empty(PKG_OPTIONS:Mlibnjb)
#.include "../../devel/libnjb/buildlink3.mk"
#.endif

.if !empty(PKG_OPTIONS:Mlibvisual)
.include "../../audio/libvisual/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mmp3tunes)
.include "../../chat/loudmouth/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
# XXX: make sure qt4-libs have glib enabled
.endif
