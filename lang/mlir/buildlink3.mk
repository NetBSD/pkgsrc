# $NetBSD: buildlink3.mk,v 1.1 2023/10/06 19:15:21 adam Exp $

BUILDLINK_TREE+=	mlir

.if !defined(MLIR_BUILDLINK3_MK)
MLIR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mlir+=	mlir>=16.0.0<17
BUILDLINK_PKGSRCDIR.mlir?=	../../lang/mlir

BUILDLINK_FILES.mlir+=		bin/mlir-tblgen

.include "../../lang/llvm/buildlink3.mk"
.endif	# MLIR_BUILDLINK3_MK

BUILDLINK_TREE+=	-mlir
