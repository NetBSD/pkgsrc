# $NetBSD: buildlink3.mk,v 1.1 2022/12/19 07:44:50 sekiya Exp $

BUILDLINK_TREE+=	kea

.if !defined(KEA_BUILDLINK3_MK)
KEA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kea+=	kea>=2.2.0
BUILDLINK_PKGSRCDIR.kea?=	../../net/kea
.endif # KEA_BUILDLINK3_MK

BUILDLINK_TREE+=	-kea
