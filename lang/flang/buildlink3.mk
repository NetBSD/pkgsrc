# $NetBSD: buildlink3.mk,v 1.4 2025/05/09 19:37:12 wiz Exp $

BUILDLINK_TREE+=	flang

.if !defined(FLANG_BUILDLINK3_MK)
FLANG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.flang+=	flang>=19.1.0
BUILDLINK_ABI_DEPENDS.flang+=	flang>=19.1.7nb1
BUILDLINK_PKGSRCDIR.flang?=	../../lang/flang

BUILDLINK_FILES.flang+=		bin/bbc
BUILDLINK_FILES.flang+=		bin/fir-opt
BUILDLINK_FILES.flang+=		bin/flang-new
BUILDLINK_FILES.flang+=		bin/flang-to-external-fc
BUILDLINK_FILES.flang+=		bin/tco

.include "../../lang/llvm/buildlink3.mk"
.endif	# FLANG_BUILDLINK3_MK

BUILDLINK_TREE+=	-flang
