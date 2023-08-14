# $NetBSD: buildlink3.mk,v 1.17 2023/08/14 05:24:12 wiz Exp $

BUILDLINK_TREE+=	lldb

.if !defined(LLDB_BUILDLINK3_MK)
LLDB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lldb+=	lldb>=9.0.1<16
BUILDLINK_ABI_DEPENDS.lldb+=	lldb>=15.0.7nb2
BUILDLINK_PKGSRCDIR.lldb?=	../../devel/lldb

.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/clang/buildlink3.mk"
.include "../../lang/llvm/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif	# LLDB_BUILDLINK3_MK

BUILDLINK_TREE+=	-lldb
