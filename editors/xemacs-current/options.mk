# $NetBSD: options.mk,v 1.11 2008/04/24 21:32:47 jlam Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.xemacs
PKG_SUPPORTED_OPTIONS=		ldap xface canna debug x11 xft
#PKG_SUPPORTED_OPTIONS+=	esound
PKG_OPTIONS_OPTIONAL_GROUPS=	toolkit
PKG_OPTIONS_GROUP.toolkit=	gtk lucid motif
PKG_OPTIONS_LEGACY_OPTS=	xaw:lucid
PKG_SUGGESTED_OPTIONS=		x11

.include "../../mk/bsd.options.mk"

###
### Any of the "toolkit" options or "xft" implies "x11".
###
.if !empty(PKG_OPTIONS:Mgtk) || !empty(PKG_OPTIONS:Mlucid) || \
    !empty(PKG_OPTIONS:Mmotif) || !empty(PKG_OPTIONS:Mxft)
.  if empty(PKG_OPTIONS:Mx11)
PKG_OPTIONS+=		x11
.  endif
.endif

###
### Default to using the Lucid X11 toolkit if none is specified.
###
.if !empty(PKG_OPTIONS:Mx11)
.  if empty(PKG_OPTIONS:Mgtk) && empty(PKG_OPTIONS:Mlucid) && \
      empty(PKG_OPTIONS:Mmotif)
PKG_OPTIONS+=		lucid
.  endif
.endif

PLIST_VARS+=		ldap
.if !empty(PKG_OPTIONS:Mldap)
PLIST.ldap=		yes
CONFIGURE_ARGS+=	--with-ldap
.  include "../../databases/openldap-client/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-ldap
.endif

.if !empty(PKG_OPTIONS:Mxface)
CONFIGURE_ARGS+=	--with-xface
.  include "../../mail/faces/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-xface
.endif

.if !empty(PKG_OPTIONS:Mcanna)
.  include "../../inputmethod/canna-lib/buildlink3.mk"
CONFIGURE_ARGS+=	--with-canna
.else
CONFIGURE_ARGS+=	--without-canna
.endif

.if !empty(PKG_OPTIONS:Mesound)
.  include "../../audio/esound/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--with-sound=none
.endif

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug=yes --with-debug
.endif

###
### Support drawing pretty X11 widgets.
###
.if !empty(PKG_OPTIONS:Mx11)
.  include "../../graphics/jpeg/buildlink3.mk"
.  include "../../graphics/png/buildlink3.mk"
.  include "../../graphics/tiff/buildlink3.mk"
.  include "../../x11/xbitmaps/buildlink3.mk"
CONFIGURE_ARGS+=	--with-x
.  if ${X11_TYPE} != "modular"
CONFIGURE_ARGS+=	--with-site-prefixes=${PREFIX}:${X11BASE}
CONFIGURE_ARGS+=	--with-site-runtime-libraries=${PREFIX}/lib:${X11BASE}/lib
.  else
CONFIGURE_ARGS+=	--with-site-prefixes=${PREFIX}
CONFIGURE_ARGS+=	--with-site-runtime-libraries=${PREFIX}/lib
.  endif
.else
CONFIGURE_ARGS+=	--without-x
CONFIGURE_ARGS+=	--without-jpeg
CONFIGURE_ARGS+=	--without-png
CONFIGURE_ARGS+=	--without-tiff
CONFIGURE_ARGS+=	--without-xpm
CONFIGURE_ARGS+=	--with-site-prefixes=${PREFIX}
CONFIGURE_ARGS+=	--with-site-runtime-libraries=${PREFIX}/lib
.endif

###
### Support using Xft for rendering TrueType fonts.
###
.if !empty(PKG_OPTIONS:Mxft)
.  include "../../fonts/fontconfig/buildlink3.mk"
.  include "../../graphics/freetype2/buildlink3.mk"
.  include "../../x11/libXft/buildlink3.mk"
.  include "../../x11/libXrender/buildlink3.mk"
CONFIGURE_ARGS+=	--with-xft=emacs,tabs,menubars,gauges
.endif

###
### Support using GTK X11 widgets.
###
.if !empty(PKG_OPTIONS:Mgtk)
.  include "../../x11/gtk/buildlink3.mk"
CONFIGURE_ARGS+=	--with-gtk
.endif

###
### Support using Motif X11 widgets.
###
.if !empty(PKG_OPTIONS:Mmotif)
.  include "../../mk/motif.buildlink3.mk"
.endif

###
### Support using Lucid X11 widgets.
###
.if !empty(PKG_OPTIONS:Mlucid)
.  include "../../mk/xaw.buildlink3.mk"
CONFIGURE_ARGS+=	--with-widgets=lucid
.endif
