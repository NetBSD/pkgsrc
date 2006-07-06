# $NetBSD: options.mk,v 1.2 2006/07/06 08:37:27 dillo Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.vice
PKG_SUPPORTED_OPTIONS=	esound ffmpeg lame gnome

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mesound)
.include "../../audio/esound/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-esd
.endif

.if !empty(PKG_OPTIONS:Mffmpeg)
CONFIGURE_ARGS+=	--enable-ffmpeg
.include "../../multimedia/ffmpeg/buildlink3.mk"
.  if !empty(PKG_OPTIONS:Mlame)
.  include "../../audio/lame/buildlink3.mk"
.  endif
.endif

.if !empty(PKG_OPTIONS:Mgnome)
CONFIGURE_ARGS+=	--enable-gnomeui
PATCHFILES=		vice-1.19-gnome2.diff.gz
PATCH_SITES=		http://www.viceteam.org/online/
PATCH_DIST_STRIP=	-p1
.include "../../devel/libgnomeui/buildlink3.mk"
.endif
