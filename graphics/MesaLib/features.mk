# $NetBSD: features.mk,v 1.1 2019/10/21 20:47:55 nia Exp $

.include "../../mk/bsd.fast.prefs.mk"

.if !defined(MESALIB_SUPPORTS_DRI)
.  for dri_os in DragonFly FreeBSD NetBSD OpenBSD Linux SunOS
.    if !empty(OPSYS:M${dri_os})
MESALIB_SUPPORTS_DRI?=		yes
.    endif
.  endfor
.endif

MESALIB_SUPPORTS_DRI?=		no

.if ${X11_TYPE} == "modular"
MESALIB_SUPPORTS_OSMESA?=	yes
MESALIB_SUPPORTS_GLESv2?=	yes
.  if ${MESALIB_SUPPORTS_DRI} == "yes"
MESALIB_SUPPORTS_EGL?=		yes
.  else
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
.endif

MESALIB_SUPPORTS_EGL?=		no
MESALIB_SUPPORTS_GLESv2?=	no
MESALIB_SUPPORTS_OSMESA?=	no
