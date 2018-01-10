# $NetBSD: buildlink3.mk,v 1.3 2018/01/10 16:53:13 jaapb Exp $

BUILDLINK_TREE+=	ocaml-jsonm

.if !defined(OCAML_JSONM_BUILDLINK3_MK)
OCAML_JSONM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-jsonm+=	ocaml-jsonm>=0.9.1
BUILDLINK_ABI_DEPENDS.ocaml-jsonm+=	ocaml-jsonm>=1.0.1nb2
BUILDLINK_PKGSRCDIR.ocaml-jsonm?=	../../textproc/ocaml-jsonm

.include "../../textproc/ocaml-uutf/buildlink3.mk"
.endif	# OCAML_JSONM_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-jsonm
