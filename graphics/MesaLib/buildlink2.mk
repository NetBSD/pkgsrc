# $NetBSD: buildlink2.mk,v 1.17 2003/11/23 07:22:10 salo Exp $

.if !defined(MESALIB_BUILDLINK2_MK)
MESALIB_BUILDLINK2_MK=	# defined

.include "../../graphics/Mesa/version.mk"

BUILDLINK_DEPENDS.MesaLib?=	MesaLib>=${MESA_VERSION}
BUILDLINK_PKGSRCDIR.MesaLib?=	../../graphics/MesaLib

BUILDLINK_PACKAGES+=		MesaLib
EVAL_PREFIX+=			BUILDLINK_PREFIX.MesaLib=MesaLib
BUILDLINK_PREFIX.MesaLib_DEFAULT=	${LOCALBASE}

CPPFLAGS+=		-DGLX_GLXEXT_LEGACY
CFLAGS+=		-DGLX_GLXEXT_LEGACY

BUILDLINK_FILES.MesaLib+=	include/GL/gl.h
BUILDLINK_FILES.MesaLib+=	include/GL/glext.h
BUILDLINK_FILES.MesaLib+=	include/GL/gl_mangle.h
BUILDLINK_FILES.MesaLib+=	include/GL/glx*.h
BUILDLINK_FILES.MesaLib+=	include/GL/osmesa.h
BUILDLINK_FILES.MesaLib+=	include/GL/xmesa.h
BUILDLINK_FILES.MesaLib+=	include/GL/xmesa_x.h
BUILDLINK_FILES.MesaLib+=	include/GL/xmesa_xf86.h
BUILDLINK_FILES.MesaLib+=	lib/libGL.*
BUILDLINK_FILES.MesaLib+=	lib/libOSMesa.*

USE_X11=			# defined

BUILDLINK_TARGETS+=		MesaLib-buildlink
BUILDLINK_TARGETS+=		MesaLib-libGL-la

MesaLib-buildlink: _BUILDLINK_USE

MesaLib-libGL-la:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	lafile="${BUILDLINK_DIR}/lib/libGL.la";				\
	libpattern="${BUILDLINK_PREFIX.MesaLib}/lib/libGL.*";		\
	${BUILDLINK_FAKE_LA}

.endif	# MESALIB_BUILDLINK2_MK
