# $NetBSD: buildlink3.mk,v 1.1 2014/02/02 15:24:13 rodent Exp $

BUILDLINK_TREE+=	smpeg2

.if !defined(SMPEG2_BUILDLINK3_MK)
SMPEG2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.smpeg2+=	smpeg2>=2.0.0
BUILDLINK_PKGSRCDIR.smpeg2?=	../../multimedia/smpeg2

.include "../../devel/SDL2/buildlink3.mk"
.endif	# SMPEG2_BUILDLINK3_MK

BUILDLINK_TREE+=	-smpeg2
