# $NetBSD: buildlink3.mk,v 1.4 2015/01/20 16:12:12 jaapb Exp $

BUILDLINK_TREE+=	ocaml-optcomp

.if !defined(OCAML_OPTCOMP_BUILDLINK3_MK)
OCAML_OPTCOMP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-optcomp+=	ocaml-optcomp>=1.6nb1
BUILDLINK_PKGSRCDIR.ocaml-optcomp?=	../../devel/ocaml-optcomp

.include "../../lang/camlp4/buildlink3.mk"
.endif	# OCAML_OPTCOMP_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-optcomp
