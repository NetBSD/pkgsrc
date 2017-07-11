# $NetBSD: buildlink3.mk,v 1.3 2017/07/11 10:29:58 jaapb Exp $

BUILDLINK_TREE+=	ocaml-cudf

.if !defined(OCAML_CUDF_BUILDLINK3_MK)
OCAML_CUDF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-cudf+=	ocaml-cudf>=0.8
BUILDLINK_ABI_DEPENDS.ocaml-cudf+=	ocaml-cudf>=0.9
BUILDLINK_PKGSRCDIR.ocaml-cudf?=	../../misc/ocaml-cudf

.include "../../devel/ocaml-extlib/buildlink3.mk"
.endif	# OCAML_CUDF_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-cudf
