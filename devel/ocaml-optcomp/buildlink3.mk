# $NetBSD: buildlink3.mk,v 1.7 2018/01/22 11:22:40 jaapb Exp $

BUILDLINK_TREE+=	ocaml-optcomp

.if !defined(OCAML_OPTCOMP_BUILDLINK3_MK)
OCAML_OPTCOMP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-optcomp+=	ocaml-optcomp>=1.6nb1
BUILDLINK_ABI_DEPENDS.ocaml-optcomp+=	ocaml-optcomp>=1.6nb9
BUILDLINK_PKGSRCDIR.ocaml-optcomp?=	../../devel/ocaml-optcomp

.include "../../lang/camlp4/buildlink3.mk"
.endif	# OCAML_OPTCOMP_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-optcomp
