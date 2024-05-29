# $NetBSD: buildlink3.mk,v 1.1 2024/05/29 16:33:13 adam Exp $

BUILDLINK_TREE+=	flang

.if !defined(FLANG_BUILDLINK3_MK)
FLANG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.flang+=	flang>=17.0.0<18
BUILDLINK_ABI_DEPENDS.flang+=	flang>=17.0.0
BUILDLINK_PKGSRCDIR.flang?=	../../lang/flang

BUILDLINK_FILES.flang+=		bin/bbc
BUILDLINK_FILES.flang+=		bin/fir-opt
BUILDLINK_FILES.flang+=		bin/flang-new
BUILDLINK_FILES.flang+=		bin/flang-to-external-fc
BUILDLINK_FILES.flang+=		bin/tco

.include "../../lang/llvm/buildlink3.mk"
.endif	# FLANG_BUILDLINK3_MK

BUILDLINK_TREE+=	-flang
