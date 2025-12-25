# $NetBSD: buildlink3.mk,v 1.1 2025/12/25 16:57:54 ryoon Exp $

BUILDLINK_TREE+=	libdwarf

.if !defined(LIBDWARF_BUILDLINK3_MK)
LIBDWARF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdwarf+=	libdwarf>=2.2.0
BUILDLINK_PKGSRCDIR.libdwarf?=		../../devel/libdwarf
.endif	# LIBDWARF_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdwarf
