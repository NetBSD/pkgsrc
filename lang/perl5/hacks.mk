# $NetBSD: hacks.mk,v 1.5 2011/10/11 10:02:13 hauke Exp $

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

### [Sun Nov 14 02:35:50 EST 2004 : jlam]
### On PowerPC, building with optimisation with GCC causes an "attempt
### to free unreference scalar".  Remove optimisation flags as a
### workaround until GCC is fixed.
###
.if !empty(CC_VERSION:Mgcc*) && !empty(MACHINE_PLATFORM:MNetBSD-*-powerpc)
PKG_HACKS+=		powerpc-codegen
BUILDLINK_TRANSFORM+=	rm:-O[0-9]*
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

.  if ${OPSYS} == "NetBSD" && ${MACHINE_ARCH} == "m68k"
PKG_HACKS+=		m68k-codegen
BUILDLINK_TRANSFORM+=	rename:-O[0-9]*:-Os
.  endif

.endif  # PERL5_HACKS_MK
