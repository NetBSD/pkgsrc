# $NetBSD: buildlink3.mk,v 1.2 2016/06/17 16:15:48 jaapb Exp $

BUILDLINK_TREE+=	ocaml-cudf

.if !defined(OCAML_CUDF_BUILDLINK3_MK)
OCAML_CUDF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-cudf+=	ocaml-cudf>=0.8
BUILDLINK_PKGSRCDIR.ocaml-cudf?=	../../misc/ocaml-cudf

.include "../../devel/ocaml-extlib/buildlink3.mk"
.endif	# OCAML_CUDF_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-cudf
