# $NetBSD: buildlink3.mk,v 1.6 2022/05/02 18:17:18 jaapb Exp $

BUILDLINK_TREE+=	ocaml-uutf

.if !defined(OCAML_UUTF_BUILDLINK3_MK)
OCAML_UUTF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-uutf+=	ocaml-uutf>=0.9.3nb1
BUILDLINK_ABI_DEPENDS.ocaml-uutf+=	ocaml-uutf>=1.0.3
BUILDLINK_PKGSRCDIR.ocaml-uutf?=	../../textproc/ocaml-uutf
.endif	# OCAML_UUTF_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-uutf
