# $NetBSD: buildlink3.mk,v 1.17 2022/05/02 14:02:09 jaapb Exp $

BUILDLINK_TREE+=	ocaml-lwt

.if !defined(OCAML_LWT_BUILDLINK3_MK)
OCAML_LWT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-lwt+=	ocaml-lwt>=5.0.0
BUILDLINK_ABI_DEPENDS.ocaml-lwt+=	ocaml-lwt>=5.5.0
BUILDLINK_PKGSRCDIR.ocaml-lwt?=		../../devel/ocaml-lwt

#.include "../../devel/libev/buildlink3.mk"
.endif	# OCAML_LWT_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-lwt
