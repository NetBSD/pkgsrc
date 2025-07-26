# $NetBSD: buildlink3.mk,v 1.3 2025/07/26 07:42:16 charlotte Exp $

BUILDLINK_TREE+=	libdivecomputer

.if !defined(LIBDIVECOMPUTER_BUILDLINK3_MK)
LIBDIVECOMPUTER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdivecomputer+=	libdivecomputer>=0.9.0
BUILDLINK_ABI_DEPENDS.libdivecomputer+=	libdivecomputer>=0.9.0
BUILDLINK_PKGSRCDIR.libdivecomputer?=	../../misc/libdivecomputer

.endif # LIBDIVECOMPUTER_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdivecomputer
