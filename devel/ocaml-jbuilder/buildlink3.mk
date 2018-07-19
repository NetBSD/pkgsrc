# $NetBSD: buildlink3.mk,v 1.7 2018/07/19 15:15:22 jaapb Exp $

BUILDLINK_TREE+=	ocaml-jbuilder

.if !defined(OCAML_JBUILDER_BUILDLINK3_MK)
OCAML_JBUILDER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-jbuilder+=	ocaml-jbuilder>=1.0_beta13nb1
BUILDLINK_ABI_DEPENDS.ocaml-jbuilder+=	ocaml-jbuilder>=1.0_beta20nb1
BUILDLINK_PKGSRCDIR.ocaml-jbuilder?=	../../devel/ocaml-jbuilder
.endif	# OCAML_JBUILDER_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-jbuilder
