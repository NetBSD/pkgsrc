# $NetBSD: buildlink3.mk,v 1.4 2025/04/16 20:43:41 adam Exp $

BUILDLINK_TREE+=	freecell-solver

.if !defined(FREECELL_SOLVER_BUILDLINK3_MK)
FREECELL_SOLVER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.freecell-solver+=	freecell-solver>=5.14.0
BUILDLINK_ABI_DEPENDS.freecell-solver+=	freecell-solver>=5.14.0nb6
BUILDLINK_PKGSRCDIR.freecell-solver?=	../../games/freecell-solver
.endif	# FREECELL_SOLVER_BUILDLINK3_MK

BUILDLINK_TREE+=	-freecell-solver
