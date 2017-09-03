# $NetBSD: buildlink3.mk,v 1.3 2017/09/03 11:59:15 jaapb Exp $

BUILDLINK_TREE+=	ocaml-batteries

.if !defined(OCAML_BATTERIES_BUILDLINK3_MK)
OCAML_BATTERIES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-batteries+=	ocaml-batteries>=2.0
BUILDLINK_ABI_DEPENDS.ocaml-batteries+=	ocaml-batteries>=2.7.0
BUILDLINK_PKGSRCDIR.ocaml-batteries?=	../../devel/ocaml-batteries

.endif	# OCAML_BATTERIES_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-batteries
