# $NetBSD: buildlink3.mk,v 1.1 2026/09/24 16:16:33 ktnb Exp $

BUILDLINK_TREE+=	unordered-dense

.if !defined(UNORDERED_DENSE_BUILDLINK3_MK)
UNORDERED_DENSE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.unordered-dense+=	unordered-dense>=5.0.1
BUILDLINK_ABI_DEPENDS.unordered-dense+=	unordered-dense>=5.0.1
BUILDLINK_PKGSRCDIR.unordered-dense?=	../../devel/unordered-dense

.endif	# UNORDERED_DENSE_BUILDLINK3_MK

BUILDLINK_TREE+=	-unordered-dense
