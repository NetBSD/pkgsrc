# $NetBSD: buildlink3.mk,v 1.2 2017/05/05 23:13:05 kamil Exp $

BUILDLINK_TREE+=	lldb

.if !defined(LLDB_BUILDLINK3_MK)
LLDB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lldb+=	lldb>=4.0.0
BUILDLINK_PKGSRCDIR.lldb?=	../../devel/lldb

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../lang/llvm/buildlink3.mk"
.include "../../lang/clang/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/swig/buildlink3.mk"
.endif	# LLDB_BUILDLINK3_MK

BUILDLINK_TREE+=	-lldb
