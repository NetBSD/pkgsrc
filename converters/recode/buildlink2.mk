# $NetBSD: buildlink2.mk,v 1.3 2003/07/13 13:50:54 wiz Exp $

.if !defined(RECODE_BUILDLINK2_MK)
RECODE_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		recode
BUILDLINK_DEPENDS.recode?=	recode>=3.6nb1
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
