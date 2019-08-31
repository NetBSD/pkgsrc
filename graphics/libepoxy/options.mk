# $NetBSD: options.mk,v 1.2 2019/08/31 13:50:09 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libepoxy
PKG_SUPPORTED_OPTIONS=	x11
PKG_SUGGESTED_OPTIONS=	x11

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		glx

.if !empty(PKG_OPTIONS:Mx11)
CONFIGURE_ARGS+=	--enable-glx=yes
CONFIGURE_ARGS+=	--enable-x11=yes
PLIST.glx=	yes
.include "../../x11/libX11/buildlink3.mk"
.  if ${OPSYS} == "Darwin" && ${X11_TYPE} == "modular"
CPPFLAGS+=		-DGLX_LIB=\"${PREFIX}/lib/libGL.dylib\"
.  endif
.else # ! x11
.  if !empty(MESALIB_SUPPORTS_EGL:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--enable-glx=no
CONFIGURE_ARGS+=	--enable-x11=no
.  else
PKG_FAIL_REASON+=	"The x11 option must be enabled on this platform/configuration."
.  endif
.endif
