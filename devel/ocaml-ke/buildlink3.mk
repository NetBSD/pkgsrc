# $NetBSD: buildlink3.mk,v 1.2 2022/05/24 18:59:25 jaapb Exp $

BUILDLINK_TREE+=	ocaml-ke

.if !defined(OCAML_KE_BUILDLINK3_MK)
OCAML_KE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-ke+=	ocaml-ke>=0.4
BUILDLINK_ABI_DEPENDS.ocaml-ke+=	ocaml-ke>=0.4nb2
BUILDLINK_PKGSRCDIR.ocaml-ke?=		../../devel/ocaml-ke

.endif	# OCAML_KE_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-ke
