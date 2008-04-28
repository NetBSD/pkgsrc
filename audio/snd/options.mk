# $NetBSD: options.mk,v 1.2 2008/04/28 12:47:44 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.snd
PKG_SUPPORTED_OPTIONS=	esound guile
# fftw2 fftw3 ladspa gamin/fam mpg123 timidity
PKG_OPTIONS_REQUIRED_GROUPS=	frontend
PKG_OPTIONS_GROUP.frontend=	gtk motif
PKG_SUGGESTED_OPTIONS=	gtk guile

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mesound)
CONFIGURE_ARGS+=	--with-esd
.include "../../audio/esound/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-esd
.endif

.if !empty(PKG_OPTIONS:Mgtk)
CONFIGURE_ARGS+=	--with-gtk
.include "../../x11/gtk2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-gtk
.endif

.if !empty(PKG_OPTIONS:Mguile)
CONFIGURE_ARGS+=	--with-guile
.include "../../lang/guile/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-guile
.endif

.if !empty(PKG_OPTIONS:Mmotif)
CONFIGURE_ARGS+=	--with-motif
.include "../../x11/openmotif/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-motif
.endif
