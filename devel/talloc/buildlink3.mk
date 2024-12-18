# $NetBSD: buildlink3.mk,v 1.4 2024/12/18 10:58:03 nros Exp $

BUILDLINK_TREE+=	talloc

.if !defined(TALLOC_BUILDLINK3_MK)
TALLOC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.talloc+=	talloc>=2.1.0
BUILDLINK_ABI_DEPENDS.talloc+=	talloc>=2.4.2nb1
BUILDLINK_PKGSRCDIR.talloc?=	../../devel/talloc
.endif	# TALLOC_BUILDLINK3_MK

BUILDLINK_TREE+=	-talloc
