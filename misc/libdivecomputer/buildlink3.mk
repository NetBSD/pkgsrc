# $NetBSD: buildlink3.mk,v 1.2 2023/05/27 07:09:09 charlotte Exp $

BUILDLINK_TREE+=	libdivecomputer

.if !defined(LIBDIVECOMPUTER_BUILDLINK3_MK)
LIBDIVECOMPUTER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdivecomputer+=	libdivecomputer>=0.8.0
BUILDLINK_ABI_DEPENDS.libdivecomputer+=	libdivecomputer>=0.8.0
BUILDLINK_PKGSRCDIR.libdivecomputer?=	../../misc/libdivecomputer

.endif # LIBDIVECOMPUTER_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdivecomputer
