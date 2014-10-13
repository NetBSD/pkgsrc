# $NetBSD: buildlink3.mk,v 1.1 2014/10/13 13:02:26 mef Exp $

BUILDLINK_TREE+=	libmirisdr

.if !defined(LIBMIRISDR_BUILDLINK3_MK)
LIBMIRISDR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmirisdr+=	libmirisdr>=0.1
BUILDLINK_ABI_DEPENDS.libmirisdr+=	libmirisdr>=0.1
BUILDLINK_PKGSRCDIR.libmirisdr?=	../../ham/libmirisdr

.endif # LIBMIRISDR_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmirisdr
