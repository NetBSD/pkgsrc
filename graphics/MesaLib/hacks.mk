# $NetBSD: hacks.mk,v 1.6 2008/04/25 20:11:11 bjs Exp $

.if !defined(MESALIBS_HACKS_MK)
MESALIBS_HACKS_MK=	# defined

### [Fri Dec 30 21:00:59 CET 2005 : schwarz]
### make sys/types.h not conflict with inttypes.h
### (issue is specific to IRIX 5.3)
###
.  if !empty(MACHINE_PLATFORM:MIRIX-5.3-*)
PKG_HACKS+=		sys_types_h-inttypes_h-conflict
post-wrapper:
		${MKDIR} ${BUILDLINK_DIR}/include/sys && ${GREP} -v '^typedef.*[^u_]int[12368]*_t;' /usr/include/sys/types.h > ${BUILDLINK_DIR}/include/sys/types.h
# should match int8_t, int16_t, and int32_t (only)
.  endif

.include "../../mk/compiler.mk"
###
### Ordinarily, this is defined by the build.  However, in pkgsrc,
### policy dictates that we do it here.  Let's trust a semi-modern
### gcc with -ffast-math for now.
###
.  if !empty(CC_VERSION:Mgcc-[34]*)
PKG_HACKS+=		no-strict-aliasing
CFLAGS+=		-fno-strict-aliasing
PKG_HACKS+=		gcc-fast-math
CFLAGS+=		-ffast-math
.  endif

.  if !empty(CC_VERSION:Mgcc-[4-9]*)
# Don't hide symbols for glut by default, it doesn't know how to unhide them.
.    if empty(PKGNAME:M*glut*)
PKG_HACKS+=		gcc-hidden-visibility
CFLAGS+=		-fvisibility=hidden
.    endif
.  endif
###
### XXX this shoddy hack is here to fix the unresolved symbol error that
###	results due to '.extern pthread_getspecific' in the x86 and x86-64
###	assembler dispatch routines.  This should be removed ASAP!
###
.  include "../../mk/bsd.fast.prefs.mk"

.  if ${OPSYS} == "NetBSD" && !empty(MACHINE_ARCH:M*86*) && \
	empty(PTHREAD_STUBLIB:U:M*pthstub*)
SUBST_CLASSES+=	asm-hack
SUBST_FILES.asm-hack=	src/mesa/x86/glapi_x86.S
SUBST_FILES.asm-jack+=	src/mesa/x86/glapi_x86-64.S
SUBST_MESSAGE.asm-hack+=Teaching x86 assembler code about NetBSD thread stubs
SUBST_SED.asm-hack=	-e 's,pthread_getspecific,__libc_thr_getspecific,g'
SUBST_STAGE.asm-hack=	post-patch
.  endif

.endif
