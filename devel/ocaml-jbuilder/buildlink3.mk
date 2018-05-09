# $NetBSD: buildlink3.mk,v 1.6 2018/05/09 12:49:17 jaapb Exp $

BUILDLINK_TREE+=	ocaml-jbuilder

.if !defined(OCAML_JBUILDER_BUILDLINK3_MK)
OCAML_JBUILDER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-jbuilder+=	ocaml-jbuilder>=1.0_beta13nb1
BUILDLINK_ABI_DEPENDS.ocaml-jbuilder+=	ocaml-jbuilder>=1.0_beta20
BUILDLINK_PKGSRCDIR.ocaml-jbuilder?=	../../devel/ocaml-jbuilder
.endif	# OCAML_JBUILDER_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-jbuilder
