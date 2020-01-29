# $NetBSD: buildlink3.mk,v 1.11 2020/01/29 08:28:44 jaapb Exp $

BUILDLINK_TREE+=	ocaml-migrate-parsetree

.if !defined(OCAML_MIGRATE_PARSETREE_BUILDLINK3_MK)
OCAML_MIGRATE_PARSETREE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-migrate-parsetree+=	ocaml-migrate-parsetree>=1.0.1
BUILDLINK_ABI_DEPENDS.ocaml-migrate-parsetree+=	ocaml-migrate-parsetree>=1.5.0
BUILDLINK_PKGSRCDIR.ocaml-migrate-parsetree?=	../../devel/ocaml-migrate-parsetree
.endif	# OCAML_MIGRATE_PARSETREE_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-migrate-parsetree
