# $NetBSD: buildlink2.mk,v 1.1.1.1 2002/10/16 15:40:33 jschauma Exp $

.if !defined(NEWMAT_BUILDLINK2_MK)
NEWMAT_BUILDLINK2_MK=			# defined

BUILDLINK_PACKAGES+=			newmat
BUILDLINK_DEPENDS.newmat?=		newmat>=10
BUILDLINK_PKGSRCDIR.newmat?=		../../math/newmat

EVAL_PREFIX+=				BUILDLINK_PREFIX.newmat=newmat
BUILDLINK_PREFIX.newmat_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.newmat=			include/newmat/*
BUILDLINK_FILES.newmat+=		lib/libnewmat.*

BUILDLINK_TARGETS+=			newmat-buildlink

newmat-buildlink: 			_BUILDLINK_USE

.endif	# NEWMAT_BUILDLINK2_MK
