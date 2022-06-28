# $NetBSD: buildlink3.mk,v 1.2 2022/06/28 11:33:56 wiz Exp $

BUILDLINK_TREE+=	freecell-solver

.if !defined(FREECELL_SOLVER_BUILDLINK3_MK)
FREECELL_SOLVER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.freecell-solver+=	freecell-solver>=5.14.0
BUILDLINK_ABI_DEPENDS.freecell-solver?=	freecell-solver>=5.14.0nb4
BUILDLINK_PKGSRCDIR.freecell-solver?=	../../games/freecell-solver
.endif	# FREECELL_SOLVER_BUILDLINK3_MK

BUILDLINK_TREE+=	-freecell-solver
