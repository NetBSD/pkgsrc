# $NetBSD: buildlink3.mk,v 1.2 2019/05/24 08:38:28 hauke Exp $

BUILDLINK_TREE+=	courier-unicode

.if !defined(COURIER_UNICODE_BUILDLINK3_MK)
COURIER_UNICODE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.courier-unicode+=	courier-unicode>=2.0
BUILDLINK_ABI_DEPENDS.courier-unicode+=	courier-unicode>=2.1
BUILDLINK_PKGSRCDIR.courier-unicode?=	../../mail/courier-unicode

.endif # COURIER_UNICODE_BUILDLINK3_MK

BUILDLINK_TREE+=	-courier-unicode
