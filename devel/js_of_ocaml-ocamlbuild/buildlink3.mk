# $NetBSD: buildlink3.mk,v 1.2 2022/05/23 15:27:15 jaapb Exp $

BUILDLINK_TREE+=	js_of_ocaml-ocamlbuild

.if !defined(JS_OF_OCAML_OCAMLBUILD_BUILDLINK3_MK)
JS_OF_OCAML_OCAMLBUILD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.js_of_ocaml-ocamlbuild+=	js_of_ocaml-ocamlbuild>=0.0.0.3693
BUILDLINK_PKGSRCDIR.js_of_ocaml-ocamlbuild?=	../../devel/js_of_ocaml-ocamlbuild

# We only need this to install
BUILDLINK_DEPMETHOD.js_of_ocaml-ocamlbuild?=	build

.include "../../devel/ocamlbuild/buildlink3.mk"
.endif	# JS_OF_OCAML_OCAMLBUILD_BUILDLINK3_MK

BUILDLINK_TREE+=	-js_of_ocaml-ocamlbuild
