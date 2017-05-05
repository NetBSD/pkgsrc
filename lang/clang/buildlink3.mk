# $NetBSD: buildlink3.mk,v 1.6 2017/05/05 23:13:05 kamil Exp $

BUILDLINK_TREE+=	clang

.if !defined(CLANG_BUILDLINK3_MK)
CLANG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.clang+=	clang>=4.0.0
BUILDLINK_PKGSRCDIR.clang?=	../../lang/clang

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/llvm/buildlink3.mk"
.endif	# CLANG_BUILDLINK3_MK

BUILDLINK_TREE+=	-clang
