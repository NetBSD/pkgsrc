# $NetBSD: buildlink3.mk,v 1.8 2018/07/19 15:15:23 jaapb Exp $

BUILDLINK_TREE+=	ocaml-optcomp

.if !defined(OCAML_OPTCOMP_BUILDLINK3_MK)
OCAML_OPTCOMP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-optcomp+=	ocaml-optcomp>=1.6nb1
BUILDLINK_ABI_DEPENDS.ocaml-optcomp+=	ocaml-optcomp>=1.6nb11
BUILDLINK_PKGSRCDIR.ocaml-optcomp?=	../../devel/ocaml-optcomp

.include "../../lang/camlp4/buildlink3.mk"
.endif	# OCAML_OPTCOMP_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-optcomp
