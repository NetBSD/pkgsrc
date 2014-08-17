# $NetBSD: buildlink3.mk,v 1.1 2014/08/17 13:38:10 jaapb Exp $

BUILDLINK_TREE+=	ocamlify

.if !defined(OCAMLIFY_BUILDLINK3_MK)
OCAMLIFY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocamlify+=	ocamlify>=0.0.2
BUILDLINK_PKGSRCDIR.ocamlify?=	../../devel/ocamlify
.endif	# OCAMLIFY_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocamlify
