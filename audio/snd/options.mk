# $NetBSD: options.mk,v 1.7 2016/09/15 17:02:24 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.snd
PKG_SUPPORTED_OPTIONS=
# ruby, forth, alsa, oss, jack, pulseaudio, gmp, ladspa
PKG_OPTIONS_REQUIRED_GROUPS=	frontend
PKG_OPTIONS_GROUP.frontend=	gtk motif
PKG_SUGGESTED_OPTIONS=	gtk

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgtk)
CONFIGURE_ARGS+=	--with-gtk
.include "../../x11/gtk2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-gtk
.endif

.if !empty(PKG_OPTIONS:Mmotif)
CONFIGURE_ARGS+=	--with-motif
.include "../../mk/motif.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-motif
.endif
