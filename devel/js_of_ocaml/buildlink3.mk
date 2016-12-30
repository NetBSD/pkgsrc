# $NetBSD: buildlink3.mk,v 1.2 2016/12/30 12:04:25 jaapb Exp $

BUILDLINK_TREE+=	js_of_ocaml

.if !defined(JS_OF_OCAML_BUILDLINK3_MK)
JS_OF_OCAML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.js_of_ocaml+=	js_of_ocaml>=2.8.3
BUILDLINK_PKGSRCDIR.js_of_ocaml?=	../../devel/js_of_ocaml

.endif	# JS_OF_OCAML_BUILDLINK3_MK

BUILDLINK_TREE+=	-js_of_ocaml
