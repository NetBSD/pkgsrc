# $NetBSD: buildlink3.mk,v 1.13 2019/03/05 16:56:16 jaapb Exp $

BUILDLINK_TREE+=	ocaml-lwt

.if !defined(OCAML_LWT_BUILDLINK3_MK)
OCAML_LWT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-lwt+=	ocaml-lwt>=4.0.0
BUILDLINK_ABI_DEPENDS.ocaml-lwt+=	ocaml-lwt>=4.1.0nb3
BUILDLINK_PKGSRCDIR.ocaml-lwt?=		../../devel/ocaml-lwt

#.include "../../devel/libev/buildlink3.mk"
.endif	# OCAML_LWT_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-lwt
