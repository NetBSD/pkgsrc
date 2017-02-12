# $NetBSD: buildlink3.mk,v 1.1 2017/02/12 02:30:07 mef Exp $

BUILDLINK_TREE+=	courier-unicode

.if !defined(COURIER_UNICODE_BUILDLINK3_MK)
COURIER_UNICODE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.courier-unicode+=		courier-unicode>=1.2
BUILDLINK_ABI_DEPENDS.courier-unicode+=		courier-unicode>=1.2
BUILDLINK_PKGSRCDIR.courier-unicode?=		../../mail/courier-unicode

.endif # COURIER_UNICODE_BUILDLINK3_MK

BUILDLINK_TREE+=	-courier-unicode
