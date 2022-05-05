# $NetBSD: buildlink3.mk,v 1.1 2022/05/05 06:01:03 jaapb Exp $

BUILDLINK_TREE+=	ocaml-ppx_ignore_instrumentation

.if !defined(OCAML_PPX_IGNORE_INSTRUMENTATION_BUILDLINK3_MK)
OCAML_PPX_IGNORE_INSTRUMENTATION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-ppx_ignore_instrumentation+=	ocaml-ppx_ignore_instrumentation>=0.15.0
BUILDLINK_PKGSRCDIR.ocaml-ppx_ignore_instrumentation?=		../../devel/ocaml-ppx_ignore_instrumentation

.include "../../devel/ocaml-ppxlib/buildlink3.mk"
.endif	# OCAML_PPX_IGNORE_INSTRUMENTATION_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-ppx_ignore_instrumentation
