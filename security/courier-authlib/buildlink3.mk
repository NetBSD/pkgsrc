# $NetBSD: buildlink3.mk,v 1.12 2024/02/12 17:24:07 hans Exp $

BUILDLINK_TREE+=	courier-authlib

.if !defined(COURIER_AUTHLIB_BUILDLINK3_MK)
COURIER_AUTHLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.courier-authlib+=	courier-authlib>=0.72
BUILDLINK_ABI_DEPENDS.courier-authlib+=	courier-authlib>=0.72.1
BUILDLINK_PKGSRCDIR.courier-authlib?=	../../security/courier-authlib

.endif # COURIER_AUTHLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-courier-authlib
