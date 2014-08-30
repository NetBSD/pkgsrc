# $NetBSD: options.mk,v 1.16 2014/08/30 11:20:38 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.pango
PKG_SUPPORTED_OPTIONS=	libthai quartz x11
PKG_SUGGESTED_OPTIONS=	x11

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		coretext quartz x11 thai

###
### X11 support
###
.if !empty(PKG_OPTIONS:Mx11)
# fix for pangox.pc
CONFIGURE_ENV+=		X_EXTRA_LIBS=${COMPILER_RPATH_FLAG}${X11BASE}/lib
PLIST.x11=		yes
BUILDLINK_API_DEPENDS.Xft2+=	Xft2>=2.1.7nb3
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
BUILDLINK_DEPMETHOD.libXt?=	build # only for configure
.include "../../x11/libXt/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-x
CONFIGURE_ARGS+=	--without-xft
.endif

###
### Thai language support
###
.if !empty(PKG_OPTIONS:Mlibthai)
PLIST.thai=		yes
.include "../../devel/libthai/buildlink3.mk"
.endif

.include "../../mk/bsd.prefs.mk"

###
### Quartz "support"
###
.if ${OPSYS} == "Darwin"
### always looks for system CoreText
.  if empty(MACHINE_PLATFORM:MDarwin-[1-8].*-*)
### CoreText is only available in 10.5 or newer
PLIST.coretext=		yes
.  endif
.  if !empty(PKG_OPTIONS:Mquartz)
### installs its coretext header file if cairo was built with "quartz" option
PLIST.quartz=		yes
.  endif
.endif
