# $NetBSD: buildlink3.mk,v 1.8 2022/03/28 10:43:40 tnn Exp $

BUILDLINK_TREE+=	twolame

.if !defined(TWOLAME_BUILDLINK3_MK)
TWOLAME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.twolame+=	twolame>=0.3.7
BUILDLINK_ABI_DEPENDS.twolame+=	twolame>=0.4.0nb2
BUILDLINK_PKGSRCDIR.twolame?=	../../audio/twolame

.include "../../audio/libsndfile/buildlink3.mk"
.endif # TWOLAME_BUILDLINK3_MK

BUILDLINK_TREE+=	-twolame
