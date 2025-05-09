# $NetBSD: buildlink3.mk,v 1.4 2025/05/09 05:51:25 adam Exp $

BUILDLINK_TREE+=	mlir

.if !defined(MLIR_BUILDLINK3_MK)
MLIR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mlir+=	mlir>=19.1.0
BUILDLINK_PKGSRCDIR.mlir?=	../../lang/mlir

BUILDLINK_FILES.mlir+=		bin/mlir-tblgen

.include "../../lang/llvm/buildlink3.mk"
.endif	# MLIR_BUILDLINK3_MK

BUILDLINK_TREE+=	-mlir
