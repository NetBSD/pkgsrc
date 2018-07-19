# $NetBSD: buildlink3.mk,v 1.2 2018/07/19 15:15:28 jaapb Exp $

BUILDLINK_TREE+=	ocaml-safepass

.if !defined(OCAML_SAFEPASS_BUILDLINK3_MK)
OCAML_SAFEPASS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-safepass+=	ocaml-safepass>=2.0
BUILDLINK_ABI_DEPENDS.ocaml-safepass+=	ocaml-safepass>=2.0nb1
BUILDLINK_PKGSRCDIR.ocaml-safepass?=	../../security/ocaml-safepass
.endif	# OCAML_SAFEPASS_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-safepass
