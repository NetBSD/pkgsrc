# $NetBSD: buildlink3.mk,v 1.2 2017/07/11 13:56:49 jaapb Exp $

BUILDLINK_TREE+=	ocaml-js-build-tools

.if !defined(OCAML_JS_BUILD_TOOLS_BUILDLINK3_MK)
OCAML_JS_BUILD_TOOLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-js-build-tools+=	ocaml-js-build-tools>=113.33.04
BUILDLINK_ABI_DEPENDS.ocaml-js-build-tools+=	ocaml-js-build-tools>=113.33.06
BUILDLINK_PKGSRCDIR.ocaml-js-build-tools?=	../../devel/ocaml-js-build-tools

.endif	# OCAML_JS_BUILD_TOOLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-js-build-tools
