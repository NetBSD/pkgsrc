# $NetBSD: buildlink3.mk,v 1.3 2022/05/24 18:59:24 jaapb Exp $

BUILDLINK_TREE+=	ocaml-encore

.if !defined(OCAML_ENCORE_BUILDLINK3_MK)
OCAML_ENCORE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-encore+=	ocaml-encore>=0.2
BUILDLINK_ABI_DEPENDS.ocaml-encore+=	ocaml-encore>=0.4nb2
BUILDLINK_PKGSRCDIR.ocaml-encore?=	../../devel/ocaml-encore

.endif	# OCAML_ENCORE_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-encore
