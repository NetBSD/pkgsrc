# $NetBSD: buildlink3.mk,v 1.10 2020/12/04 04:56:11 riastradh Exp $

BUILDLINK_TREE+=	courier-authlib

.if !defined(COURIER_AUTHLIB_BUILDLINK3_MK)
COURIER_AUTHLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.courier-authlib+=	courier-authlib>=0.53
BUILDLINK_ABI_DEPENDS.courier-authlib+=	courier-authlib>=0.69.1nb2
BUILDLINK_PKGSRCDIR.courier-authlib?=	../../security/courier-authlib
.endif # COURIER_AUTHLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-courier-authlib
