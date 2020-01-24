# $NetBSD: buildlink3.mk,v 1.2 2020/01/24 16:27:41 jaapb Exp $

BUILDLINK_TREE+=	ocaml-stringext

.if !defined(OCAML_STRINGEXT_BUILDLINK3_MK)
OCAML_STRINGEXT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-stringext+=	ocaml-stringext>=1.5.0
BUILDLINK_ABI_DEPENDS.ocaml-stringext+=	ocaml-stringext>=1.6.0
BUILDLINK_PKGSRCDIR.ocaml-stringext?=	../../devel/ocaml-stringext
.endif	# OCAML_STRINGEXT_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-stringext
