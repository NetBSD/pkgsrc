# $NetBSD: buildlink3.mk,v 1.1 2016/05/24 09:20:07 leot Exp $

BUILDLINK_TREE+=	stfl

.if !defined(STFL_BUILDLINK3_MK)
STFL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.stfl+=	stfl>=0.19
BUILDLINK_PKGSRCDIR.stfl?=	../../devel/stfl
.endif	# STFL_BUILDLINK3_MK

BUILDLINK_TREE+=	-stfl
