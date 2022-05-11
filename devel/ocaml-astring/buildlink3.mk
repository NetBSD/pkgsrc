# $NetBSD: buildlink3.mk,v 1.2 2022/05/11 08:26:28 jaapb Exp $

BUILDLINK_TREE+=	ocaml-astring

.if !defined(OCAML_ASTRING_BUILDLINK3_MK)
OCAML_ASTRING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-astring+=	ocaml-astring>=0.8.3
BUILDLINK_ABI_DEPENDS.ocaml-astring+=	ocaml-astring>=0.8.5
BUILDLINK_PKGSRCDIR.ocaml-astring?=	../../devel/ocaml-astring
.endif	# OCAML_ASTRING_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-astring
