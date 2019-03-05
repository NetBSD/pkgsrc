# $NetBSD: buildlink3.mk,v 1.4 2019/03/05 18:21:04 jaapb Exp $

BUILDLINK_TREE+=	ocaml-yojson

.if !defined(OCAML_YOJSON_BUILDLINK3_MK)
OCAML_YOJSON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-yojson+=	ocaml-yojson>=1.7.0
BUILDLINK_ABI_DEPENDS.ocaml-yojson+=	ocaml-yojson>=1.7.0
BUILDLINK_PKGSRCDIR.ocaml-yojson?=	../../devel/ocaml-yojson

.endif	# OCAML_YOJSON_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-yojson
