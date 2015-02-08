# $NetBSD: options.mk,v 1.7 2015/02/08 23:40:09 tnn Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.openjdk7
PKG_SUPPORTED_OPTIONS=		debug jre-jce jdk-zero-vm x11
PKG_SUGGESTED_OPTIONS=		jre-jce x11
.if ${MACHINE_ARCH} != "i386" && ${MACHINE_ARCH} != "x86_64"
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
.if !empty(PKG_OPTIONS:Mjdk-zero-vm)
MAKE_ENV+=		ZERO_BUILD=true
 # valid are i386 / amd64 / sparc* / ppc32 / ppc64
MAKE_ENV+=		ZERO_LIBARCH=${MACHINE_ARCH:S/x86_64/amd64/}
 # valid are IA32 / AMD64 / SPARC / PPC32 / PPC64
MAKE_ENV+=		ZERO_ARCHDEF=${MACHINE_ARCH:S/i386/IA32/:S/x86_64/AMD64/}
.include "../../mk/endian.mk"
MAKE_ENV+=		ZERO_ENDIANNESS=${MACHINE_ENDIAN}
.include "../../devel/libffi/buildlink3.mk"
.else
PLIST.native=		yes
.endif
