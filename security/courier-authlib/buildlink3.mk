# $NetBSD: buildlink3.mk,v 1.8 2010/06/15 23:10:44 pettai Exp $

BUILDLINK_TREE+=	courier-authlib

.if !defined(COURIER_AUTHLIB_BUILDLINK3_MK)
COURIER_AUTHLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.courier-authlib+=	courier-authlib>=0.53
BUILDLINK_ABI_DEPENDS.courier-authlib?=	courier-authlib>=0.63.0
BUILDLINK_PKGSRCDIR.courier-authlib?=	../../security/courier-authlib
.endif # COURIER_AUTHLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-courier-authlib
