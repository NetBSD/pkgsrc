# $NetBSD: buildlink3.mk,v 1.2 2022/05/11 10:20:21 jaapb Exp $

BUILDLINK_TREE+=	ocaml-angstrom

.if !defined(OCAML_ANGSTROM_BUILDLINK3_MK)
OCAML_ANGSTROM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-angstrom+=	ocaml-angstrom>=0.14.0
BUILDLINK_ABI_DEPENDS.ocaml-angstrom+=	ocaml-angstrom>=0.15.0
BUILDLINK_PKGSRCDIR.ocaml-angstrom?=	../../devel/ocaml-angstrom
.endif	# OCAML_ANGSTROM_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-angstrom
