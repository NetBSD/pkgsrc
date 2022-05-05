# $NetBSD: buildlink3.mk,v 1.9 2022/05/05 12:11:18 jaapb Exp $

BUILDLINK_TREE+=	pgocaml

.if !defined(PGOCAML_BUILDLINK3_MK)
PGOCAML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pgocaml+=	pgocaml>=4.0
BUILDLINK_ABI_DEPENDS.pgocaml+=	pgocaml>=4.3.0
BUILDLINK_PKGSRCDIR.pgocaml?=	../../databases/pgocaml

.include "../../devel/ocaml-re/buildlink3.mk"
.include "../../textproc/ocaml-csv/buildlink3.mk"
.include "../../time/ocaml-calendar/buildlink3.mk"
.endif	# PGOCAML_BUILDLINK3_MK

BUILDLINK_TREE+=	-pgocaml
