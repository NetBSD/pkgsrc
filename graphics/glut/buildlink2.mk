# $NetBSD: buildlink2.mk,v 1.5 2003/03/09 19:04:54 jschauma Exp $

.if !defined(GLUT_BUILDLINK2_MK)
GLUT_BUILDLINK2_MK=	# defined

MESA_REQD?=			3.4.2
BUILDLINK_PACKAGES+=		glut
BUILDLINK_DEPENDS.glut?=	glut>=${MESA_REQD}
BUILDLINK_PKGSRCDIR.glut?=	../../graphics/glut

EVAL_PREFIX+=		BUILDLINK_PREFIX.glut=glut
BUILDLINK_PREFIX.glut_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.glut=	include/GL/glut.h
BUILDLINK_FILES.glut+=	include/GL/glutf90.h
BUILDLINK_FILES.glut+=	lib/libglut.*

.include "../../graphics/MesaLib/buildlink2.mk"

BUILDLINK_TARGETS+=	glut-buildlink

glut-buildlink: _BUILDLINK_USE

.endif	# GLUT_BUILDLINK2_MK
