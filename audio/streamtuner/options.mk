# $NetBSD: options.mk,v 1.4 2014/05/09 07:36:55 wiz Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.streamtuner
PKG_SUPPORTED_OPTIONS=	streamtuner-local streamtuner-xiph python
PKG_SUGGESTED_OPTIONS=	streamtuner-local streamtuner-xiph

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		local python xiph

.if !empty(PKG_OPTIONS:Mstreamtuner-local)
PLIST.local=		yes
CONFIGURE_ARGS+=	--enable-local
.  include "../../audio/taglib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-local
.endif

.if !empty(PKG_OPTIONS:Mstreamtuner-xiph)
PLIST.xiph=		yes
CONFIGURE_ARGS+=	--enable-xiph
.  include "../../textproc/libxml2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-xiph
.endif

.if !empty(PKG_OPTIONS:Mpython)
PLIST.python=		yes
CONFIGURE_ARGS+=	--enable-python
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-gtk2
.  include "../../x11/py-gtk2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-python
.endif
