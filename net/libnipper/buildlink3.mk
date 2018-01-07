# $NetBSD: buildlink3.mk,v 1.3 2018/01/07 13:04:27 rillig Exp $

BUILDLINK_TREE+=	libnipper

.if !defined(LIBNIPPER_BUILDLINK3_MK)
LIBNIPPER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libnipper+=	libnipper>=0.12.1
BUILDLINK_PKGSRCDIR.libnipper?=		../../net/libnipper
.endif # LIBNIPPER_BUILDLINK3_MK

BUILDLINK_TREE+=	-libnipper
