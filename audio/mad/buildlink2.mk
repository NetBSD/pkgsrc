# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/06/23 23:03:56 jlam Exp $

.if !defined(MAD_BUILDLINK2_MK)
MAD_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		mad
BUILDLINK_DEPENDS.mad?=		mad>=0.14.2b
BUILDLINK_PKGSRCDIR.mad?=	../../audio/mad

EVAL_PREFIX+=	BUILDLINK_PREFIX.mad=mad
BUILDLINK_PREFIX.mad_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.mad=		include/id3tag.h
BUILDLINK_FILES.mad+=		include/mad.h
BUILDLINK_FILES.mad+=		lib/libid3tag.*
BUILDLINK_FILES.mad+=		lib/libmad.*

#.include "../../audio/libaudiofile/buildlink2.mk"
.include "../../audio/esound/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"

BUILDLINK_TARGETS+=		mad-buildlink

mad-buildlink: _BUILDLINK_USE

.endif	# MAD_BUILDLINK2_MK
