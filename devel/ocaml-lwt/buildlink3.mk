# $NetBSD: buildlink3.mk,v 1.8 2018/01/22 11:53:24 jaapb Exp $

BUILDLINK_TREE+=	ocaml-lwt

.if !defined(OCAML_LWT_BUILDLINK3_MK)
OCAML_LWT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-lwt+=	ocaml-lwt>=3.0.0
BUILDLINK_ABI_DEPENDS.ocaml-lwt+=	ocaml-lwt>=3.2.0
BUILDLINK_PKGSRCDIR.ocaml-lwt?=		../../devel/ocaml-lwt

#.include "../../devel/libev/buildlink3.mk"
.endif	# OCAMLLWT_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-lwt
