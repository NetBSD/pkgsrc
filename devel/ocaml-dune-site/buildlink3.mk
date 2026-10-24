# $NetBSD: buildlink3.mk,v 1.1 2026/10/24 14:59:38 alnsn Exp $

BUILDLINK_TREE+=	ocaml-dune-site

.if !defined(OCAML_DUNE_SITE_BUILDLINK3_MK)
OCAML_DUNE_SITE_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.ocaml-dune-site?=	build

BUILDLINK_API_DEPENDS.ocaml-dune-site+=	ocaml-dune-site>=3.23.0
BUILDLINK_ABI_DEPENDS.ocaml-dune-site+=	ocaml-dune-site>=3.23.0
BUILDLINK_PKGSRCDIR.ocaml-dune-site?=	../../devel/ocaml-dune-site

.include "../../devel/ocaml-dune/buildlink3.mk"
.endif	# OCAML_DUNE_SITE_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-dune-site
