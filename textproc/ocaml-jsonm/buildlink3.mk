# $NetBSD: buildlink3.mk,v 1.5 2022/05/24 18:51:55 jaapb Exp $

BUILDLINK_TREE+=	ocaml-jsonm

.if !defined(OCAML_JSONM_BUILDLINK3_MK)
OCAML_JSONM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-jsonm+=	ocaml-jsonm>=0.9.1
BUILDLINK_ABI_DEPENDS.ocaml-jsonm+=	ocaml-jsonm>=1.0.1nb7
BUILDLINK_PKGSRCDIR.ocaml-jsonm?=	../../textproc/ocaml-jsonm

.include "../../textproc/ocaml-uutf/buildlink3.mk"
.endif	# OCAML_JSONM_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-jsonm
