# $NetBSD: buildlink3.mk,v 1.6 2022/05/11 13:26:05 jaapb Exp $

BUILDLINK_TREE+=	ocaml-base64

.if !defined(OCAML_BASE64_BUILDLINK3_MK)
OCAML_BASE64_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-base64+=	ocaml-base64>=3.5.0
BUILDLINK_ABI_DEPENDS.ocaml-base64+=	ocaml-base64>=3.5.0
BUILDLINK_PKGSRCDIR.ocaml-base64?=	../../devel/ocaml-base64
.endif	# OCAML_BASE64_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-base64
