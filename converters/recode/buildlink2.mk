# $NetBSD: buildlink2.mk,v 1.2 2002/08/25 19:22:02 jlam Exp $

.if !defined(RECODE_BUILDLINK2_MK)
RECODE_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		recode
BUILDLINK_DEPENDS.recode?=	recode>=3.5
BUILDLINK_PKGSRCDIR.recode?=	../../databases/recode

EVAL_PREFIX+=			BUILDLINK_PREFIX.recode=recode
BUILDLINK_PREFIX.recode_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.recode=		include/recode.h
BUILDLINK_FILES.recode+=	include/recodext.h
BUILDLINK_FILES.recode+=	lib/librecode.*

.include "../../devel/gettext-lib/buildlink2.mk"

BUILDLINK_TARGETS+=	recode-buildlink

recode-buildlink: _BUILDLINK_USE

.endif	# RECODE_BUILDLINK2_MK
