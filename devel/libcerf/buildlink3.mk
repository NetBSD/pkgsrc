# $NetBSD: buildlink3.mk,v 1.2 2024/06/05 13:51:28 adam Exp $

BUILDLINK_TREE+=	libcerf

.if !defined(LIBCERF_BUILDLINK3_MK)
LIBCERF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcerf+=	libcerf>=2.4
BUILDLINK_PKGSRCDIR.libcerf?=	../../devel/libcerf
.endif	# LIBCERF_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcerf
