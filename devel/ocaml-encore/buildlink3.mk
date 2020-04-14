# $NetBSD: buildlink3.mk,v 1.2 2020/04/14 08:56:07 jaapb Exp $

BUILDLINK_TREE+=	ocaml-encore

.if !defined(OCAML_ENCORE_BUILDLINK3_MK)
OCAML_ENCORE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-encore+=	ocaml-encore>=0.2
BUILDLINK_ABI_DEPENDS.ocaml-encore+=	ocaml-encore>=0.4
BUILDLINK_PKGSRCDIR.ocaml-encore?=	../../devel/ocaml-encore

.endif	# OCAML_ENCORE_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-encore
