# $NetBSD: buildlink2.mk,v 1.3 2004/02/09 18:14:45 jmmv Exp $

.if !defined(FAM_BUILDLINK2_MK)
FAM_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		fam
BUILDLINK_DEPENDS.fam?=		fam>=2.6.10
BUILDLINK_PKGSRCDIR.fam?=	../../sysutils/fam

EVAL_PREFIX+=	BUILDLINK_PREFIX.fam=fam
BUILDLINK_PREFIX.fam_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.fam+=	include/fam.h
BUILDLINK_FILES.fam+=	lib/libfam.*

BUILDLINK_TARGETS+=	fam-buildlink

fam-buildlink: _BUILDLINK_USE

.endif	# FAM_BUILDLINK2_MK
