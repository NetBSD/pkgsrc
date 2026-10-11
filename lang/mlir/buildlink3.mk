# $NetBSD: buildlink3.mk,v 1.9 2026/10/11 16:02:20 wiz Exp $

BUILDLINK_TREE+=	mlir

.if !defined(MLIR_BUILDLINK3_MK)
MLIR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mlir+=	mlir>=22.1.0
BUILDLINK_ABI_DEPENDS.mlir?=	mlir>=22.1.8nb1
BUILDLINK_PKGSRCDIR.mlir?=	../../lang/mlir

BUILDLINK_FILES.mlir+=		bin/mlir-tblgen

.include "../../lang/llvm/buildlink3.mk"
.endif	# MLIR_BUILDLINK3_MK

BUILDLINK_TREE+=	-mlir
