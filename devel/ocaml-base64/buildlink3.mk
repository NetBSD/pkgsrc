# $NetBSD: buildlink3.mk,v 1.3 2018/01/10 16:53:08 jaapb Exp $

BUILDLINK_TREE+=	ocaml-base64

.if !defined(OCAML_BASE64_BUILDLINK3_MK)
OCAML_BASE64_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-base64+=	ocaml-base64>=2.0.0
BUILDLINK_API_DEPENDS.ocaml-base64+=	ocaml-base64>=2.2.0nb2
BUILDLINK_PKGSRCDIR.ocaml-base64?=	../../devel/ocaml-base64
.endif	# OCAML_BASE64_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-base64
