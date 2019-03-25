# $NetBSD: buildlink3.mk,v 1.1 2019/03/25 09:07:07 jaapb Exp $

BUILDLINK_TREE+=	ocaml-spawn

.if !defined(OCAML_SPAWN_BUILDLINK3_MK)
OCAML_SPAWN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-spawn+=	ocaml-spawn>=0.12.0
BUILDLINK_PKGSRCDIR.ocaml-spawn?=	../../devel/ocaml-spawn

.endif	# OCAML_SPAWN_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-spawn
