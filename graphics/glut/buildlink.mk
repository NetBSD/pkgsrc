# $NetBSD: buildlink.mk,v 1.1 2002/06/26 05:36:30 jlam Exp $

.if !defined(GLUT_BUILDLINK_MK)
GLUT_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.glut?=	glut>=3.4.2
DEPENDS+=	${BUILDLINK_DEPENDS.glut}:../../graphics/glut

EVAL_PREFIX+=		BUILDLINK_PREFIX.glut=glut
BUILDLINK_PREFIX.glut_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.glut=	include/GL/glut.h
BUILDLINK_FILES.glut+=	include/GL/glutf90.h
BUILDLINK_FILES.glut+=	lib/libglut.*

BUILDLINK_TARGETS+=	glut-buildlink

pre-configure: glut-buildlink
glut-buildlink: _BUILDLINK_USE

.endif	# GLUT_BUILDLINK_MK
