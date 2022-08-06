# $NetBSD: buildlink3.mk,v 1.2 2022/08/06 07:22:32 nia Exp $

BUILDLINK_TREE+=	libepoll-shim

.if !defined(LIBEPOLL_SHIM_BUILDLINK3_MK)
LIBEPOLL_SHIM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libepoll-shim+=	libepoll-shim>=0.0.20210418
BUILDLINK_PKGSRCDIR.libepoll-shim?=	../../devel/libepoll-shim

.endif	# LIBEPOLL_SHIM_BUILDLINK3_MK

BUILDLINK_TREE+=	-libepoll-shim
