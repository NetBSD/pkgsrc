# $NetBSD: buildlink3.mk,v 1.3 2017/07/11 10:39:47 jaapb Exp $

BUILDLINK_TREE+=	ocaml-uutf

.if !defined(OCAML_UUTF_BUILDLINK3_MK)
OCAML_UUTF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-uutf+=	ocaml-uutf>=0.9.3nb1
BUILDLINK_ABI_DEPENDS.ocaml-uutf+=	ocaml-uutf>=1.0.1
BUILDLINK_PKGSRCDIR.ocaml-uutf?=	../../textproc/ocaml-uutf
.endif	# OCAML_UUTF_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-uutf
