# $NetBSD: buildlink3.mk,v 1.5 2019/03/05 19:38:49 jaapb Exp $

BUILDLINK_TREE+=	ocaml-safepass

.if !defined(OCAML_SAFEPASS_BUILDLINK3_MK)
OCAML_SAFEPASS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-safepass+=	ocaml-safepass>=2.0
BUILDLINK_ABI_DEPENDS.ocaml-safepass+=	ocaml-safepass>=3.0nb3
BUILDLINK_PKGSRCDIR.ocaml-safepass?=	../../security/ocaml-safepass
.endif	# OCAML_SAFEPASS_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-safepass
