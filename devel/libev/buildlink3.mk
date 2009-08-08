# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/08/08 19:40:37 sno Exp $

BUILDLINK_TREE+=	libev

.if !defined(LIBEV_BUILDLINK3_MK)
LIBEV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libev+=libev>=3.7
BUILDLINK_ABI_DEPENDS.libev+=libev>=3.7
BUILDLINK_PKGSRCDIR.libev?=	../../devel/libev
.endif # LIBEV_BUILDLINK3_MK

BUILDLINK_TREE+=	-libev
