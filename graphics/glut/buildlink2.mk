# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/05/11 02:09:12 jlam Exp $
#
# This Makefile fragment is included by packages that use glut.
#
# To use this Makefile fragment, simply include this Makefile fragment in the
# package Makefile.

.if !defined(GLUT_BUILDLINK2_MK)
GLUT_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.buildlink2.mk"

BUILDLINK_DEPENDS.glut?=	glut>=3.4.2

DEPENDS+=		${BUILDLINK_DEPENDS.glut}:../../graphics/glut
EVAL_PREFIX+=		BUILDLINK_PREFIX.glut=glut
BUILDLINK_PREFIX.glut_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.glut=	include/GL/glut.h
BUILDLINK_FILES.glut+=	include/GL/glutf90.h
BUILDLINK_FILES.glut+=	lib/libglut.*

BUILDLINK_TARGETS+=	glut-buildlink

glut-buildlink: _BUILDLINK_USE

.endif	# GLUT_BUILDLINK2_MK
