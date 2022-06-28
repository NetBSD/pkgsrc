# $NetBSD: buildlink3.mk,v 1.2 2022/06/28 11:31:45 wiz Exp $

BUILDLINK_TREE+=	kdevplatform

.if !defined(KDEVPLATFORM_BUILDLINK3_MK)
KDEVPLATFORM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kdevplatform+=	kdevplatform>=1.0.0
BUILDLINK_ABI_DEPENDS.kdevplatform?=	kdevplatform>=1.7.0nb50
BUILDLINK_PKGSRCDIR.kdevplatform?=	../../devel/kdevplatform
.endif # KDEVPLATFORM_BUILDLINK3_MK

BUILDLINK_TREE+=	-kdevplatform
