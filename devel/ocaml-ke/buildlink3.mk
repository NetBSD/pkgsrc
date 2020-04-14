# $NetBSD: buildlink3.mk,v 1.1 2020/04/14 08:18:30 jaapb Exp $

BUILDLINK_TREE+=	ocaml-ke

.if !defined(OCAML_KE_BUILDLINK3_MK)
OCAML_KE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-ke+=	ocaml-ke>=0.4
BUILDLINK_PKGSRCDIR.ocaml-ke?=		../../devel/ocaml-ke

.endif	# OCAML_KE_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-ke
