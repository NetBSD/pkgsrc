# $NetBSD: buildlink3.mk,v 1.9 2013/06/30 03:14:43 rodent Exp $

BUILDLINK_TREE+=	Cg-compiler

.if !defined(CG_COMPILER_BUILDLINK3_MK)
CG_COMPILER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.Cg-compiler+=	Cg-compiler>=3.1
BUILDLINK_PKGSRCDIR.Cg-compiler?=	../../lang/Cg-compiler
.endif	# CG_COMPILER_BUILDLINK3_MK

BUILDLINK_TREE+=	-Cg-compiler
