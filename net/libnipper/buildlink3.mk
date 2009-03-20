# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:25:10 joerg Exp $

BUILDLINK_TREE+=	libnipper

.if !defined(LIBNIPPER_BUILDLINK3_MK)
LIBNIPPER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libnipper+=	libnipper>=0.12.1
BUILDLINK_PKGSRCDIR.libnipper?=	../../net/libnipper
.endif # LIBNIPPER_BUILDLINK3_MK

BUILDLINK_TREE+=	-libnipper
