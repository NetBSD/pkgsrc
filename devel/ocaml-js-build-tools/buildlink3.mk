# $NetBSD: buildlink3.mk,v 1.1 2016/06/20 14:50:12 jaapb Exp $

BUILDLINK_TREE+=	ocaml-js-build-tools

.if !defined(OCAML_JS_BUILD_TOOLS_BUILDLINK3_MK)
OCAML_JS_BUILD_TOOLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-js-build-tools+=	ocaml-js-build-tools>=113.33.04
BUILDLINK_PKGSRCDIR.ocaml-js-build-tools?=	../../devel/ocaml-js-build-tools

.endif	# OCAML_JS_BUILD_TOOLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-js-build-tools
