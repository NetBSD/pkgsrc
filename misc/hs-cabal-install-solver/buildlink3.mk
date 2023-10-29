# $NetBSD: buildlink3.mk,v 1.4 2023/10/29 03:29:28 pho Exp $

BUILDLINK_TREE+=	hs-cabal-install-solver

.if !defined(HS_CABAL_INSTALL_SOLVER_BUILDLINK3_MK)
HS_CABAL_INSTALL_SOLVER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-cabal-install-solver+=	hs-cabal-install-solver>=3.10.1
BUILDLINK_ABI_DEPENDS.hs-cabal-install-solver+=	hs-cabal-install-solver>=3.10.1.0
BUILDLINK_PKGSRCDIR.hs-cabal-install-solver?=	../../misc/hs-cabal-install-solver

.include "../../textproc/hs-edit-distance/buildlink3.mk"
.endif	# HS_CABAL_INSTALL_SOLVER_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-cabal-install-solver
