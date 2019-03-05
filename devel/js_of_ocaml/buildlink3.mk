# $NetBSD: buildlink3.mk,v 1.14 2019/03/05 17:31:04 jaapb Exp $

BUILDLINK_TREE+=	js_of_ocaml

.if !defined(JS_OF_OCAML_BUILDLINK3_MK)
JS_OF_OCAML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.js_of_ocaml+=	js_of_ocaml>=3.0.0
BUILDLINK_ABI_DEPENDS.js_of_ocaml+=	js_of_ocaml>=3.3.0nb1
BUILDLINK_PKGSRCDIR.js_of_ocaml?=	../../devel/js_of_ocaml

.endif	# JS_OF_OCAML_BUILDLINK3_MK

BUILDLINK_TREE+=	-js_of_ocaml
