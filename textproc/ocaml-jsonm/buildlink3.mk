# $NetBSD: buildlink3.mk,v 1.1 2014/11/06 11:37:33 jaapb Exp $

BUILDLINK_TREE+=	ocaml-jsonm

.if !defined(OCAML_JSONM_BUILDLINK3_MK)
OCAML_JSONM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-jsonm+=	ocaml-jsonm>=0.9.1
BUILDLINK_PKGSRCDIR.ocaml-jsonm?=	../../textproc/ocaml-jsonm

.include "../../textproc/ocaml-uutf/buildlink3.mk"
.endif	# OCAML_JSONM_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-jsonm
