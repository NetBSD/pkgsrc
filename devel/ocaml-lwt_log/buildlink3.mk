# $NetBSD: buildlink3.mk,v 1.2 2018/07/19 15:15:23 jaapb Exp $

BUILDLINK_TREE+=	ocaml-lwt_log

.if !defined(OCAML_LWT_LOG_BUILDLINK3_MK)
OCAML_LWT_LOG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-lwt_log+=	ocaml-lwt_log>=1.1.0
BUILDLINK_ABI_DEPENDS.ocaml-lwt_log?=	ocaml-lwt_log>=1.1.0nb1
BUILDLINK_PKGSRCDIR.ocaml-lwt_log?=	../../devel/ocaml-lwt_log

.include "../../devel/ocaml-lwt/buildlink3.mk"
.endif	# OCAML_LWT_LOG_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-lwt_log
