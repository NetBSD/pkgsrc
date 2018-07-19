# $NetBSD: buildlink3.mk,v 1.2 2018/07/19 14:18:09 jaapb Exp $

BUILDLINK_TREE+=	ocaml-yojson

.if !defined(OCAML_YOJSON_BUILDLINK3_MK)
OCAML_YOJSON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-yojson+=	ocaml-yojson>=1.3.3
BUILDLINK_ABI_DEPENDS.ocaml-yojson+=	ocaml-yojson>=1.4.1nb2
BUILDLINK_PKGSRCDIR.ocaml-yojson?=	../../devel/ocaml-yojson

.endif	# OCAML_YOJSON_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-yojson
