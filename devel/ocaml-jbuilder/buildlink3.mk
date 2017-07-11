# $NetBSD: buildlink3.mk,v 1.1 2017/07/11 11:14:58 jaapb Exp $

BUILDLINK_TREE+=	ocaml-jbuilder

.if !defined(OCAML_JBUILDER_BUILDLINK3_MK)
OCAML_JBUILDER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-jbuilder+=	ocaml-jbuilder>=1.0_beta10
BUILDLINK_PKGSRCDIR.ocaml-jbuilder?=	../../devel/ocaml-jbuilder
.endif	# OCAML_JBUILDER_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-jbuilder
