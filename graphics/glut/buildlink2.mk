# $NetBSD: buildlink2.mk,v 1.1.2.2 2002/06/21 23:00:31 jlam Exp $

.if !defined(GLUT_BUILDLINK2_MK)
GLUT_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		glut
BUILDLINK_DEPENDS.glut?=	glut>=3.4.2
BUILDLINK_PKGSRCDIR.glut?=	../../graphics/glut

EVAL_PREFIX+=		BUILDLINK_PREFIX.glut=glut
BUILDLINK_PREFIX.glut_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.glut=	include/GL/glut.h
BUILDLINK_FILES.glut+=	include/GL/glutf90.h
BUILDLINK_FILES.glut+=	lib/libglut.*

BUILDLINK_TARGETS+=	glut-buildlink

glut-buildlink: _BUILDLINK_USE

.endif	# GLUT_BUILDLINK2_MK
