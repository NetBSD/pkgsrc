# $NetBSD: buildlink3.mk,v 1.2 2022/05/24 18:59:24 jaapb Exp $

BUILDLINK_TREE+=	ocaml-duff

.if !defined(OCAML_DUFF_BUILDLINK3_MK)
OCAML_DUFF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-duff+=	ocaml-duff>=0.2
BUILDLINK_ABI_DEPENDS.ocaml-duff+=	ocaml-duff>=0.2nb2
BUILDLINK_PKGSRCDIR.ocaml-duff?=	../../devel/ocaml-duff

.endif	# OCAML_DUFF_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-duff
