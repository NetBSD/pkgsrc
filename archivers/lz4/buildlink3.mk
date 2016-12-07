# $NetBSD: buildlink3.mk,v 1.4 2016/12/07 21:34:58 fhajny Exp $

BUILDLINK_TREE+=	lz4

.if !defined(LZ4_BUILDLINK3_MK)
LZ4_BUILDLINK3_MK:=

# Set upper limit to force update from the previous version
# scheme that generated technically higher version numbers
BUILDLINK_API_DEPENDS.lz4+=	lz4>=1.7.3<100
BUILDLINK_ABI_DEPENDS.lz4+=	lz4>=1.7.3
BUILDLINK_PKGSRCDIR.lz4?=	../../archivers/lz4
.endif # LZ4_BUILDLINK3_MK

BUILDLINK_TREE+=	-lz4
