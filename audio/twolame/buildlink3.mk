# $NetBSD: buildlink3.mk,v 1.7 2020/08/18 17:57:26 leot Exp $

BUILDLINK_TREE+=	twolame

.if !defined(TWOLAME_BUILDLINK3_MK)
TWOLAME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.twolame+=	twolame>=0.3.7
BUILDLINK_ABI_DEPENDS.twolame+=	twolame>=0.4.0nb1
BUILDLINK_PKGSRCDIR.twolame?=	../../audio/twolame

.include "../../audio/libsndfile/buildlink3.mk"
.endif # TWOLAME_BUILDLINK3_MK

BUILDLINK_TREE+=	-twolame
