# $NetBSD: buildlink3.mk,v 1.6 2018/07/19 15:15:26 jaapb Exp $

BUILDLINK_TREE+=	ocamlify

.if !defined(OCAMLIFY_BUILDLINK3_MK)
OCAMLIFY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocamlify+=	ocamlify>=0.0.2nb1
BUILDLINK_ABI_DEPENDS.ocamlify+=	ocamlify>=0.0.2nb9
BUILDLINK_PKGSRCDIR.ocamlify?=	../../devel/ocamlify
.endif	# OCAMLIFY_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocamlify
