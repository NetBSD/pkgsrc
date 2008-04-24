# $NetBSD: options.mk,v 1.8 2008/04/24 15:32:15 jlam Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.xemacs
PKG_SUPPORTED_OPTIONS=		ldap xface canna x11
PKG_OPTIONS_OPTIONAL_GROUPS=	toolkit
PKG_OPTIONS_GROUP.toolkit=	lucid

# GUI configuration is a mess... only support "lucid" for now.
#PKG_OPTIONS_GROUP.toolkit+=	gtk motif xaw
#PKG_OPTIONS_LEGACY_VARS+=	USE_ATHENA:xaw
#PKG_OPTIONS_LEGACY_VARS+=	USE_GTK:gtk
#PKG_OPTIONS_LEGACY_VARS+=	USE_MOTIF:motif

PKG_SUGGESTED_OPTIONS=		x11

.include "../../mk/bsd.options.mk"

###
### Any of the "toolkit" options implies "x11".
###
.if !empty(PKG_OPTIONS:Mgtk) || !empty(PKG_OPTIONS:Mlucid) || \
    !empty(PKG_OPTIONS:Mmotif) || !empty(PKG_OPTIONS:Mxaw)
.  if empty(PKG_OPTIONS:Mx11)
PKG_OPTIONS+=		x11
.  endif
.endif

###
### Default to using the Lucid X11 toolkit if none is specified.
###
.if !empty(PKG_OPTIONS:Mx11)
.  if empty(PKG_OPTIONS:Mgtk) && empty(PKG_OPTIONS:Mlucid) && \
      empty(PKG_OPTIONS:Mmotif) && empty(PKG_OPTIONS:Mxaw)
PKG_OPTIONS+=		lucid
.  endif
.endif

.if !empty(PKG_OPTIONS:Mldap)
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

PLIST_VARS+=		canna
.if !empty(PKG_OPTIONS:Mcanna)
.  include "../../inputmethod/canna-lib/buildlink3.mk"
CONFIGURE_ARGS+=	--with-canna
PLIST.canna=		yes
.else
CONFIGURE_ARGS+=	--without-canna
.endif

###
### Support drawing pretty X11 widgets.
###
PLIST_VARS+=		x11
.if !empty(PKG_OPTIONS:Mx11)
.  include "../../graphics/jpeg/buildlink3.mk"
.  include "../../graphics/png/buildlink3.mk"
.  include "../../graphics/tiff/buildlink3.mk"
.  include "../../x11/libXpm/buildlink3.mk"
.  include "../../x11/xbitmaps/buildlink3.mk"
PLIST.x11=		yes
CONFIGURE_ARGS+=	--with-x
CONFIGURE_ARGS+=	--with-jpeg
CONFIGURE_ARGS+=	--with-png
CONFIGURE_ARGS+=	--with-tiff
CONFIGURE_ARGS+=	--with-xpm
CONFIGURE_ARGS+=	--site-includes=${SITE_INCLUDES:Q}
CONFIGURE_ARGS+=	--site-libraries=${SITE_LIBRARIES:Q}
CONFIGURE_ARGS+=	--site-runtime-libraries=${SITE_RUNTIME_LIBRARIES:Q}
.  if ${X11_TYPE} != "modular"
SITE_INCLUDES=		${BUILDLINK_DIR}/include:${BUILDLINK_X11_DIR}/include
SITE_LIBRARIES=		${BUILDLINK_DIR}/lib:${BUILDLINK_X11_DIR}/lib
SITE_RUNTIME_LIBRARIES=	${PREFIX}/lib:${X11BASE}/lib
.  else
SITE_INCLUDES=		${BUILDLINK_DIR}/include
SITE_LIBRARIES=		${BUILDLINK_DIR}/lib
SITE_RUNTIME_LIBRARIES=	${PREFIX}/lib
.  endif
.else
CONFIGURE_ARGS+=	--without-x
CONFIGURE_ARGS+=	--without-jpeg
CONFIGURE_ARGS+=	--without-png
CONFIGURE_ARGS+=	--without-tiff
CONFIGURE_ARGS+=	--without-xpm
CONFIGURE_ARGS+=	--site-includes=${SITE_INCLUDES:Q}
CONFIGURE_ARGS+=	--site-libraries=${SITE_LIBRARIES:Q}
CONFIGURE_ARGS+=	--site-runtime-libraries=${SITE_RUNTIME_LIBRARIES:Q}
SITE_INCLUDES=		${BUILDLINK_DIR}/include
SITE_LIBRARIES=		${BUILDLINK_DIR}/lib
SITE_RUNTIME_LIBRARIES=	${PREFIX}/lib
.endif

###
### Support using GTK X11 widgets.
###
.if !empty(PKG_OPTIONS:Mgtk)
.  include "../../x11/gtk/buildlink3.mk"
CONFIGURE_ARGS+=	--with-gtk
CONFIGURE_ARGS+=	--with-menubars=yes
CONFIGURE_ARGS+=	--with-scrollbars=yes
CONFIGURE_ARGS+=	--with-dialogs=yes
CONFIGURE_ARGS+=	--with-widgets=yes
CONFIGURE_ARGS+=	--with-xim=yes
.endif

###
### Support using Lucid X11 widgets.
###
.if !empty(PKG_OPTIONS:Mlucid)
.  include "../../mk/xaw.buildlink3.mk"
CONFIGURE_ARGS+=	--with-toolbars=yes
CONFIGURE_ARGS+=	--with-menubars=yes
CONFIGURE_ARGS+=	--with-scrollbars=lucid
CONFIGURE_ARGS+=	--with-dialogs=lucid
CONFIGURE_ARGS+=	--with-widgets=lucid
CONFIGURE_ARGS+=	--with-athena=xaw
CONFIGURE_ARGS+=	--with-xim=xlib
.endif

###
### Support using Motif X11 widgets.
###
.if !empty(PKG_OPTIONS:Mmotif)
.  include "../../mk/motif.buildlink3.mk"
CONFIGURE_ARGS+=	--with-menubars=motif
CONFIGURE_ARGS+=	--with-scrollbars=motif
CONFIGURE_ARGS+=	--with-dialogs=motif
CONFIGURE_ARGS+=	--with-widgets=motif
CONFIGURE_ARGS+=	--with-xim=motif
.endif

###
### Support using Athena X11 widgets.
###
.if !empty(PKG_OPTIONS:Mxaw)
.  include "../../mk/xaw.buildlink3.mk"
CONFIGURE_ARGS+=	--with-menubars=athena
CONFIGURE_ARGS+=	--with-scrollbars=athena
CONFIGURE_ARGS+=	--with-dialogs=athena
CONFIGURE_ARGS+=	--with-widgets=athena
CONFIGURE_ARGS+=	--with-athena=xaw
CONFIGURE_ARGS+=	--with-xim=xlib
.endif
