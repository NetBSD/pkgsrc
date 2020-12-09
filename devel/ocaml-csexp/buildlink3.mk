# $NetBSD: buildlink3.mk,v 1.1 2020/12/09 11:10:47 jaapb Exp $

BUILDLINK_TREE+=	ocaml-csexp

.if !defined(OCAML_CSEXP_BUILDLINK3_MK)
OCAML_CSEXP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-csexp+=	ocaml-csexp>=1.3.2
BUILDLINK_PKGSRCDIR.ocaml-csexp?=	../../devel/ocaml-csexp

.endif	# OCAML_CSEXP_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-csexp
