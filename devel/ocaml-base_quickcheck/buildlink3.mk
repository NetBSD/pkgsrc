# $NetBSD: buildlink3.mk,v 1.2 2020/01/16 13:31:13 jaapb Exp $

BUILDLINK_TREE+=	ocaml-base_quickcheck

.if !defined(OCAML_BASE_QUICKCHECK_BUILDLINK3_MK)
OCAML_BASE_QUICKCHECK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-base_quickcheck+=	ocaml-base_quickcheck>=0.13.0
BUILDLINK_PKGSRCDIR.ocaml-base_quickcheck?=	../../devel/ocaml-base_quickcheck

.endif	# OCAML_BASE_QUICKCHECK_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-base_quickcheck
