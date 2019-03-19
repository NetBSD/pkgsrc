# $NetBSD: buildlink3.mk,v 1.1 2019/03/19 11:07:40 jaapb Exp $
BUILDLINK_TREE+=	ocaml-angstrom

.if !defined(OCAML_ANGSTROM_BUILDLINK3_MK)
OCAML_ANGSTROM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-angstrom+=	ocaml-angstrom>=0.11.1
BUILDLINK_PKGSRCDIR.ocaml-angstrom?=	../../devel/ocaml-angstrom
.endif	# OCAML_ANGSTROM_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-angstrom
