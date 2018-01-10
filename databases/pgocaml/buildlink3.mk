# $NetBSD: buildlink3.mk,v 1.3 2018/01/10 16:53:08 jaapb Exp $

BUILDLINK_TREE+=	pgocaml

.if !defined(PGOCAML_BUILDLINK3_MK)
PGOCAML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pgocaml+=	pgocaml>=2.3
BUILDLINK_ABI_DEPENDS.pgocaml+=	pgocaml>=2.3nb5
BUILDLINK_PKGSRCDIR.pgocaml?=	../../databases/pgocaml

.include "../../devel/ocaml-batteries/buildlink3.mk"
.include "../../devel/ocaml-re/buildlink3.mk"
.include "../../lang/camlp4/buildlink3.mk"
.include "../../textproc/ocaml-csv/buildlink3.mk"
.include "../../time/ocaml-calendar/buildlink3.mk"
.endif	# PGOCAML_BUILDLINK3_MK

BUILDLINK_TREE+=	-pgocaml
