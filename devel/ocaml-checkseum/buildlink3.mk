# $NetBSD: buildlink3.mk,v 1.3 2022/03/21 07:52:04 jaapb Exp $

BUILDLINK_TREE+=	ocaml-checkseum

.if !defined(OCAML_CHECKSEUM_BUILDLINK3_MK)
OCAML_CHECKSEUM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-checkseum+=	ocaml-checkseum>=0.0.3
BUILDLINK_ABI_DEPENDS.ocaml-checkseum+=	ocaml-checkseum>=0.3.1nb1
BUILDLINK_PKGSRCDIR.ocaml-checkseum?=	../../devel/ocaml-checkseum

.endif	# OCAML_CHECKSEUM_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-checkseum
