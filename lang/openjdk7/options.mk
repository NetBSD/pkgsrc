# $NetBSD: options.mk,v 1.11 2015/03/04 17:01:02 tnn Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.openjdk7
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
#PKG_SUGGESTED_OPTIONS+=	jdk-zeroshark-vm
.else
PKG_SUGGESTED_OPTIONS+=		jdk-zero-vm
.endif

.include "../../mk/bsd.options.mk"

###
### Java(TM) Cryptography Extension (JCE)
###
.if !empty(PKG_OPTIONS:Mjre-jce)
MAKE_ENV+=	UNLIMITED_CRYPTO=true
.endif

###
### X11 or headless build
###
PLIST_VARS+=		x11
.if !empty(PKG_OPTIONS:Mx11)
PLIST.x11=		yes
MAKE_ENV+=		ALT_X11_PATH=${X11BASE}
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
# We apparently still need the Xlib headers to build headless. why?
MAKE_ENV+=		ALT_X11_PATH=${X11BASE}
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
PKG_FAIL_REASON+=	"The fastdebug build is currently broken due to a linker error"
PLIST_SRC+=		PLIST.debug
JDK_MAKE_TARGET=	fastdebug_build
MAKE_ENV+=		FULL_DEBUG_SYMBOLS=1
MAKE_ENV+=		ZIP_DEBUGINFO_FILES=0
MAKE_ENV+=		USE_PRECOMPILED_HEADER=0
.else
JDK_MAKE_TARGET=	all
MAKE_ENV+=		FULL_DEBUG_SYMBOLS=0
.endif

#
# Build variant. Zero VM builds a portable JVM without assembly optimization.
#
PLIST_VARS+=		native
.if !empty(PKG_OPTIONS:Mjdk-zero-vm) || !empty(PKG_OPTIONS:Mjdk-zeroshark-vm)
MAKE_ENV+=		ZERO_BUILD=true
MAKE_ENV+=		ZERO_LIBARCH=${MACHINE_ARCH:S/x86_64/amd64/:S/sparc64/sparcv9/:C/^e?arm.*$/arm/}
MAKE_ENV+=		ZERO_ARCHDEF=${MACHINE_ARCH:S/i386/IA32/:S/x86_64/AMD64/:S/sparc64/SPARC/:C/^e?arm.*$/ARM/}
.include "../../mk/endian.mk"
MAKE_ENV+=		ZERO_ENDIANNESS=${MACHINE_ENDIAN}
.include "../../devel/libffi/buildlink3.mk"
.else
PLIST.native=		yes
.endif
.if !empty(PKG_OPTIONS:Mjdk-zeroshark-vm)
MAKE_ENV+=		SHARK_BUILD=true
.include "../../lang/libLLVM/buildlink3.mk"
.endif
