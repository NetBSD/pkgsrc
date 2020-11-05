# $NetBSD: buildlink3.mk,v 1.10 2020/11/05 09:06:51 ryoon Exp $

BUILDLINK_TREE+=	lldb

.if !defined(LLDB_BUILDLINK3_MK)
LLDB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lldb+=	lldb>=9.0.1
BUILDLINK_ABI_DEPENDS.lldb+=	lldb>=10.0.1nb2
BUILDLINK_PKGSRCDIR.lldb?=	../../devel/lldb

.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/clang/buildlink3.mk"
.include "../../lang/llvm/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif	# LLDB_BUILDLINK3_MK

BUILDLINK_TREE+=	-lldb
