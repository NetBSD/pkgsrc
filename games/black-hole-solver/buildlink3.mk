# $NetBSD: buildlink3.mk,v 1.3 2023/08/14 05:24:25 wiz Exp $

BUILDLINK_TREE+=	black-hole-solver

.if !defined(BLACK_HOLE_SOLVER_BUILDLINK3_MK)
BLACK_HOLE_SOLVER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.black-hole-solver+=	black-hole-solver>=1.10.1
BUILDLINK_ABI_DEPENDS.black-hole-solver?=		black-hole-solver>=1.10.1nb3
BUILDLINK_PKGSRCDIR.black-hole-solver?=		../../games/black-hole-solver

.endif	# BLACK_HOLE_SOLVER_BUILDLINK3_MK

BUILDLINK_TREE+=	-black-hole-solver
