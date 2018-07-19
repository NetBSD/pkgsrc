# $NetBSD: buildlink3.mk,v 1.4 2018/07/19 15:15:29 jaapb Exp $

BUILDLINK_TREE+=	ocaml-jsonm

.if !defined(OCAML_JSONM_BUILDLINK3_MK)
OCAML_JSONM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-jsonm+=	ocaml-jsonm>=0.9.1
BUILDLINK_ABI_DEPENDS.ocaml-jsonm+=	ocaml-jsonm>=1.0.1nb4
BUILDLINK_PKGSRCDIR.ocaml-jsonm?=	../../textproc/ocaml-jsonm

.include "../../textproc/ocaml-uutf/buildlink3.mk"
.endif	# OCAML_JSONM_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-jsonm
