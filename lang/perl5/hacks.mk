# $NetBSD: hacks.mk,v 1.21 2018/11/21 08:33:51 maya Exp $

.if !defined(PERL5_HACKS_MK)
PERL5_HACKS_MK=	defined

.include "../../mk/compiler.mk"

### [ Fri Oct 11 10:00:00 UTC 2011 : hauke ]
###
### On m68k, gcc creates short assembler branch insns, and expects
### the assembler to adapt them to the distance. m68k gas appears not to
### do that for fpu branch insns, resulting in an out-of-range FPU
### assembler branch instruction error in "ext/re/re_exec.c".
###
### As a workaround, building with "-Os" instead of "-O2" reduces
### the size of the object file enough to allow short branches.
###
### See PR toolchain/45439.

.if ${OPSYS} == "NetBSD" && ${MACHINE_ARCH} == "m68k"
PKG_HACKS+=		m68k-codegen
BUILDLINK_TRANSFORM+=	opt:-O[0-9]*:-Os
.endif

# Alignment fault on perl 5.28.0
# https://rt.perl.org/Public/Bug/Display.html?id=133495
.if ${OPSYS} == "SunOS" && !empty(MACHINE_ARCH:Msparc*)
PKG_HACKS+=		
BUILDLINK_TRANSFORM+=	opt:-O3:-O2
.endif

### [Fri Jan 31 11:09:04 CST 2014 : schnoebe]
### [Fri Oct 28 11:53:57 EDT 2016 : dholland - extended to gcc5]
### gcc-[45].*.* in NetBSD/alpha causes unaligned access exception in perl.
### -O works around, and there is a report that -O2 -fno-tree-ter is enough.
.if (!empty(MACHINE_PLATFORM:MNetBSD-*-alpha) || !empty(MACHINE_PLATFORM:MOpenBSD-*-alpha)) \
	&& !empty(CC_VERSION:Mgcc-[45].*.*)
# XXX: is there any good way to replace the default -O2 with multiple args?
PKG_HACKS+=		alpha-optimisation
#BUILDLINK_TRANSFORM+=  opt:-O[2-9]*:-O2 -fno-tree-ter
CFLAGS+=-fno-tree-ter
.endif

### [Thu May 14 23:17:20 JST 2015 : ryoon]
### Force to use /usr/sfw/lib/amd64/libgcc_s.co.1 instead.
.if !empty(MACHINE_PLATFORM:MSunOS-5.10-x86_64)
.  if !empty(CC_VERSION:Mgcc-3.4.3)
BUILDLINK_PASSTHRU_RPATHDIRS+=	/usr/sfw/lib/amd64
LDFLAGS+=	${COMPILER_RPATH_FLAG}/usr/sfw/lib/amd64
.  endif
.endif

### [Thu Aug  6 14:43:56 PDT 2015 : mrg]
### On NetBSD/{mips,vax,sparc64}, the -freorder-blocks option in -O2
### causes opmini.c to be miscompiled, and perl build fails.
###
.if !empty(CC_VERSION:Mgcc-4.5.*) && ${OPSYS} == "NetBSD"
.  if (${MACHINE_ARCH} == "vax" ||	\
       ${MACHINE_CPU} == "mips" ||	\
       ${MACHINE_ARCH} == "sparc" ||	\
       ${MACHINE_ARCH} == "sparc64")
PKG_HACKS+=	gcc-4.5-codegen
CFLAGS+=	-fno-reorder-blocks
.  endif
.endif

.endif  # PERL5_HACKS_MK
