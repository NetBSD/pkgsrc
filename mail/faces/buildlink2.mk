# $NetBSD: buildlink2.mk,v 1.2 2002/08/25 19:23:05 jlam Exp $

.if !defined(FACES_BUILDLINK2_MK)
FACES_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		faces
BUILDLINK_DEPENDS.faces?=	faces>=1.6.1nb1
BUILDLINK_PKGSRCDIR.faces?=	../../mail/faces

EVAL_PREFIX+=			BUILDLINK_PREFIX.faces=faces
BUILDLINK_PREFIX.faces_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.faces=		include/compface.h
BUILDLINK_FILES.faces+=		lib/libcompface.*

BUILDLINK_TARGETS+=	faces-buildlink

faces-buildlink: _BUILDLINK_USE

.endif	# FACES_BUILDLINK2_MK
