# $NetBSD: buildlink3.mk,v 1.1 2016/02/06 13:28:07 jaapb Exp $

BUILDLINK_TREE+=	ocaml-base64

.if !defined(OCAML_BASE64_BUILDLINK3_MK)
OCAML_BASE64_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-base64+=	ocaml-base64>=2.0.0
BUILDLINK_PKGSRCDIR.ocaml-base64?=	../../devel/ocaml-base64
.endif	# OCAML_BASE64_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-base64
