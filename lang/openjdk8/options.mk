# $NetBSD: options.mk,v 1.3 2015/03/04 17:01:02 tnn Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.openjdk8
PKG_OPTIONS_OPTIONAL_GROUPS=	variant
PKG_OPTIONS_GROUP.variant=	jdk-zero-vm
PKG_SUPPORTED_OPTIONS=		debug jre-jce x11
PKG_SUGGESTED_OPTIONS=		jre-jce x11

.if !empty(PKGSRC_COMPILER:Mclang)
PKG_OPTIONS_GROUP.variant+=	jdk-zeroshark-vm
.endif

.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
PKG_OPTIONS_GROUP.variant+=	jdk-hotspot-vm
PKG_SUGGESTED_OPTIONS+=		jdk-hotspot-vm
#notyet
#.elif !empty(PKGSRC_COMPILER:Mclang)
#PKG_SUGGESTED_OPTIONS+		jdk-zeroshark-vm
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
CONFIGURE_ARGS+=	--with-x=yes
CONFIGURE_ARGS+=	--x-includes=${X11BASE}/include
CONFIGURE_ARGS+=	--x-libraries=${X11BASE}/lib
CONFIGURE_ARGS+=	--enable-headful
DEPENDS+=		dejavu-ttf-[0-9]*:../../fonts/dejavu-ttf
#DEPENDS+=		ja-sazanami-ttf-[0-9]*:../../fonts/ja-sazanami-ttf
#DEPENDS+=		baekmuk-ttf-[0-9]*:../../fonts/baekmuk-ttf
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
BUILDLINK_DEPMETHOD.libXp?=	build
.include "../../x11/libXp/buildlink3.mk"
BUILDLINK_DEPMETHOD.libXt?=	build
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.else
MAKE_ENV+=		BUILD_HEADLESS_ONLY=true
CONFIGURE_ARGS+=	--without-x
CONFIGURE_ARGS+=	--disable-headful
# We apparently still need the Xlib headers to build headless. why?
BUILDLINK_DEPMETHOD.libX11?=	build
.include "../../x11/libX11/buildlink3.mk"
BUILDLINK_DEPMETHOD.libXt?=	build
.include "../../x11/libXt/buildlink3.mk"
BUILDLINK_DEPMETHOD.libXrender?=build
.include "../../x11/libXrender/buildlink3.mk"
post-configure: remove-x11-classes
remove-x11-classes:
	rm ${WRKSRC}/jdk/src/solaris/classes/sun/awt/X11/*.java
.endif

#
# Debugging
#
.if !empty(PKG_OPTIONS:Mdebug)
BUILD_DEBUG_LEVEL=	fastdebug
CONFIGURE_ARGS+=	--enable-debug-symbols
CONFIGURE_ARGS+=	--disable-zip-debug-info
CONFIGURE_ARGS+=	--disable-precompiled-headers
PLIST_SRC+=		PLIST.debug
.else
BUILD_DEBUG_LEVEL=	release
CONFIGURE_ARGS+=	--disable-debug-symbols
.endif
CONFIGURE_ARGS+=	--with-debug-level=${BUILD_DEBUG_LEVEL}

#
# Build variant. Zero VM builds a portable JVM without assembly optimization.
#
PLIST_VARS+=		native
.if !empty(PKG_OPTIONS:Mjdk-zero-vm)
BUILD_VARIANT=		zero
.include "../../devel/libffi/buildlink3.mk"
.elif !empty(PKG_OPTIONS:Mjdk-zeroshark-vm)
BUILD_VARIANT=		zeroshark
.include "../../devel/libffi/buildlink3.mk"
.include "../../lang/libLLVM/buildlink3.mk"
CONFIGURE_ENV+=		LLVM_CONFIG=${LLVM_CONFIG_PATH}
.else
BUILD_VARIANT=		server
PLIST.native=		yes
.endif
CONFIGURE_ARGS+=	--with-jvm-variants=${BUILD_VARIANT}
