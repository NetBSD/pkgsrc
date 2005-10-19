# $NetBSD: options.mk,v 1.1 2005/10/19 09:45:09 xtraeme Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.streamtuner
PKG_SUPPORTED_OPTIONS=	streamtuner-local streamtuner-xiph python
PKG_SUGGESTED_OPTIONS=	streamtuner-local streamtuner-xiph

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mstreamtuner-local)
PLIST_SUBST+=		LOCAL_PLUGIN=
CONFIGURE_ARGS+=	--enable-local
.  include "../../audio/taglib/buildlink3.mk"
.else
PLIST_SUBST+=		LOCAL_PLUGIN='@comment '
CONFIGURE_ARGS+=	--disable-local
.endif

.if !empty(PKG_OPTIONS:Mstreamtuner-xiph)
PLIST_SUBST+=		XIPH_PLUGIN=
CONFIGURE_ARGS+=	--enable-xiph
.  include "../../textproc/libxml2/buildlink3.mk"
.else
PLIST_SUBST+=		XIPH_PLUGIN='@comment '
CONFIGURE_ARGS+=	--disable-xiph
.endif

.if !empty(PKG_OPTIONS:Mpython)
PLIST_SUBST+=		PYTHON_PLUGIN=
CONFIGURE_ARGS+=	--enable-python
.  include "../../x11/py-gtk2/buildlink3.mk"
.else
PLIST_SUBST+=		PYTHON_PLUGIN='@comment '
CONFIGURE_ARGS+=	--disable-python
.endif
