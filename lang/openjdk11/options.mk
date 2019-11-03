# $NetBSD: options.mk,v 1.2 2019/11/03 19:04:04 rillig Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.openjdk11
PKG_OPTIONS_OPTIONAL_GROUPS=	variant
PKG_OPTIONS_GROUP.variant=	jdk-zero-vm
PKG_SUPPORTED_OPTIONS=		debug dtrace jre-jce x11 static-libstdcpp
PKG_SUGGESTED_OPTIONS=		jre-jce x11

.if !empty(PKGSRC_COMPILER:Mclang)
PKG_OPTIONS_GROUP.variant+=	jdk-zeroshark-vm
.endif

.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
PKG_OPTIONS_GROUP.variant+=	jdk-hotspot-vm
PKG_SUGGESTED_OPTIONS+=		jdk-hotspot-vm
.else
PKG_SUGGESTED_OPTIONS+=		jdk-zero-vm
.endif

.include "../../mk/bsd.options.mk"

###
### Java(TM) Cryptography Extension (JCE)
###
.if !empty(PKG_OPTIONS:Mjre-jce)
CONFIGURE_ARGS+=	--enable-unlimited-crypto
.else
CONFIGURE_ARGS+=	--disable-unlimited-crypto
.endif

###
### X11 or headless build
###
PLIST_VARS+=	x11
.if !empty(PKG_OPTIONS:Mx11)
PLIST.x11=	yes
CONFIGURE_ARGS+=	--x-includes=${X11BASE}/include
CONFIGURE_ARGS+=	--x-libraries=${X11BASE}/lib
CONFIGURE_ARGS+=	--disable-headless-only
DEPENDS+=		dejavu-ttf-[0-9]*:../../fonts/dejavu-ttf
#DEPENDS+=		ja-sazanami-ttf-[0-9]*:../../fonts/ja-sazanami-ttf
#DEPENDS+=		baekmuk-ttf-[0-9]*:../../fonts/baekmuk-ttf
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
BUILDLINK_DEPMETHOD.libXt?=	build
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--enable-headless-only
# We apparently still need the Xlib headers to build headless. why?
BUILDLINK_DEPMETHOD.libX11?=	build
.include "../../x11/libX11/buildlink3.mk"
BUILDLINK_DEPMETHOD.libXext?=build
.include "../../x11/libXext/buildlink3.mk"
BUILDLINK_DEPMETHOD.libXt?=	build
.include "../../x11/libXt/buildlink3.mk"
BUILDLINK_DEPMETHOD.libXrender?=build
.include "../../x11/libXrender/buildlink3.mk"
BUILDLINK_DEPMETHOD.libXtst?=build
.include "../../x11/libXtst/buildlink3.mk"
BUILDLINK_DEPMETHOD.libXrandr?=build
.include "../../x11/libXrandr/buildlink3.mk"
.endif

#
# Debugging
#
.if !empty(PKG_OPTIONS:Mdebug)
BUILD_DEBUG_LEVEL=	fastdebug
CONFIGURE_ARGS+=	--with-native-debug-symbols=external
CONFIGURE_ARGS+=	--enable-debug
PLIST_SUBST+=		DBGEXT=.debuginfo
.else
BUILD_DEBUG_LEVEL=	release
CONFIGURE_ARGS+=	--with-native-debug-symbols=zipped
PLIST_SUBST+=		DBGEXT=.diz
.endif

.if !empty(PKG_OPTIONS:Mdtrace)
CONFIGURE_ARGS+=	--enable-dtrace=yes
.else
CONFIGURE_ARGS+=	--enable-dtrace=no
.endif

#
# static libstdc++ and libgcc
#
# On NetBSD you need to use libstdc++_pic.a when creating a shared library,
# but I don't think there is any easy way to tell the compiler to do this.
# Also, -static-libgcc doesn't work because libpthread needs dynamic
# linkage of libgcc.
.if !empty(PKG_OPTIONS:Mstatic-libstdcpp)
.  if ${OPSYS} == "NetBSD" && !empty(PKGSRC_COMPILER:Mgcc)
BUILDLINK_TRANSFORM+=	rm:-static-libgcc
.  endif
.else
CONFIGURE_ARGS+=	--with-stdc++lib=dynamic
.endif

#
# Build variant. Zero VM builds a portable JVM without assembly optimization.
#
.if !empty(PKG_OPTIONS:Mjdk-zero-vm)
BUILD_VARIANT=		zero
.include "../../devel/libffi/buildlink3.mk"
.elif !empty(PKG_OPTIONS:Mjdk-zeroshark-vm)
BUILD_VARIANT=		zeroshark
.include "../../devel/libffi/buildlink3.mk"
.include "../../lang/libLLVM/buildlink3.mk"
CONFIGURE_ENV+=		LLVM_CONFIG=${LLVM_CONFIG_PATH}
.elif !empty(PKG_OPTIONS:Mjdk-hotspot-vm)
BUILD_VARIANT=		server
.endif
CONFIGURE_ARGS+=	--with-jvm-variants=${BUILD_VARIANT}
