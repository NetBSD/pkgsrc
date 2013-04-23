# $NetBSD: buildlink3.mk,v 1.10 2013/04/23 09:02:26 wiz Exp $

BUILDLINK_TREE+=	libdvbpsi

.if !defined(LIBDVBPSI_BUILDLINK3_MK)
LIBDVBPSI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdvbpsi+=	libdvbpsi>=0.1.3
BUILDLINK_ABI_DEPENDS.libdvbpsi+=	libdvbpsi>=1.1.0
BUILDLINK_PKGSRCDIR.libdvbpsi?=	../../multimedia/libdvbpsi
.endif # LIBDVBPSI_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdvbpsi
