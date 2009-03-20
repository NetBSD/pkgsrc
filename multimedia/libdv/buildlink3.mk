# $NetBSD: buildlink3.mk,v 1.9 2009/03/20 19:25:03 joerg Exp $

BUILDLINK_TREE+=	libdv

.if !defined(LIBDV_BUILDLINK3_MK)
LIBDV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdv+=	libdv>=0.102
BUILDLINK_ABI_DEPENDS.libdv+=	libdv>=0.104nb2
BUILDLINK_PKGSRCDIR.libdv?=	../../multimedia/libdv
.endif # LIBDV_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdv
