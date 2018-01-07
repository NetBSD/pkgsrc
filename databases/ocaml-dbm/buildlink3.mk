# $NetBSD: buildlink3.mk,v 1.11 2018/01/07 13:03:59 rillig Exp $

BUILDLINK_TREE+=	ocaml-dbm

.if !defined(OCAML_DBM_BUILDLINK3_MK)
OCAML_DBM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-dbm+=	ocaml-dbm>=1.0
BUILDLINK_ABI_DEPENDS.ocaml-dbm?=	ocaml-dbm>=1.0nb12
BUILDLINK_PKGSRCDIR.ocaml-dbm?=		../../databases/ocaml-dbm

.include "../../databases/gdbm/buildlink3.mk"
.include "../../lang/ocaml/buildlink3.mk"
.endif	# OCAML_DBM_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-dbm
