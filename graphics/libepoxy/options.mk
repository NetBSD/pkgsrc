# $NetBSD: options.mk,v 1.3 2020/01/01 21:16:12 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libepoxy
PKG_SUPPORTED_OPTIONS=	x11
PKG_SUGGESTED_OPTIONS=	x11

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	glx

.if !empty(PKG_OPTIONS:Mx11)
MESON_ARGS+=	-Dglx=yes
MESON_ARGS+=	-Dx11=true
PLIST.glx=	yes
.include "../../x11/libX11/buildlink3.mk"
.  if ${OPSYS} == "Darwin" && ${X11_TYPE} == "modular"
CPPFLAGS+=	-DGLX_LIB=\"${PREFIX}/lib/libGL.dylib\"
.  endif
.else # ! x11
.  if !empty(MESALIB_SUPPORTS_EGL:M[Yy][Ee][Ss])
MESON_ARGS+=	-Dglx=no
MESON_ARGS+=	-Dx11=false
.  elif ${OPSYS} != "Darwin"
PKG_FAIL_REASON+=	"The x11 option must be enabled on this platform/configuration."
.  endif
.endif
