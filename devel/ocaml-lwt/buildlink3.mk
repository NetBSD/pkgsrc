# $NetBSD: buildlink3.mk,v 1.5 2017/09/08 12:45:33 jaapb Exp $

BUILDLINK_TREE+=	ocaml-lwt

.if !defined(OCAML_LWT_BUILDLINK3_MK)
OCAML_LWT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-lwt+=	ocaml-lwt>=3.0.0
BUILDLINK_ABI_DEPENDS.ocaml-lwt+=	ocaml-lwt>=3.1.0
BUILDLINK_PKGSRCDIR.ocaml-lwt?=	../../devel/ocaml-lwt

#.include "../../devel/libev/buildlink3.mk"
.endif	# OCAMLLWT_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-lwt
