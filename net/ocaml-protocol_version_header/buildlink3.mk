# $NetBSD: buildlink3.mk,v 1.2 2020/04/08 09:34:28 jaapb Exp $

BUILDLINK_TREE+=	ocaml-protocol_version_header

.if !defined(OCAML_PROTOCOL_VERSION_HEADER_BUILDLINK3_MK)
OCAML_PROTOCOL_VERSION_HEADER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-protocol_version_header+=	ocaml-protocol_version_header>=0.12.0
BUILDLINK_ABI_DEPENDS.ocaml-protocol_version_header+=	ocaml-protocol_version_header>=0.13.0

BUILDLINK_PKGSRCDIR.ocaml-protocol_version_header?=	../../net/ocaml-protocol_version_header

.endif	# OCAML_PROTOCOL_VERSION_HEADER_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-protocol_version_header
