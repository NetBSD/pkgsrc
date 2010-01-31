# $NetBSD: buildlink3.mk,v 1.2.4.1 2010/01/31 14:04:37 tron Exp $

BUILDLINK_TREE+=	libev

.if !defined(LIBEV_BUILDLINK3_MK)
LIBEV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libev+=libev>=3.8nb1
BUILDLINK_ABI_DEPENDS.libev+=libev>=3.8nb1
BUILDLINK_PKGSRCDIR.libev?=	../../devel/libev

BUILDLINK_LIBDIRS.libev+=	lib/ev
BUILDLINK_RPATHDIRS.libev+=	lib/ev
BUILDLINK_INCDIRS.libev+=	include/ev

.endif # LIBEV_BUILDLINK3_MK

BUILDLINK_TREE+=	-libev
