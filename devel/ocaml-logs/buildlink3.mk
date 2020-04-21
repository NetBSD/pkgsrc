# $NetBSD: buildlink3.mk,v 1.2 2020/04/21 10:43:38 jaapb Exp $

BUILDLINK_TREE+=	ocaml-logs

.if !defined(OCAML_LOGS_BUILDLINK3_MK)
OCAML_LOGS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-logs+=	ocaml-logs>=0.6.2
BUILDLINK_ABI_DEPENDS.ocaml-logs+=	ocaml-logs>=0.7.0
BUILDLINK_PKGSRCDIR.ocaml-logs?=	../../devel/ocaml-logs

.endif	# OCAML_LOGS_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-logs
