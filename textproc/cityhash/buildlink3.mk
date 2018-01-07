# $NetBSD: buildlink3.mk,v 1.2 2018/01/07 13:04:33 rillig Exp $

BUILDLINK_TREE+=	cityhash

.if !defined(CITYHASH_BUILDLINK3_MK)
CITYHASH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cityhash+=	cityhash>=1.1.0
BUILDLINK_PKGSRCDIR.cityhash?=		../../textproc/cityhash
.endif	# CITYHASH_BUILDLINK3_MK

BUILDLINK_TREE+=	-cityhash
