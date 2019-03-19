# $NetBSD: buildlink3.mk,v 1.1 2019/03/19 14:24:26 jaapb Exp $

BUILDLINK_TREE+=	ocaml-stringext

.if !defined(OCAML_STRINGEXT_BUILDLINK3_MK)
OCAML_STRINGEXT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-stringext+=	ocaml-stringext>=1.5.0
BUILDLINK_PKGSRCDIR.ocaml-stringext?=	../../devel/ocaml-stringext
.endif	# OCAML_STRINGEXT_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-stringext
