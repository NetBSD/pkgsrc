# $NetBSD: buildlink3.mk,v 1.11 2020/11/05 09:06:56 ryoon Exp $

BUILDLINK_TREE+=	coreclr

.if !defined(CORECLR_BUILDLINK3_MK)
CORECLR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.coreclr+=	coreclr>=1.0.0
BUILDLINK_ABI_DEPENDS.coreclr?=	coreclr>=1.0.0nb12
BUILDLINK_PKGSRCDIR.coreclr?=	../../lang/coreclr

BUILDLINK_INCDIRS.coreclr+=	CoreCLR/inc
BUILDLINK_INCDIRS.coreclr+=	CoreCLR/gcinfo
BUILDLINK_FILES.coreclr+=	CoreCLR/gcinfo/gcinfoencoder.cpp
BUILDLINK_FILES.coreclr+=	CoreCLR/inc/*.h
BUILDLINK_FILES.coreclr+=	CoreCLR/inc/*.def

.include "../../textproc/icu/buildlink3.mk"
.include "../../lang/llvm/buildlink3.mk"
.include "../../devel/lldb/buildlink3.mk"
.include "../../lang/clang/buildlink3.mk"
.include "../../lang/libunwind/buildlink3.mk"
.endif	# CORECLR_BUILDLINK3_MK

BUILDLINK_TREE+=	-coreclr
