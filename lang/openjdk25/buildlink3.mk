# $NetBSD: buildlink3.mk,v 1.1 2026/09/26 12:54:51 tnn Exp $

BUILDLINK_TREE+=	openjdk25

.if !defined(OPENJDK25_BUILDLINK3_MK)
OPENJDK25_BUILDLINK3_MK:=

BUILDLINK_LIBDIRS.openjdk25+=	java/openjdk25/lib
BUILDLINK_LIBDIRS.openjdk25+=	java/openjdk25/lib/server

BUILDLINK_API_DEPENDS.openjdk25+=	openjdk25>=1.25.0.4
BUILDLINK_PKGSRCDIR.openjdk25?=		../../lang/openjdk25

.endif	# OPENJDK25_BUILDLINK3_MK

BUILDLINK_TREE+=	-openjdk25
