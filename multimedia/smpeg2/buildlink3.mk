# $NetBSD: buildlink3.mk,v 1.16 2026/09/02 19:03:49 wiz Exp $

BUILDLINK_TREE+=	smpeg2

.if !defined(SMPEG2_BUILDLINK3_MK)
SMPEG2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.smpeg2+=	smpeg2>=2.0.0
BUILDLINK_ABI_DEPENDS.smpeg2?=	smpeg2>=2.0.0nb17
BUILDLINK_PKGSRCDIR.smpeg2?=	../../multimedia/smpeg2

.include "../../devel/SDL2/buildlink3.mk"
.endif	# SMPEG2_BUILDLINK3_MK

BUILDLINK_TREE+=	-smpeg2
