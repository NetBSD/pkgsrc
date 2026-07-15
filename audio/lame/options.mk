# $NetBSD: options.mk,v 1.7 2026/07/15 07:09:51 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.lame
PKG_SUPPORTED_OPTIONS=	gtk sndfile unicode
# We really want to work with unicode (ID3 Tags) in 2026.
PKG_SUGGESTED_OPTIONS=	unicode

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		gtk

.if !empty(PKG_OPTIONS:Mgtk)
CONFIGURE_ENV+=		GTK_CONFIG=${BUILDLINK_PREFIX.gtk}/bin/gtk-config
CONFIGURE_ARGS+=	--enable-mp3x
PLIST.gtk=		yes
.  include "../../x11/gtk/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Msndfile)
CONFIGURE_ARGS+=	--with-fileio=sndfile
.  include "../../audio/libsndfile/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Municode)
CFLAGS+=		-DHAVE_ICONV
.  include "../../converters/libiconv/buildlink3.mk"
.endif

# doesn't work
#.if !empty(PKG_OPTIONS:Mvorbis)
#CONFIGURE_ARGS+=	--with-vorbis
#CONFIGURE_ARGS+=	--with-vorbis-prefix=${BUILDLINK_PREFIX.libvorbis}
#.  include "../../audio/libvorbis/buildlink3.mk"
#.else
#CONFIGURE_ARGS+=	--without-vorbis
#.endif
