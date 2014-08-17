# $NetBSD: buildlink3.mk,v 1.2 2014/08/17 12:11:07 jaapb Exp $

BUILDLINK_TREE+=	ocaml-optcomp

.if !defined(OCAML_OPTCOMP_BUILDLINK3_MK)
OCAML_OPTCOMP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-optcomp+=	ocaml-optcomp>=1.4
BUILDLINK_PKGSRCDIR.ocaml-optcomp?=	../../devel/ocaml-optcomp

.include "../../lang/ocaml/buildlink3.mk"
.endif	# OCAML_OPTCOMP_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-optcomp
