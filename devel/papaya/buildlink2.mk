# $NetBSD: buildlink2.mk,v 1.1.1.1 2002/10/16 04:46:31 rh Exp $
#

.if !defined(PAPAYA_BUILDLINK2_MK)
PAPAYA_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		papaya
BUILDLINK_DEPENDS.papaya?=	papaya>=0.1.7
BUILDLINK_PKGSRCDIR.papaya?=	../../devel/papaya
BUILDLINK_DEPMETHOD.papaya?=	build

EVAL_PREFIX+=	BUILDLINK_PREFIX.papaya=papaya
BUILDLINK_PREFIX.papaya_DEFAULT=	${LOCALBASE}

.include "../../textproc/texi2html/buildlink2.mk"

BUILDLINK_TARGETS+=	papaya-buildlink

papaya-buildlink: _BUILDLINK_USE

.endif	# PAPAYA_BUILDLINK2_MK
