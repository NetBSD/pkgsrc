# $NetBSD: buildlink3.mk,v 1.11 2022/06/28 11:35:34 wiz Exp $

BUILDLINK_TREE+=	courier-authlib

.if !defined(COURIER_AUTHLIB_BUILDLINK3_MK)
COURIER_AUTHLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.courier-authlib+=	courier-authlib>=0.53
BUILDLINK_ABI_DEPENDS.courier-authlib+=	courier-authlib>=0.69.1nb5
BUILDLINK_PKGSRCDIR.courier-authlib?=	../../security/courier-authlib
.endif # COURIER_AUTHLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-courier-authlib
