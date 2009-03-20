# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:25:09 joerg Exp $

BUILDLINK_TREE+=	libmms

.if !defined(LIBMMS_BUILDLINK3_MK)
LIBMMS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmms+=	libmms>=0.3
BUILDLINK_PKGSRCDIR.libmms?=	../../net/libmms
.endif # LIBMMS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmms
