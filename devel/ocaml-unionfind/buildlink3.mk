# $NetBSD: buildlink3.mk,v 1.1 2026/10/24 19:03:12 alnsn Exp $

BUILDLINK_TREE+=	ocaml-unionfind

.if !defined(OCAML_UNIONFIND_BUILDLINK3_MK)
OCAML_UNIONFIND_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-unionfind+=	ocaml-unionfind>=20220122
BUILDLINK_ABI_DEPENDS.ocaml-unionfind+=	ocaml-unionfind>=20220122
BUILDLINK_PKGSRCDIR.ocaml-unionfind?=	../../devel/ocaml-unionfind
.endif	# OCAML_UNIONFIND_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-unionfind
