# $NetBSD: buildlink3.mk,v 1.5 2017/09/08 09:51:21 jaapb Exp $

BUILDLINK_TREE+=	ocaml-optcomp

.if !defined(OCAML_OPTCOMP_BUILDLINK3_MK)
OCAML_OPTCOMP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-optcomp+=	ocaml-optcomp>=1.6nb1
BUILDLINK_ABI_DEPENDS.ocaml-optcomp+=	ocaml-optcomp>=1.6nb6
BUILDLINK_PKGSRCDIR.ocaml-optcomp?=	../../devel/ocaml-optcomp

.include "../../lang/camlp4/buildlink3.mk"
.endif	# OCAML_OPTCOMP_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-optcomp
