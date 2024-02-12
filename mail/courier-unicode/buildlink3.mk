# $NetBSD: buildlink3.mk,v 1.3 2024/02/12 17:10:22 hans Exp $

BUILDLINK_TREE+=	courier-unicode

.if !defined(COURIER_UNICODE_BUILDLINK3_MK)
COURIER_UNICODE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.courier-unicode+=	courier-unicode>=2.0
BUILDLINK_ABI_DEPENDS.courier-unicode+=	courier-unicode>=2.3
BUILDLINK_PKGSRCDIR.courier-unicode?=	../../mail/courier-unicode

.endif # COURIER_UNICODE_BUILDLINK3_MK

BUILDLINK_TREE+=	-courier-unicode
