# $NetBSD: buildlink3.mk,v 1.1 2019/03/25 09:24:16 jaapb Exp $

BUILDLINK_TREE+=	ocaml-base_bigstring

.if !defined(OCAML_BASE_BIGSTRING_BUILDLINK3_MK)
OCAML_BASE_BIGSTRING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-base_bigstring+=	ocaml-base_bigstring>=0.12.0
BUILDLINK_PKGSRCDIR.ocaml-base_bigstring?=	../../devel/ocaml-base_bigstring

.endif	# OCAML_BASE_BIGSTRING_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-base_bigstring
