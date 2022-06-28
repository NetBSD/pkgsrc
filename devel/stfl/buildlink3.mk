# $NetBSD: buildlink3.mk,v 1.2 2022/06/28 11:33:43 wiz Exp $

BUILDLINK_TREE+=	stfl

.if !defined(STFL_BUILDLINK3_MK)
STFL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.stfl+=	stfl>=0.19
BUILDLINK_ABI_DEPENDS.stfl?=	stfl>=0.24nb7
BUILDLINK_PKGSRCDIR.stfl?=	../../devel/stfl
.endif	# STFL_BUILDLINK3_MK

BUILDLINK_TREE+=	-stfl
