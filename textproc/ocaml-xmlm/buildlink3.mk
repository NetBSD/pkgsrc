# $NetBSD: buildlink3.mk,v 1.1 2026/01/25 14:00:06 alnsn Exp $

BUILDLINK_TREE+=	ocaml-xmlm

.if !defined(OCAML_XMLM_BUILDLINK3_MK)
OCAML_XMLM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-xmlm+=	ocaml-xmlm>=1.4.0
BUILDLINK_ABI_DEPENDS.ocaml-xmlm+=	ocaml-xmlm>=1.4.0
BUILDLINK_PKGSRCDIR.ocaml-xmlm?=	../../textproc/ocaml-xmlm
.endif	# OCAML_XMLM_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-xmlm
