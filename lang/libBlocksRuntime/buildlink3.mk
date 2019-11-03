# $NetBSD: buildlink3.mk,v 1.2 2019/11/03 19:04:02 rillig Exp $

BUILDLINK_TREE+=	libBlocksRuntime

.if !defined(LIBBLOCKSRUNTIME_BUILDLINK3_MK)
LIBBLOCKSRUNTIME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libBlocksRuntime+=	libBlocksRuntime>=6.0.0
BUILDLINK_PKGSRCDIR.libBlocksRuntime?=		../../lang/libBlocksRuntime
.endif	# LIBBLOCKSRUNTIME_BUILDLINK3_MK

BUILDLINK_TREE+=	-libBlocksRuntime
