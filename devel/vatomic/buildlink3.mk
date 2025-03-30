# $NetBSD: buildlink3.mk,v 1.1 2025/03/30 07:57:10 wiz Exp $

BUILDLINK_TREE+=	vatomic

.if !defined(VATOMIC_BUILDLINK3_MK)
VATOMIC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.vatomic+=	vatomic>=2.3.1
BUILDLINK_ABI_DEPENDS.vatomic+=	vatomic>=2.3.1
BUILDLINK_PKGSRCDIR.vatomic?=	../../devel/vatomic

.endif # VATOMIC_BUILDLINK3_MK

BUILDLINK_TREE+=	-vatomic
