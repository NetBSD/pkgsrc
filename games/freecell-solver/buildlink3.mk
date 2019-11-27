# $NetBSD: buildlink3.mk,v 1.1 2019/11/27 21:17:18 markd Exp $

BUILDLINK_TREE+=	freecell-solver

.if !defined(FREECELL_SOLVER_BUILDLINK3_MK)
FREECELL_SOLVER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.freecell-solver+=	freecell-solver>=5.14.0
BUILDLINK_PKGSRCDIR.freecell-solver?=	../../games/freecell-solver
.endif	# FREECELL_SOLVER_BUILDLINK3_MK

BUILDLINK_TREE+=	-freecell-solver
