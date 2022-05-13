# $NetBSD: buildlink3.mk,v 1.1 2022/05/13 14:24:19 ryoon Exp $

BUILDLINK_TREE+=	openjdk17

.if !defined(OPENJDK17_BUILDLINK3_MK)
OPENJDK17_BUILDLINK3_MK:=

BUILDLINK_LIBDIRS.openjdk17+=	java/openjdk17/lib
BUILDLINK_LIBDIRS.openjdk17+=	java/openjdk17/lib/jli
BUILDLINK_LIBDIRS.openjdk17+=	java/openjdk17/lib/server

BUILDLINK_API_DEPENDS.openjdk17+=	openjdk17>=1.17.0.3.7
BUILDLINK_PKGSRCDIR.openjdk17?=		../../lang/openjdk17

.endif	# OPENJDK17_BUILDLINK3_MK

BUILDLINK_TREE+=	-openjdk17
