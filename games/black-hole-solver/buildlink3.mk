# $NetBSD: buildlink3.mk,v 1.1 2021/04/08 19:51:44 markd Exp $

BUILDLINK_TREE+=	black-hole-solver

.if !defined(BLACK_HOLE_SOLVER_BUILDLINK3_MK)
BLACK_HOLE_SOLVER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.black-hole-solver+=	black-hole-solver>=1.10.1
BUILDLINK_PKGSRCDIR.black-hole-solver?=		../../games/black-hole-solver

.endif	# BLACK_HOLE_SOLVER_BUILDLINK3_MK

BUILDLINK_TREE+=	-black-hole-solver
