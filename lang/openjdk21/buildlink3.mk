# $NetBSD: buildlink3.mk,v 1.2 2026/09/29 10:49:57 tnn Exp $

BUILDLINK_TREE+=	openjdk21

.if !defined(OPENJDK21_BUILDLINK3_MK)
OPENJDK21_BUILDLINK3_MK:=

BUILDLINK_LIBDIRS.openjdk21+=	java/openjdk21/lib
BUILDLINK_LIBDIRS.openjdk21+=	java/openjdk21/lib/server
BUILDLINK_LIBDIRS.openjdk21+=	java/openjdk21/lib/zero

BUILDLINK_API_DEPENDS.openjdk21+=	openjdk21>=1.21.0.1.12
BUILDLINK_PKGSRCDIR.openjdk21?=		../../lang/openjdk21

.endif	# OPENJDK21_BUILDLINK3_MK

BUILDLINK_TREE+=	-openjdk21
