# $NetBSD: buildlink3.mk,v 1.5 2022/05/24 18:59:25 jaapb Exp $

BUILDLINK_TREE+=	ocaml-js-build-tools

.if !defined(OCAML_JS_BUILD_TOOLS_BUILDLINK3_MK)
OCAML_JS_BUILD_TOOLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-js-build-tools+=	ocaml-js-build-tools>=113.33.04
BUILDLINK_ABI_DEPENDS.ocaml-js-build-tools+=	ocaml-js-build-tools>=113.33.06nb8
BUILDLINK_PKGSRCDIR.ocaml-js-build-tools?=	../../devel/ocaml-js-build-tools

.endif	# OCAML_JS_BUILD_TOOLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-js-build-tools
