# $NetBSD: buildlink3.mk,v 1.2 2022/05/02 13:44:25 jaapb Exp $

BUILDLINK_TREE+=	ocaml-ocplib-endian

.if !defined(OCAML_OCPLIB_ENDIAN_BUILDLINK3_MK)
OCAML_OCPLIB_ENDIAN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-ocplib-endian+=	ocaml-ocplib-endian>=1.0
BUILDLINK_ABI_DEPENDS.ocaml-ocplib-endian+=	ocaml-ocplib-endian>=1.2
BUILDLINK_PKGSRCDIR.ocaml-ocplib-endian?=	../../devel/ocaml-ocplib-endian

.endif	# OCAML_OCPLIB_ENDIAN_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-ocplib-endian
