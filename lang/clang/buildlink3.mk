# $NetBSD: buildlink3.mk,v 1.13 2020/11/05 09:06:56 ryoon Exp $

BUILDLINK_TREE+=	clang

.if !defined(CLANG_BUILDLINK3_MK)
CLANG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.clang+=	clang>=9.0.1
BUILDLINK_ABI_DEPENDS.clang?=	clang>=10.0.1nb2
BUILDLINK_PKGSRCDIR.clang?=	../../lang/clang

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/llvm/buildlink3.mk"
.endif	# CLANG_BUILDLINK3_MK

BUILDLINK_TREE+=	-clang
