# $NetBSD: buildlink3.mk,v 1.3 2022/05/24 18:51:48 jaapb Exp $

BUILDLINK_TREE+=	ocaml-csexp

.if !defined(OCAML_CSEXP_BUILDLINK3_MK)
OCAML_CSEXP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-csexp+=	ocaml-csexp>=1.3.2
BUILDLINK_ABI_DEPENDS.ocaml-csexp+=	ocaml-csexp>=1.5.1nb1
BUILDLINK_PKGSRCDIR.ocaml-csexp?=	../../devel/ocaml-csexp

.endif	# OCAML_CSEXP_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-csexp
