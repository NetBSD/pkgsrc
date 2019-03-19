# $NetBSD: buildlink3.mk,v 1.1 2019/03/19 11:35:33 jaapb Exp $

BUILDLINK_TREE+=	ocaml-ocplib-endian

.if !defined(OCAML_OCPLIB_ENDIAN_BUILDLINK3_MK)
OCAML_OCPLIB_ENDIAN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-ocplib-endian+=	ocaml-ocplib-endian>=1.0
BUILDLINK_PKGSRCDIR.ocaml-ocplib-endian?=	../../devel/ocaml-ocplib-endian

.endif	# OCAML_OCPLIB_ENDIAN_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-ocplib-endian
