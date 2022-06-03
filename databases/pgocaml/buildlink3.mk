# $NetBSD: buildlink3.mk,v 1.10 2022/06/03 13:17:35 jaapb Exp $

BUILDLINK_TREE+=	pgocaml

.if !defined(PGOCAML_BUILDLINK3_MK)
PGOCAML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pgocaml+=	pgocaml>=4.0
BUILDLINK_ABI_DEPENDS.pgocaml+=	pgocaml>=4.3.0nb1
BUILDLINK_PKGSRCDIR.pgocaml?=	../../databases/pgocaml

.include "../../devel/ocaml-re/buildlink3.mk"
.include "../../devel/ocaml-rresult/buildlink3.mk"
.include "../../textproc/ocaml-csv/buildlink3.mk"
.include "../../time/ocaml-calendar/buildlink3.mk"
.endif	# PGOCAML_BUILDLINK3_MK

BUILDLINK_TREE+=	-pgocaml
