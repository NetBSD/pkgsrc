# $NetBSD: buildlink3.mk,v 1.6 2018/01/22 11:50:24 jaapb Exp $

BUILDLINK_TREE+=	js_of_ocaml

.if !defined(JS_OF_OCAML_BUILDLINK3_MK)
JS_OF_OCAML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.js_of_ocaml+=	js_of_ocaml>=3.0.0
BUILDLINK_ABI_DEPENDS.js_of_ocaml+=	js_of_ocaml>=3.0.2
BUILDLINK_PKGSRCDIR.js_of_ocaml?=	../../devel/js_of_ocaml

.endif	# JS_OF_OCAML_BUILDLINK3_MK

BUILDLINK_TREE+=	-js_of_ocaml
