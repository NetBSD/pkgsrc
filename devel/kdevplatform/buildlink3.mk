# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/06/01 21:35:52 markd Exp $

BUILDLINK_TREE+=	kdevplatform

.if !defined(KDEVPLATFORM_BUILDLINK3_MK)
KDEVPLATFORM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kdevplatform+=	kdevplatform>=1.0.0
BUILDLINK_PKGSRCDIR.kdevplatform?=	../../devel/kdevplatform
.endif # KDEVPLATFORM_BUILDLINK3_MK

BUILDLINK_TREE+=	-kdevplatform
