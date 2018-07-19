# $NetBSD: buildlink3.mk,v 1.4 2018/07/19 13:47:36 jaapb Exp $

BUILDLINK_TREE+=	pgocaml

.if !defined(PGOCAML_BUILDLINK3_MK)
PGOCAML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pgocaml+=	pgocaml>=2.3
BUILDLINK_ABI_DEPENDS.pgocaml+=	pgocaml>=2.3nb7
BUILDLINK_PKGSRCDIR.pgocaml?=	../../databases/pgocaml

.include "../../devel/ocaml-re/buildlink3.mk"
.include "../../lang/camlp4/buildlink3.mk"
.include "../../textproc/ocaml-csv/buildlink3.mk"
.include "../../time/ocaml-calendar/buildlink3.mk"
.endif	# PGOCAML_BUILDLINK3_MK

BUILDLINK_TREE+=	-pgocaml
