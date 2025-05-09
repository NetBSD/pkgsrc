# $NetBSD: buildlink3.mk,v 1.5 2025/05/09 19:37:13 wiz Exp $

BUILDLINK_TREE+=	mlir

.if !defined(MLIR_BUILDLINK3_MK)
MLIR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mlir+=	mlir>=19.1.0
BUILDLINK_ABI_DEPENDS.mlir?=	mlir>=19.1.7nb1
BUILDLINK_PKGSRCDIR.mlir?=	../../lang/mlir

BUILDLINK_FILES.mlir+=		bin/mlir-tblgen

.include "../../lang/llvm/buildlink3.mk"
.endif	# MLIR_BUILDLINK3_MK

BUILDLINK_TREE+=	-mlir
