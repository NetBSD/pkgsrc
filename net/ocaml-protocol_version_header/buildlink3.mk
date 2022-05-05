# $NetBSD: buildlink3.mk,v 1.3 2022/05/05 08:25:44 jaapb Exp $

BUILDLINK_TREE+=	ocaml-protocol_version_header

.if !defined(OCAML_PROTOCOL_VERSION_HEADER_BUILDLINK3_MK)
OCAML_PROTOCOL_VERSION_HEADER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-protocol_version_header+=	ocaml-protocol_version_header>=0.12.0
BUILDLINK_ABI_DEPENDS.ocaml-protocol_version_header+=	ocaml-protocol_version_header>=0.15.0

BUILDLINK_PKGSRCDIR.ocaml-protocol_version_header?=	../../net/ocaml-protocol_version_header

.endif	# OCAML_PROTOCOL_VERSION_HEADER_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-protocol_version_header
