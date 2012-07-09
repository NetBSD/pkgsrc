# $NetBSD: buildlink3.mk,v 1.11 2012/07/09 05:52:14 marino Exp $

BUILDLINK_TREE+=	florist

.if !defined(FLORIST_BUILDLINK3_MK)
FLORIST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.florist+=	florist>=2012
BUILDLINK_ABI_DEPENDS.florist+=	florist>=2012
BUILDLINK_PKGSRCDIR.florist?=	../../devel/florist
.endif # FLORIST_BUILDLINK3_MK

BUILDLINK_TREE+=	-florist
