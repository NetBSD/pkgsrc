# $NetBSD: features.mk,v 1.2 2023/07/10 03:16:45 pho Exp $

.include "../../mk/bsd.fast.prefs.mk"

.if !defined(MESALIB_SUPPORTS_DRI)
.  for dri_os in DragonFly FreeBSD NetBSD OpenBSD Linux SunOS
.    if !empty(OPSYS:M${dri_os})
MESALIB_SUPPORTS_DRI?=		yes
.    endif
.  endfor
.endif

MESALIB_SUPPORTS_DRI?=		no

_MESALIB_ARCH_SUPPORTS_XA?=	no # Only for graphics/MesaLib/Makefile
.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64" || \
    ${MACHINE_ARCH:M*arm*} || ${MACHINE_ARCH} == "aarch64"
_MESALIB_ARCH_SUPPORTS_XA=	yes
.endif

.if ${X11_TYPE} == "modular"
MESALIB_SUPPORTS_OSMESA?=	yes
MESALIB_SUPPORTS_GLESv2?=	yes
.  if ${MESALIB_SUPPORTS_DRI} == "yes"
MESALIB_SUPPORTS_EGL?=		yes
.    if ${_MESALIB_ARCH_SUPPORTS_XA} == "yes"
MESALIB_SUPPORTS_XA?=		yes
.    endif
.  endif
.else
.  if exists(${X11BASE}/include/EGL/egl.h)
MESALIB_SUPPORTS_EGL?=		yes
.  endif
.  if exists(${X11BASE}/lib/libOSMesa.so)
MESALIB_SUPPORTS_OSMESA?=	yes
.  endif
.  if exists(${X11BASE}/include/GLES2/gl2.h)
MESALIB_SUPPORTS_GLESv2?=	yes
.  endif
.  if exists(${X11BASE}/include/xa_tracker.h)
MESALIB_SUPPORTS_XA?=		yes
.  endif
.endif

MESALIB_SUPPORTS_EGL?=		no
MESALIB_SUPPORTS_GLESv2?=	no
MESALIB_SUPPORTS_OSMESA?=	no
MESALIB_SUPPORTS_XA?=		no
