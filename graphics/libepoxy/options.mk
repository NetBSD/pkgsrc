# $NetBSD: options.mk,v 1.1 2017/06/08 04:31:34 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libepoxy
PKG_SUPPORTED_OPTIONS=	x11
PKG_SUGGESTED_OPTIONS=	x11

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		egl glx

.if !empty(PKG_OPTIONS:Mx11)
CONFIGURE_ARGS+=	--enable-glx=yes
PLIST.glx=	yes
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"

CONFIGURE_ARGS+=	--enable-egl=${MESALIB_SUPPORTS_EGL}
.  if !empty(MESALIB_SUPPORTS_EGL:Myes)
PLIST.egl=		yes
.  endif
.  if ${OPSYS} == "Darwin" && ${X11_TYPE} == "modular"
CPPFLAGS+=		-DGLX_LIB=\"${PREFIX}/lib/libGL.dylib\"
.  endif
.else # ! x11
CONFIGURE_ARGS+=	--enable-glx=no
CONFIGURE_ARGS+=	--enable-egl=no
.  if !(${OPSYS} == "Darwin" && ${X11_TYPE} == "native")
PKG_FAIL_REASON+=	"The x11 option must be enabled on this platform/configuration."
.  endif
.endif
