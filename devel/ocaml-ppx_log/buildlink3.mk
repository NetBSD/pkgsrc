# $NetBSD: buildlink3.mk,v 1.1 2022/05/05 06:10:54 jaapb Exp $

BUILDLINK_TREE+=	ocaml-ppx_log

.if !defined(OCAML_PPX_LOG_BUILDLINK3_MK)
OCAML_PPX_LOG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-ppx_log+=	ocaml-ppx_log>=0.15.0
BUILDLINK_PKGSRCDIR.ocaml-ppx_log?=	../../devel/ocaml-ppx_log

.endif	# OCAML_PPX_LOG_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-ppx_log
