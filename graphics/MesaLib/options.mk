# $NetBSD: options.mk,v 1.22 2013/05/20 07:04:35 sbd Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.MesaLib
PKG_SUPPORTED_OPTIONS=

# Assembler code build configurations
.if (${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64") && \
    ${OPSYS} != "Darwin"
#PKG_SUPPORTED_OPTIONS+=		${MACHINE_ARCH}
#PKG_SUGGESTED_OPTIONS+=		${MACHINE_ARCH}
.endif
###
### XXX  There are [probably] others, but let's not get crazy just yet.
### 	 This will take a while to test for the myriad platforms we
### 	 support.
###
.if (${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64" || \
     ${MACHINE_ARCH} == "powerpc" || ${MACHINE_ARCH} == "sparc" || \
     ${MACHINE_ARCH} == "sparc64") && \
    ((${OPSYS} == "NetBSD" && ${X11_TYPE} == "modular") || \
     ${OPSYS} == "FreeBSD" || ${OPSYS} == "OpenBSD" || \
     ${OPSYS} == "DragonFly" || ${OPSYS} == "Linux" || \
     ${OPSYS} == "SunOS")
PKG_SUPPORTED_OPTIONS+=		dri
.endif
###
### XXX OpenGL still works fine with the software fallback.  As of now,
###	I think this is a good way to see which bugs surface before the
###	next release branch.  Upgrading the X server to the 1.4 branch
###	is advised given that it's glx/glcore modules are built from
###	Mesa 6.5.3 (a development release).
###
.if !empty(MACHINE_PLATFORM:MNetBSD-[4-9]*-*86*) && ${X11_TYPE} == "modular"
PKG_SUGGESTED_OPTIONS+=		dri
.endif
.if !empty(MACHINE_PLATFORM:MLinux-*-*86*) && ${X11_TYPE} == "modular"
PKG_SUGGESTED_OPTIONS+=		dri
.endif

.if ${OPSYS} == "DragonFly" || (${OPSYS} == "SunOS" && ${OS_VERSION} == "5.11")
PKG_SUGGESTED_OPTIONS+=		dri
.endif

.include "../../mk/bsd.options.mk"
###
### XXX Yes, this is a bit overly verbose; with Mesa, that can't hurt much.
###	NOTE: there is no assembler code built with libOSMesa.
#.if (!empty(PKG_OPTIONS:Mi386) || !empty(PKG_OPTIONS:Mx86_64)) && \
#     !empty(PKG_OPTIONS:Mdri)
#BUILD_TARGET_SUFFIX=	-${MACHINE_ARCH}
#.else
#BUILD_TARGET_SUFFIX=	# empty
#.endif

.if !empty(PKG_OPTIONS:Mdri)
CONFIGURE_ARGS+=        --with-driver=dri
PLIST.dri=	yes
BUILDLINK_API_DEPENDS.libdrm+= libdrm>=2.4.9
.  include "../../sysutils/libpciaccess/buildlink3.mk"
.  include "../../graphics/MesaLib/dri.mk"
CONFIGURE_ARGS+=        --with-dri-drivers="i810 i915 i965 mach64 mga r128 r200 r300 r600 radeon savage sis swrast tdfx unichrome"
.else
CONFIGURE_ARGS+=        --with-driver=xlib
PLIST.nodri=	yes
###
### XXX building libOSMesa breaks with -j, and GNU make has no .WAIT
###
#MAKE_JOBS_SAFE=			no
.endif
