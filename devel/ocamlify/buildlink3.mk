# $NetBSD: buildlink3.mk,v 1.3 2017/07/11 14:19:22 jaapb Exp $

BUILDLINK_TREE+=	ocamlify

.if !defined(OCAMLIFY_BUILDLINK3_MK)
OCAMLIFY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocamlify+=	ocamlify>=0.0.2nb1
BUILDLINK_ABI_DEPENDS.ocamlify+=	ocamlify>=0.0.2nb5
BUILDLINK_PKGSRCDIR.ocamlify?=	../../devel/ocamlify
.endif	# OCAMLIFY_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocamlify
