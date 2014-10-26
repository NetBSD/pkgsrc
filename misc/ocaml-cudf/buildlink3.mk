# $NetBSD: buildlink3.mk,v 1.1 2014/10/26 14:15:45 jaapb Exp $

BUILDLINK_TREE+=	ocaml-cudf

.if !defined(OCAML_CUDF_BUILDLINK3_MK)
OCAML_CUDF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-cudf+=	ocaml-cudf>=0.7
BUILDLINK_PKGSRCDIR.ocaml-cudf?=	../../misc/ocaml-cudf

.include "../../devel/ocaml-extlib/buildlink3.mk"
.endif	# OCAML_CUDF_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-cudf
