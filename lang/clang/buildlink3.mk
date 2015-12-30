# $NetBSD: buildlink3.mk,v 1.3 2015/12/30 15:54:56 bsiegert Exp $

BUILDLINK_TREE+=	clang

.if !defined(CLANG_BUILDLINK3_MK)
CLANG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.clang+=	clang>=3.7.0
BUILDLINK_PKGSRCDIR.clang?=	../../lang/clang

#.include "../../textproc/libxml2/buildlink3.mk"
#.include "../../devel/zlib/buildlink3.mk"
.endif	# CLANG_BUILDLINK3_MK

BUILDLINK_TREE+=	-clang
