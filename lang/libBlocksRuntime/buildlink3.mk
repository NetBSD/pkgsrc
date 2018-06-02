# $NetBSD: buildlink3.mk,v 1.1 2018/06/02 19:11:01 joerg Exp $

BUILDLINK_TREE+=	libBlocksRuntime

.if !defined(LIBBLOCKSRUNTIME_BUILDLINK3_MK)
LIBBLOCKSRUNTIME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libBlocksRuntime+=	libBlocksRuntime>=6.0.0
BUILDLINK_PKGSRCDIR.libBlocksRuntime?=	../../lang/libBlocksRuntime
.endif	# LIBBLOCKSRUNTIME_BUILDLINK3_MK

BUILDLINK_TREE+=	-libBlocksRuntime
