# $NetBSD: buildlink3.mk,v 1.11 2017/02/26 10:15:52 adam Exp $

BUILDLINK_TREE+=	libdvbpsi

.if !defined(LIBDVBPSI_BUILDLINK3_MK)
LIBDVBPSI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdvbpsi+=	libdvbpsi>=0.1.3
BUILDLINK_ABI_DEPENDS.libdvbpsi+=	libdvbpsi>=1.1.0
BUILDLINK_PKGSRCDIR.libdvbpsi?=		../../multimedia/libdvbpsi
.endif # LIBDVBPSI_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdvbpsi
