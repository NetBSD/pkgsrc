# $NetBSD: buildlink3.mk,v 1.2 2023/02/07 01:41:01 pho Exp $

BUILDLINK_TREE+=	hs-cabal-install-solver

.if !defined(HS_CABAL_INSTALL_SOLVER_BUILDLINK3_MK)
HS_CABAL_INSTALL_SOLVER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-cabal-install-solver+=	hs-cabal-install-solver>=3.8.1
BUILDLINK_ABI_DEPENDS.hs-cabal-install-solver+=	hs-cabal-install-solver>=3.8.1.0nb1
BUILDLINK_PKGSRCDIR.hs-cabal-install-solver?=	../../misc/hs-cabal-install-solver

.include "../../textproc/hs-edit-distance/buildlink3.mk"
.endif	# HS_CABAL_INSTALL_SOLVER_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-cabal-install-solver
