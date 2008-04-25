# $NetBSD: options.mk,v 1.2 2008/04/25 20:33:08 bjs Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.MesaLib
PKG_SUPPORTED_OPTIONS=	mesa-execmem-mmap

# Assembler code build configurations
.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
PKG_SUPPORTED_OPTIONS+=		${MACHINE_ARCH}
PKG_SUGGESTED_OPTIONS+=		${MACHINE_ARCH}
.endif
###
### XXX Prior to this patch, Mesa only allocated executable memory
###	with mmap(2) and PROT_EXEC on linux.  On e.g. OpenBSD and NetBSD,
###	pages which absolutely required PROT_EXEC were allocated using
###	malloc(3).  You may wonder why it only worked on Linux.  Answer:
###	the code was excluded with '#ifdef __linux__'!  "Porting" this
###	[to BSD platforms] involved adding three lines of [preprocessor]
###	code (see patch-ap if you're curious).
###
###	Please do note hack (NetBSD-only for now) I added to wire down
###	this memory by setting the MESA_EXECMEM_MMAP environment variable;
###	you probably don't want it paged out.  MAP_WIRED is probably
###	overkill--I will revisit this at a later date.
###
###	You may also define MESA_EXECMEM_HEAP_SIZE in your build
###	environment to adjust the size of the anonymous executable
###	memory pool (in bytes).  The default is 10MB (huge?).
###
###	Here's the bottom line:  IF YOUR PLATFORM DOES NOT HAVE AN
###	EXECUTABLE HEAP, YOU RUN THE RISK OF MANY SEGMENTATION FAULTS
###	UNLESS THIS OPTION IS ENABLED.  If enabling this option results in
###	build failure, please do file a PR.  Thanks to Owain Ainsworth
###	<oga@openbsd.org> for discovering this.
###
###	--bjs (04/23/08)
###
.if (!empty(OPSYS:M*BSD) || ${OPSYS} == "DragonFly" || ${OPSYS} == "Linux")
PKG_SUGGESTED_OPTIONS=	mesa-execmem-mmap
.endif
###
### XXX  There are [probably] others, but let's not get crazy just yet.
### 	 This will take a while to test for the myriad platforms we
### 	 support.
###
.if (${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64" || \
     ${MACHINE_ARCH} == "powerpc" || ${MACHINE_ARCH} == "sparc" || \
     ${MACHINE_ARCH} == "sparc64") && \
    (${OPSYS} == "NetBSD" || ${OPSYS} == "FreeBSD" || ${OPSYS} == "OpenBSD")
PKG_SUPPORTED_OPTIONS+=		dri
.endif
###
### XXX OpenGL still works fine with the software fallback.  As of now,
###	I think this is a good way to see which bugs surface before the
###	next release branch.  Upgrading the X server to the 1.4 branch
###	is advised given that it's glx/glcore modules are built from
###	Mesa 6.5.3 (a development release). 
###
.if !empty(MACHINE_PLATFORM:MNetBSD-[4-9]*-[ix]86*)
PKG_SUGGESTED_OPTIONS+=		dri
.endif

.include "../../mk/bsd.options.mk"
###
### XXX Yes, this is a bit overly verbose; with Mesa, that can't hurt much.
###
.if !empty(PKG_OPTIONS:Mi386) || !empty(PKG_OPTIONS:Mx86_64)
BUILD_TARGET_SUFFIX=	-${MACHINE_ARCH}
.else
BUILD_TARGET_SUFFIX=	# empty
.endif

.if !empty(PKG_OPTIONS:Mdri)
BUILD_TARGET=	pkgsrc-dri${BUILD_TARGET_SUFFIX}
PLIST.dri=	# empty
.  include "../../graphics/MesaLib/dri.mk"
.else
BUILD_TARGET=	pkgsrc${BUILD_TARGET_SUFFIX}
PLIST.nodri=	# empty
.endif
###
### XXX This is the default heap size.  Would there be an occasion to
### change it?  It seems large, so we should investigate further.
###
MESA_EXECMEM_HEAPSIZE?=	10485760

.if !empty(PKG_OPTIONS:Mmesa-execmem-mmap)
CFLAGS+=	-DMESA_EXECMEM_MMAP
CFLAGS+=	-DEXEC_HEAP_SIZE=${MESA_EXECMEM_HEAPSIZE:M[0-9]*:Q}
.endif
