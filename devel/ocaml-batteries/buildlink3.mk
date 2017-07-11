# $NetBSD: buildlink3.mk,v 1.2 2017/07/11 11:34:25 jaapb Exp $

BUILDLINK_TREE+=	ocaml-batteries

.if !defined(OCAML_BATTERIES_BUILDLINK3_MK)
OCAML_BATTERIES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-batteries+=	ocaml-batteries>=2.0
BUILDLINK_ABI_DEPENDS.ocaml-batteries+=	ocaml-batteries>=2.6.0
BUILDLINK_PKGSRCDIR.ocaml-batteries?=	../../devel/ocaml-batteries

.endif	# OCAML_BATTERIES_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-batteries
