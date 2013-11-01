# $NetBSD: buildlink3.mk,v 1.1 2013/11/01 11:40:00 jaapb Exp $

BUILDLINK_TREE+=	optcomp

.if !defined(OPTCOMP_BUILDLINK3_MK)
OPTCOMP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.optcomp+=	optcomp>=1.4
BUILDLINK_PKGSRCDIR.optcomp?=	../../devel/ocaml-optcomp

.include "../../lang/ocaml/buildlink3.mk"
.endif	# OPTCOMP_BUILDLINK3_MK

BUILDLINK_TREE+=	-optcomp
