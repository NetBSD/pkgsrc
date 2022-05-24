# $NetBSD: buildlink3.mk,v 1.5 2022/05/24 18:59:32 jaapb Exp $

BUILDLINK_TREE+=	ocaml-yojson

.if !defined(OCAML_YOJSON_BUILDLINK3_MK)
OCAML_YOJSON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-yojson+=	ocaml-yojson>=1.7.0
BUILDLINK_ABI_DEPENDS.ocaml-yojson+=	ocaml-yojson>=1.7.0nb2
BUILDLINK_PKGSRCDIR.ocaml-yojson?=	../../devel/ocaml-yojson

.endif	# OCAML_YOJSON_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-yojson
