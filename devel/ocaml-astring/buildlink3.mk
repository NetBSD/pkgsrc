# $NetBSD: buildlink3.mk,v 1.1 2019/03/12 18:04:58 jaapb Exp $

BUILDLINK_TREE+=	ocaml-astring

.if !defined(OCAML_ASTRING_BUILDLINK3_MK)
OCAML_ASTRING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-astring+=	ocaml-astring>=0.8.3
BUILDLINK_PKGSRCDIR.ocaml-astring?=	../../devel/ocaml-astring
.endif	# OCAML_ASTRING_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-astring
