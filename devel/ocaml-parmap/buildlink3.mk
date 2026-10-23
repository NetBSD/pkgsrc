# $NetBSD: buildlink3.mk,v 1.1 2026/10/23 23:17:50 alnsn Exp $

BUILDLINK_TREE+=	ocaml-parmap

.if !defined(OCAML_PARMAP_BUILDLINK3_MK)
OCAML_PARMAP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-parmap+=	ocaml-parmap>=1.2.5
BUILDLINK_ABI_DEPENDS.ocaml-parmap+=	ocaml-parmap>=1.2.5
BUILDLINK_PKGSRCDIR.ocaml-parmap?=	../../devel/ocaml-parmap
.endif	# OCAML_PARMAP_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-parmap
