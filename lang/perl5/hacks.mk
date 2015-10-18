# $NetBSD: hacks.mk,v 1.17.2.1 2015/10/18 16:45:27 spz Exp $

.if !defined(PERL5_HACKS_MK)
PERL5_HACKS_MK=	defined

.include "../../mk/compiler.mk"

### [Thu Jun 7 04:25:34 UTC 2001 : jlam]
### Fix brokenness when using an older toolchain (gcc<3.3) on
### NetBSD/sparc64.  Pass -g and -DDEBUGGING to the compiler to
### circumvent some code-generation bugs.
###
.if !empty(MACHINE_PLATFORM:MNetBSD-*-sparc64)
.  if !empty(CC_VERSION:Mgcc*)
.    if !defined(_GCC_IS_TOO_OLD)
_GCC_IS_TOO_OLD!=	\
	if ${PKG_ADMIN} pmatch 'gcc<3.3' ${CC_VERSION}; then		\
		${ECHO} "yes";						\
	else								\
		${ECHO} "no";						\
	fi
MAKEFLAGS+=	_GCC_IS_TOO_OLD=${_GCC_IS_TOO_OLD:Q}
.    endif
.    if !empty(_GCC_IS_TOO_OLD:M[yY][eE][sS])
PKG_HACKS+=	sparc64-codegen
CFLAGS+=	-DDEBUGGING -g -msoft-quad-float -O2
.    endif
.  endif
.endif

### [Mon May 9 15:35:44 UTC 2005 : jlam]
### On NetBSD/arm, skipping one part of the optimization pass empirically
### "fixes" the build of perl using gcc-3.x.
###
.if !empty(CC_VERSION:Mgcc-3.*) && !empty(MACHINE_ARCH:Marm*)
PKG_HACKS+=	arm-codegen
CFLAGS+=	-fno-cse-skip-blocks
.endif

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

### [Fri Jan 31 11:09:04 CST 2014 : schnoebe]
### gcc-4.*.* in NetBSD/alpha causes  unaligned access exception in perl.
### -O works around, and there is a report that -O2 -fno-tree-ter is enough.
.if (!empty(MACHINE_PLATFORM:MNetBSD-*-alpha) || !empty(MACHINE_PLATFORM:MOpenBSD-*-alpha)) \
	&& !empty(CC_VERSION:Mgcc-4.*.*)
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
