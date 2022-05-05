# $NetBSD: buildlink3.mk,v 1.3 2022/05/05 07:23:10 jaapb Exp $

BUILDLINK_TREE+=	ocaml-spawn

.if !defined(OCAML_SPAWN_BUILDLINK3_MK)
OCAML_SPAWN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-spawn+=	ocaml-spawn>=0.12.0
BUILDLINK_ABI_DEPENDS.ocaml-spawn+=	ocaml-spawn>=0.15.0
BUILDLINK_PKGSRCDIR.ocaml-spawn?=	../../devel/ocaml-spawn

.endif	# OCAML_SPAWN_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-spawn
