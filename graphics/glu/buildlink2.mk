# $NetBSD: buildlink2.mk,v 1.15 2004/01/25 17:26:07 jlam Exp $

.if !defined(GLU_BUILDLINK2_MK)
GLU_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		glu
BUILDLINK_DEPENDS.glu?=		glu>=6.0
BUILDLINK_PKGSRCDIR.glu?=	../../graphics/glu
EVAL_PREFIX+=			BUILDLINK_PREFIX.glu=glu
BUILDLINK_PREFIX.glu_DEFAULT=	${LOCALBASE}

BUILDLINK_FILES.glu=	include/GL/glu.h
BUILDLINK_FILES.glu+=	include/GL/glu_mangle.h
BUILDLINK_FILES.glu+=	lib/libGLU.*

USE_X11=		# defined

.include "../../graphics/MesaLib/buildlink2.mk"

BUILDLINK_TARGETS+=	glu-buildlink
BUILDLINK_TARGETS+=	glu-libGLU-la

glu-buildlink: _BUILDLINK_USE

glu-libGLU-la:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	lafile="${BUILDLINK_DIR}/lib/libGLU.la";			\
	libpattern="${BUILDLINK_PREFIX.glu}/lib/libGLU.*";		\
	${BUILDLINK_FAKE_LA}

.endif	# GLU_BUILDLINK2_MK
