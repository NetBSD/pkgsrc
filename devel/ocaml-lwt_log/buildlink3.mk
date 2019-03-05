# $NetBSD: buildlink3.mk,v 1.4 2019/03/05 17:16:32 jaapb Exp $

BUILDLINK_TREE+=	ocaml-lwt_log

.if !defined(OCAML_LWT_LOG_BUILDLINK3_MK)
OCAML_LWT_LOG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-lwt_log+=	ocaml-lwt_log>=1.1.0
BUILDLINK_ABI_DEPENDS.ocaml-lwt_log?=	ocaml-lwt_log>=1.1.0nb4
BUILDLINK_PKGSRCDIR.ocaml-lwt_log?=	../../devel/ocaml-lwt_log

.include "../../devel/ocaml-lwt/buildlink3.mk"
.endif	# OCAML_LWT_LOG_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-lwt_log
