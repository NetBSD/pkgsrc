# $NetBSD: buildlink3.mk,v 1.4 2010/12/02 15:47:12 wiz Exp $

BUILDLINK_TREE+=	libev

.if !defined(LIBEV_BUILDLINK3_MK)
LIBEV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libev+=libev>=3.9nb1
BUILDLINK_ABI_DEPENDS.libev+=libev>=4.01
BUILDLINK_PKGSRCDIR.libev?=	../../devel/libev

BUILDLINK_LIBDIRS.libev+=	lib/ev
BUILDLINK_RPATHDIRS.libev+=	lib/ev
BUILDLINK_INCDIRS.libev+=	include/ev

.endif # LIBEV_BUILDLINK3_MK

BUILDLINK_TREE+=	-libev
