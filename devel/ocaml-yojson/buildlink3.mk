# $NetBSD: buildlink3.mk,v 1.1 2017/07/11 11:29:56 jaapb Exp $

BUILDLINK_TREE+=	ocaml-yojson

.if !defined(OCAML_YOJSON_BUILDLINK3_MK)
OCAML_YOJSON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-yojson+=	ocaml-yojson>=1.3.3
BUILDLINK_PKGSRCDIR.ocaml-yojson?=	../../devel/ocaml-yojson

.endif	# OCAML_YOJSON_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-yojson
