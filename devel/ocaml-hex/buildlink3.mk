# $NetBSD: buildlink3.mk,v 1.1 2019/03/19 12:56:46 jaapb Exp $

BUILDLINK_TREE+=	ocaml-hex

.if !defined(OCAML_HEX_BUILDLINK3_MK)
OCAML_HEX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-hex+=	ocaml-hex>=1.3.0
BUILDLINK_PKGSRCDIR.ocaml-hex?=	../../devel/ocaml-hex

.endif	# OCAML_HEX_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-hex
