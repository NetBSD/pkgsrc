# $NetBSD: buildlink3.mk,v 1.2 2019/07/01 12:32:56 jaapb Exp $

BUILDLINK_TREE+=	ocaml-checkseum

.if !defined(OCAML_CHECKSEUM_BUILDLINK3_MK)
OCAML_CHECKSEUM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-checkseum+=	ocaml-checkseum>=0.0.3
BUILDLINK_ABI_DEPENDS.ocaml-checkseum+=	ocaml-checkseum>=0.1.0
BUILDLINK_PKGSRCDIR.ocaml-checkseum?=	../../devel/ocaml-checkseum

.endif	# OCAML_CHECKSEUM_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-checkseum
