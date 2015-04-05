# $NetBSD: glx-config.mk,v 1.1 2015/04/05 17:01:37 tnn Exp $
#
# used by x11/modular-xorg-server112/options.mk

.if !defined(GLX_CONFIG_MK)
GLX_CONFIG_MK=	# empty

### XXX Older versions of xf86driproto installed dri_interface.h, which
###	is now installed by Mesa.
###
BUILDLINK_API_DEPENDS.xf86driproto+=	xf86driproto>=2.0.4

.  include "../../mk/bsd.fast.prefs.mk"

CFLAGS.NetBSD+=	-D_NETBSD_SOURCE
CFLAGS.NetBSD+=	${ATOMIC_OPS_CHECK}HAVE_NETBSD_ATOMIC_OPS

.  if ${OPSYS} == "NetBSD" && !target(netbsd-atomic-ops-check)
.PHONY:	netbsd-atomic-opts-check
netbsd-atomic-ops-check:
ATOMIC_OPS_CHECK!=\
  if ( ${NM} /usr/lib/libc.so | ${GREP} -q atomic_cas_uint ); then	\
    ${ECHO} "-D";	\
  else	\
    ${ECHO} "-U";	\
  fi
.endif

.if (${MACHINE_ARCH} == "x86_64" || \
    ${MACHINE_ARCH} == "sparc64" || \
    ${MACHINE_ARCH} == "alpha")
CFLAGS+=	-D__GLX_ALIGN64
.endif

.if !empty(MACHINE_ARCH:Mi386) || !empty(MACHINE_ARCH:Mx86_64)
###
### This is taken from <sys/arch/i386/include/npx.h>.  If we don't override
### it, the FPU control word will be restored to 0x037f.
###
### Also, see patch-aq about the libm functions required (float functions
### such as floorf).  Proper configuration of this should be a goal of
### the Mesa developers; alas, it obviously is not.
###
### XXX We need a reliable check for these functions.
###
#/* NetBSD uses IEEE double precision. */
CFLAGS.NetBSD+=		-DDEFAULT_X86_FPU=0x127f
###
#/* FreeBSD leaves some exceptions unmasked as well. */
###
CFLAGS.FreeBSD+=	-DDEFAULT_X86_FPU=0x1272
.  endif

CFLAGS.FreeBSD+=	-DUSE_NATIVE_LIBM_FUNCS
CFLAGS.NetBSD+=		-DUSE_NATIVE_LIBM_FUNCS
CFLAGS.DragonFly+=	-DUSE_NATIVE_LIBM_FUNCS

.endif # GLX_CONFIG_MK
