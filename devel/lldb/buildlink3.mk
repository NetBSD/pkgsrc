# $NetBSD: buildlink3.mk,v 1.3 2017/07/11 19:47:37 adam Exp $

BUILDLINK_TREE+=	lldb

.if !defined(LLDB_BUILDLINK3_MK)
LLDB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lldb+=	lldb>=4.0.1
BUILDLINK_PKGSRCDIR.lldb?=	../../devel/lldb

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../lang/llvm/buildlink3.mk"
.include "../../lang/clang/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/swig/buildlink3.mk"
.endif	# LLDB_BUILDLINK3_MK

BUILDLINK_TREE+=	-lldb
