# $NetBSD: buildlink3.mk,v 1.3 2016/02/17 17:00:38 jaapb Exp $

BUILDLINK_TREE+=	ocaml-lwt

.if !defined(OCAML_LWT_BUILDLINK3_MK)
OCAML_LWT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-lwt+=	ocaml-lwt>=2.4.2
BUILDLINK_PKGSRCDIR.ocaml-lwt?=	../../devel/ocaml-lwt

.include "../../devel/libev/buildlink3.mk"
.endif	# OCAMLLWT_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-lwt
